class Solution {
public:
    vector<int> mostCompetitive(vector<int>& v, int k) {
        int n = v.size();
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = v[i];
            // Only pop if remaining elements plus stack size can still reach k
            while (st.size() > 0 && curr < st.top() && (st.size() - 1 + (n - i) >= k)) {
                st.pop();
            }
            st.push(curr);
        }

        int gr = min((int)st.size(), k);
        vector<int> g;
        while (st.size() > 0) {
            g.push_back(st.top());
            st.pop();
        }
        reverse(g.begin(), g.end());

        for (int i = 0; i < gr; i++) {
            ans.push_back(g[i]);
        }

        return ans;
    }
};