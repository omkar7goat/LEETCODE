class Solution {
public: 
   vector<vector<int>>dp;
    int f(int i,int j,vector<vector<int>>& v,int n,int m){
        if((i>=n)||(j>=m)) return 0;
        if(dp[i][j]!=-1e9)return dp[i][j];
        
        int a=v[i][j]+f(i+1,j,v,n,m);
        int b=v[i][j]+f(i+1,j+1,v,n,m);
         dp[i][j]= min(a,b);
         return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& v) {
        int n=v.size(),m=v[n-1].size();
        dp.resize(n+1,vector<int>(m+1,-1e9));
        return f(0,0,v,n,m);
        
    }
};