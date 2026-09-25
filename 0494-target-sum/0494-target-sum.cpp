class Solution {
public:
    vector<vector<int>>dp;
    int f(int i, int curr,int n,int target,vector<int>&v,int s){
        if(i>=n){
            if(curr==target)return 1;
            return 0;
        }
        if(dp[i][curr+s]!=-1)return dp[i][curr+s];
        int a=0,b=0,c=0;
        a=f(i+1,curr+v[i],n,target,v,s);        
        b=f(i+1,curr-v[i],n,target,v,s);
    
        return dp[i][curr+s]= a+b+c;

    }
    int findTargetSumWays(vector<int>& v, int target) {
        int n=v.size();int s=0;
        for(auto x: v)s+=x;
        dp.resize(n+1,vector<int>(2*s+1,-1));
        return f(0,0,n,target,v,s);
    }
};