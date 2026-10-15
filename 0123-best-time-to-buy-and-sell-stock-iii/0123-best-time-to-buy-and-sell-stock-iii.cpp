class Solution {
public:
   int dp[100005][2][3];
    int f(int i ,int buyflag, int k ,int n,vector<int>& v){
        if(k>2)return -1e9;
        if(i>=n){
            if(k<=2){
                if(buyflag==0)return 0;
                else return -1e9;
            }
            
        }
        if(dp[i][buyflag][k] !=-1)return dp[i][buyflag][k];
        int a=-1e9,b=-1e9;
        if(buyflag==1){
           b=v[i]+f(i+1,0,k+1,n,v);
           a=f(i+1,1,k,n,v);
        }
        else{
          b=-v[i]+f(i+1,1,k,n,v);
          a=f(i+1,0,k,n,v);
        }
        return dp[i][buyflag][k] = max(a,b);
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();
        memset(dp, -1, sizeof(dp));
        return f(0,0,0,n,v);
        
    }
};