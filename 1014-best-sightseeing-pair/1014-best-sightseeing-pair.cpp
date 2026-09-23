class Solution {
public:
   vector<vector<int>>dp;
    int f(int i,int k, int n,vector<int>&v){
        if((k>=2))return 0;
        if(i>=n)return -1e9;
        if(dp[i][k]!=-1)return dp[i][k];
        int b;
        if(k==0) b=v[i]+i + f(i+1,k+1,n,v);
        if(k==1) b=v[i]-i + f(i+1,k+1,n,v);
        int a=f(i+1,k,n,v);
        return dp[i][k]= max(a,b);

    }
    
    int maxScoreSightseeingPair(vector<int>& v) {
        int n=v.size(),ans=-1e9;
        dp.resize(n+1,vector<int>(2,-1));
       ans= f(0,0,n,v);
        return  ans;
        
    }
};