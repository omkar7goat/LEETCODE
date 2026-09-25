class Solution {
public:
   int mod=1e9+7;
   vector<vector<long long >>dp;
   int f(int i, long long curr,int x, int n){
    if(curr==n)return 1;
    if(i>n){
        if(curr==n)return 1;
        return 0;
    }
    if(dp[i][curr]!=-1)return dp[i][curr];
    int a=f(i+1,curr,x,n);
    long long  c=pow(i,x);
    int b=0;
    if(curr+c<=n)b=f(i+1,curr+c,x,n);
    return dp[i][curr]= (a+b)%(mod);
   }
    int numberOfWays(int n, int x) {
        dp.resize(n+2,vector<long long >(n+2,-1));
        return f(1,0,x,n);
        
    }
};