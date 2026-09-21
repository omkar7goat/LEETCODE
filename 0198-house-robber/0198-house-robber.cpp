class Solution {
public:
    vector<int>dp;
    int f(vector<int>&v,int i,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int b=v[i]+f(v,i+2,n);
        int a=f(v,i+1,n);
        dp[i]=max(b,a);
        return dp[i];

    }
    int rob(vector<int>& v) {
        int n=v.size();
        dp.resize(n+1,-1);
        return f(v,0,n);
    }
};