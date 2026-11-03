class Solution {
public:
   void f(int i ,vector<vector<int>>& v,vector<int>&vis,int n ,int m ){

    vis[i]=0;
    vector<int>neighbours=v[i];
    for(int j=0;j<m;j++){
        if((v[i][j]==1)&&(vis[j]==-1)&&(i!=j)){
            f(j,v,vis,n,m);
        }
    }
   }
    int findCircleNum(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();int ans=0;
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
          if(vis[i]==-1){
            ans++;f(i,v,vis,n,m);
          }
        }
        return ans;
    }
};