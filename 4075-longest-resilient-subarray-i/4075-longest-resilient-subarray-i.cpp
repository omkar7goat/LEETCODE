#include <vector>
#include <algorithm>

class Solution {
public:
    int resilientSubarray(std::vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return 0;

        int max_len = 1;

        for (int l = 0; l < n; l++) {
            long long total_sum = 0;
            int target_rem = ((nums[l] % k) + k) % k;

            for (int r = l; r < n; r++) {
                int cur_rem = ((nums[r] % k) + k) % k;

                // If any element has a different remainder, no extension starting at l is valid
                if (cur_rem != target_rem) {
                    break;
                }

                total_sum += nums[r];

                // Length 1 is always resilient by definition
                if (r == l) {
                    max_len = std::max(max_len, 1);
                    continue;
                }

                // Since all elements have remainder target_rem, testing one tests all
                if ((total_sum - target_rem) % k == 0) {
                    max_len = std::max(max_len, r - l + 1);
                }
            }
        }

        return max_len;
    }
};