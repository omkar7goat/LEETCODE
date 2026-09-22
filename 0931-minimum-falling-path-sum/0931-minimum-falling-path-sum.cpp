class Solution {
public:
   vector<vector<int>> dp;
   int f(int i,int j,int n,int m,vector<vector<int>>& v){
     if((j>=m) ||(j<0))return 1e7;
    if(i>=n)return 0;   
    if(dp[i][j]!=-1e5)return dp[i][j];
    int a=v[i][j]+f(i+1,j,n,m,v);
    int b=v[i][j]+f(i+1,j-1,n,m,v);
    int c=v[i][j]+f(i+1,j+1,n,m,v);
    return  dp[i][j]= min(a,min(b,c));

   }
    int minFallingPathSum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();int ans=1e9;  
        dp.assign(n, vector<int>(m, -1e5));     
            for(int j=0;j<m;j++){     
                 ans=min(ans,f(0,j,n,m,v));
            }
       
        return ans;
    }
};