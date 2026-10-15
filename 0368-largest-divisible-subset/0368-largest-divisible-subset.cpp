class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(v.begin(),v.end());
        int n=v.size();vector<int>parent(n);
        for(int i=0;i<n;i++)parent[i]=i;
        vector<int>dp(n,1);
        int max_len=0,best_idx=-1;
        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
            if(v[i]%v[j]==0){
               if(dp[j]+1 > dp[i]){
                dp[i]=dp[j]+1;
                parent[i]=j;
               }
            }
           
          }
           if(dp[i]>max_len){
                max_len=dp[i];best_idx=i;
            }
        }
        vector<int>ans;
        while(true){
            ans.push_back(v[best_idx]);
            if(best_idx==parent[best_idx])break;
            best_idx=parent[best_idx];
        }
        return ans;
    }
};