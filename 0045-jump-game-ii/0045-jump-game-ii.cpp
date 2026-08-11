class Solution {
public:
   vector<int>dp;
    int f(vector<int> & v,int i,int n){
        if(i==n-1){
            return 0;
        }
        if(i>=n)return 1e9;
        if(dp[i]!=-1)return dp[i];
        int a=v[i];int ans=1e9;
        for(int j=0;j<a;j++){
           ans=min(ans,1+ f(v,i+j+1,n));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& v) {
        int n=v.size();
        dp.resize(n+1,-1);
        return f(v,0,n);
    }
};