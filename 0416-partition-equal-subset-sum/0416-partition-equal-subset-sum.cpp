class Solution {
public:
   vector<vector<int>>dp;
   bool f(int i,int s,int n,vector<int>&v,int g){
      if(s==g){
        return true;
      }
      if(i>=n)return false;
      if(dp[i][s]!=-1)return dp[i][s];
      bool a=false || f(i+1,s,n,v,g);
      bool b= false || f(i+1,s+v[i],n,v,g);
      return dp[i][s]= a|| b;
   }
    bool canPartition(vector<int>& v) {
        int n=v.size(),sum=0;
        for(auto x : v)sum+=x;
        dp.resize(n+1,vector<int>(sum,-1));
        if(sum%2!=0)return false;
        return f(0,0,n,v,sum/2);

        
    }
};