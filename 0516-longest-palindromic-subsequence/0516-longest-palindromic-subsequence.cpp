class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string text1=s,text2=s;reverse(text2.begin(),text2.end());
         int n=text1.size(),m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1]){
                  dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
};