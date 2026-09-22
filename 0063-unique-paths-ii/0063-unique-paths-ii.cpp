class Solution {
public:
  vector<vector<int>>dp;
   int f(vector<vector<int>>& arr, int i,int j ){
    if(i<0 || j < 0)return 0;
    if(i==0 && j==0)return 1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(arr[i][j]==-1){
       dp[i][j]=0;
    }
    else{
       dp[i][j]=f(arr,i-1,j) + f(arr,i,j-1);
    }
    return dp[i][j];
   }
    
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        dp.resize(n,vector<int>(m,1));
        for ( int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(((i==0)||(j==0))&&(arr[i][j]==1)){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0)&&(j>0)){
                    if(dp[i][j-1]==0)dp[i][j]=0;
                }
                else if((j==0)&&(i>0)){
                    if(dp[i-1][j]==0)dp[i][j]=0;
                }
            }
        }
        if((n==1)||(m==1) || dp[0][0]==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(dp[i][j]==0)return 0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]==1){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
return dp[n-1][m-1];
        
    }
};