class Solution {
public:
   vector<vector<int>>dp;
   int f(int i,int curr,int n,int k ,vector<int>&v){
    if(i>=n){
        if(curr==k)return 1;
        return 0;
    }
    if(dp[i][curr]!=-1)return dp[i][curr];
    int a=0,b=0;
    a=f(i+1,curr,n,k,v);
    if(curr+v[i]<=k){
        
         b=f(i,curr+v[i],n,k,v);
        
    }
    return dp[i][curr]= a+b;
   }
    int change(int k, vector<int>& v) {
        int n=v.size();int s=0;for(auto x: v)s+=x;
        dp.resize(n+1,vector<int>(k+1,-1));
        return f(0,0,n,k,v);
    }
};