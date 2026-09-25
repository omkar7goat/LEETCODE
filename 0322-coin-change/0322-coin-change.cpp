class Solution {
public:
   vector<vector<int>>dp;
   int f(int i,long long curr,int k,int n,vector<int>&v){
    if(curr==k)return 0;
    if(i>=n)return 1e9;
    if(dp[i][curr]!=-1)return dp[i][curr];    
    int b=1e9,c=1e9;
    b=f(i+1,curr,k,n,v);
    if(curr+v[i]<=k){
    c=1+f(i,curr+v[i],k,n,v);
    }
    return dp[i][curr]=min(b,c);
    
   }
    int coinChange(vector<int>& v, int k) {
        int n=v.size();
        //int sumarr=0;for(auto x: v)sumarr+=x;
        dp.resize(n+1,vector<int>(k+1,-1));
        if(k==0)return 0;
        if(n==1){
            if (k%v[0]==0)return k/v[0];
            else return -1;
        }
        int c= f(0,0,k,n,v);
        if(c>=1e9)return -1;
         return c;
    }
};