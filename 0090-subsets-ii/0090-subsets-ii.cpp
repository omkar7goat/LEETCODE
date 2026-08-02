class Solution {
public:
    set<vector<int>>ans;
    void f(vector<int>&nums,int i,int n,vector<int>v){
        if(i>=n){
            ans.insert(v);
            return;
        }

        v.push_back(nums[i]);
        f(nums,i+1,n,v);
        v.pop_back();
        f(nums,i+1,n,v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        f(nums,0,nums.size(),{});
        vector<vector<int>>gj;
        for(auto x:ans)gj.push_back(x);
        return gj;
    }
};