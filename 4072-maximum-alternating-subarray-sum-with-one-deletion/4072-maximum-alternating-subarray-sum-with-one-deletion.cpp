class Solution {
public:
    long long maxAlternatingSum(vector<int>& v) {
        int n = v.size();
        // dp[i][k][sign]
        // k: 0 (no deletion yet), 1 (already deleted 1 element)
        // sign: 0 (+), 1 (-)
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(2, vector<long long>(2, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 2; k++) {
                for (int sign = 0; sign < 2; sign++) {
                    // Option 1: Stop subarray here
                    long long a = 0;

                    // Option 2: Pick v[i]
                    long long gf = v[i];
                    if (sign == 1) gf = -gf;
                    long long b = gf + dp[i + 1][k][1 - sign];

                    // Option 3: Delete v[i]
                    long long c = -1e18;
                    if (k == 0) {
                        c = dp[i + 1][1][sign];
                    }

                    dp[i][k][sign] = max({a, b, c});
                }
            }
        }

        long long ans = -1e18;
        for (int i = 0; i < n; i++) {
            // Start subarray at index i: +v[i] and next sign is 1 (-)
            ans = max(ans, (long long)v[i] + dp[i + 1][0][1]);
        }

        return ans;
    }
};