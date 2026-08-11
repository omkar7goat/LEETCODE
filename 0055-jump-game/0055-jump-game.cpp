class Solution {
public:
    vector<int>dp;
    bool f(vector<int>&v,int i,int n){
        if(i==n-1)return true;
        if(i>=n)return false;
        if(dp[i]!=-1)return dp[i];
        int a=v[i];
        bool ans=false;
        for(int j=0;j<a;j++){
          ans= ans || f(v,i+j+1,n);
        }
        return dp[i]=ans;
    }
    bool canJump(vector<int>& v) {
        int n=v.size();
        dp.resize(n+1,-1);
        return f(v,0,n);

    }
};