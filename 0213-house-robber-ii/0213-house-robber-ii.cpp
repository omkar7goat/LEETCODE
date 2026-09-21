class Solution {
public:
   vector<int>dp;
    int f(int i,int n,vector<int>&v){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int b=v[i]+f(i+2,n,v);
        int a=f(i+1,n,v);
        dp[i]=max(b,a);
        return dp[i];

    }
    int rob(vector<int>& v) {
        int n=v.size();
        if(n<=2){
            if(n==1)return v[0];
            if(n==2)return max(v[0],v[1]);
        }
        dp.resize(n+1,-1);
        
        int a=f(0,n-1,v);
        fill(dp.begin(), dp.end(), -1);
        int b=f(1,n,v);
        return max(a,b);
        
    }
};