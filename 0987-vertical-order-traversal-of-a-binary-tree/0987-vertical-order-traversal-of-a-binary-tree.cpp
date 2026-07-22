class Solution {
public:
    typedef pair<TreeNode*,int>p;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>v;map<int,vector<int>>mp;
        queue<p>q;q.push({root,0});
        while(!q.empty() && q.front().first!=NULL){
           int n=q.size();map<int,vector<int>>currtrav;
           for(int i=0;i<n;i++){
            TreeNode* curr=q.front().first;int col=q.front().second;
            currtrav[col].push_back(curr->val);q.pop();
            if(curr->left)q.push({curr->left,col-1});
            if(curr->right)q.push({curr->right,col+1});
           }
           for(auto x: currtrav){
            vector<int>currnode=x.second;
            if(currnode.size()>1)sort(currnode.begin(),currnode.end());
            for(int i=0;i<currnode.size();i++){
                mp[x.first].push_back(currnode[i]);
            }

           }
        }
        while(mp.size()>0){
            pair<int,vector<int>> curr= *mp.begin();
            v.push_back(curr.second);
            mp.erase(curr.first);
        }
return v;
    }
};