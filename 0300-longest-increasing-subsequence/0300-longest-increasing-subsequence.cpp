class Solution {
public:
   vector<vector<int>>dp;
   int f(int i ,int prev_idx,int n,vector<int>&v){
    if(i>=n)return 0;
    if(dp[i][prev_idx+1]!=-1)return dp[i][prev_idx+1];
    int a=-1e9,b=-1e9;
    a=f(i+1,prev_idx,n,v);
    if(prev_idx==-1){
        b=1+f(i+1,i,n,v);
    }
    else{
        if(v[i]>v[prev_idx]){
            b=1+f(i+1,i,n,v);
        }
    }
    return dp[i][prev_idx+1]=max(a,b);
   }
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        dp.resize(n+2,vector<int>(n+2,-1));
        return f(0,-1,n,v);
    }
};