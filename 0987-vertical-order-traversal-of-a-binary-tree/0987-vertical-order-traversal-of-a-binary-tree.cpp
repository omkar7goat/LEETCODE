class Solution {
public:
    map<int, map<int, multiset<int>>> mp;
    void dfs(TreeNode* node, int row, int col) {
        if (node == NULL) return;
        mp[col][row].insert(node->val);     
        dfs(node->left, row + 1, col - 1);
        dfs(node->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>ans;
        for(auto x : mp){
            int col = x.first;vector<int>g;
            map<int,multiset<int>> rowmap=x.second;
            for(auto y : rowmap){
                int row=y.first;
                multiset<int>v=y.second;
                for(auto z : v){
                     g.push_back(z);
                }
            }
            ans.push_back(g);
        }
        return ans;
    }
};