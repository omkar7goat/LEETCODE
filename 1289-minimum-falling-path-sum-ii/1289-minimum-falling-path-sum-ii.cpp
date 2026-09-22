class Solution {
public:
   vector<vector<int>>dp;
    int f(int i,int j,int n,int m,vector<vector<int>>& v){
        if(i>=n)return 0;
        if((j<0)||(j>=m))return 1e9;
        if(dp[i][j]!=-1000)return dp[i][j];
        int a=1e9;
        for(int k=0;k<m;k++){
          if(k!=j)a=min(a,v[i][j]+f(i+1,k,n,m,v));
        }
        return dp[i][j]= a;
    }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();int ans=1e9;
        if(n==1){
            int a=1e9;
            for(int k=0;k<m;k++){
                a=min(a,v[0][k]);
            }
            return a;
        }
        dp.resize(n+1,vector<int>(m+1,-1000));
        for(int j=0;j<m;j++){
          ans=min(ans,f(0,j,n,m,v));
        }
        return ans;
        
    }
};