class Solution {
public:
   map<TreeNode*,TreeNode*>parents;
   vector<int>v;
    void f(TreeNode* root,TreeNode * parent){
    if(root==NULL)return;
       parents[root]=parent;
       if(root->left){        
        f(root->left,root);
       }
       if(root->right){
        f(root->right,root);
       }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       f(root,NULL);
       queue<TreeNode*>q;q.push(target); int l=0;set<int>visited;visited.insert(target->val);
       while(q.size()>0){
        int n=q.size();if(l>k)break;vector<int>temp;
        for(int i=0;i<n;i++){
          TreeNode* curr=q.front();q.pop();temp.push_back(curr->val);
        if(parents[curr] && visited.find(parents[curr]->val)==visited.end()){
            q.push(parents[curr]);visited.insert(parents[curr]->val);
        }
        if(curr->left && visited.find(curr->left->val)==visited.end()){
            q.push(curr->left);visited.insert(curr->left->val);
        }
        if(curr->right && visited.find(curr->right->val)==visited.end()){
            q.push(curr->right);visited.insert(curr->right->val);
        }
        }
        if(l==k){
            for(auto x:temp)v.push_back(x);
        }
        l++;
       }
       return v;
    }
};