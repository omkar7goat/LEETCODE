class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        // 1. If total sum can't be divided evenly into k parts, impossible.
        if (totalSum % k != 0) return false;

        int target = totalSum / k;
        int n = nums.size();

        // 2. Sort descending so larger elements are considered early
        sort(nums.rbegin(), nums.rend());

        // If any single element exceeds the target, impossible.
        if (nums[0] > target) return false;

        // Total possible subsets of picked numbers: 2^n
        int totalStates = 1 << n;

        // dp[mask] stores how full the current bucket is (0 to target - 1)
        // initialized to -1 (meaning unreachable / invalid state)
        vector<int> dp(totalStates, -1);

        // Base case: 0 elements picked -> current bucket has 0 sum
        dp[0] = 0;

        // Iterate through all bitmasks from 0 to 2^n - 1
        for (int mask = 0; mask < totalStates; ++mask) {
            // Skip invalid/unreachable combinations
            if (dp[mask] == -1) continue;

            // Try picking each unused number
            for (int i = 0; i < n; ++i) {
                // Check if the i-th number is NOT yet picked (i-th bit is 0)
                if (!(mask & (1 << i))) {
                    
                    // Check if this number fits in our current bucket
                    if (dp[mask] + nums[i] <= target) {
                        // Mark the i-th number as picked
                        int nextMask = mask | (1 << i);

                        // If bucket hits target, it resets to 0 for the next bucket.
                        // Otherwise, it holds the running sum.
                        dp[nextMask] = (dp[mask] + nums[i]) % target;
                    } else {
                        // Because nums is sorted descending, any future nums[j] (j > i)
                        // could still be smaller, so we don't break here.
                    }
                }
            }
        }

        // All elements picked = mask (1 << n) - 1.
        // If all buckets closed perfectly, the final remainder is 0.
        return dp[totalStates - 1] == 0;
    }
};