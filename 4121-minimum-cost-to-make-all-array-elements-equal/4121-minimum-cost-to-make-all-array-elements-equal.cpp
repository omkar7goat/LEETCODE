class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n = nums.size();

        auto talmerovik = nums;

        long long ans = LLONG_MAX;

        int l = 0;

        for (int r = 0; r < n; r++) {
            if (r == n - 1 || nums[r] != nums[r + 1]) {

                if (r > 0 && l < n - 1) {
                    long long cost = 1LL * (l + n - r - 1) * nums[r];
                    ans = min(ans, cost);
                }

                l = r + 1;
            }
        }

        return ans;
    }
};