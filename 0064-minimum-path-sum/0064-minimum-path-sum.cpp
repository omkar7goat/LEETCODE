class Solution {
public:
   vector<vector<int>> dp;
    int f(int i,int j,vector<vector<int>>& v){
        if(i<0 || j<0)return 1e5;
        if((i==0)&&(j==0))return v[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int a=v[i][j]+f(i-1,j,v);
        int b=v[i][j]+f(i,j-1,v);
         dp[i][j] = min(a,b);
         return dp[i][j];

    }
    int minPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,v);
    }
};