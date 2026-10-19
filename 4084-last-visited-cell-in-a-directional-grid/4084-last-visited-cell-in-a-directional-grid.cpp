class Solution {
public:
 
   vector<int>ans;
   bool f(int i ,int j,int n , int m , vector<vector<char>>& v,vector<vector<int>>& vis){
    if((i>=n)||(j>=m)||(i<0)||(j<0)||vis[i][j]==1){
        return true;
    }
    vis[i][j]=1;int nextrow,nextcol;
    char ch=v[i][j];
    if(ch=='R'){
     nextcol=j+1;nextrow=i;
    }
    else if(ch=='U'){
        nextcol=j;nextrow=i-1;
    }
    else if(ch=='L'){
        nextcol=j-1;nextrow=i;
    }
    else{
        nextrow=i+1;nextcol=j;
    }
    if(f(nextrow,nextcol,n,m,v,vis)){
        ans.push_back(i);ans.push_back(j);return false;
    }
    return false;
      
   }
    vector<int> lastVisitedCell(vector<vector<char>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        bool g=f(0,0,n,m,v,vis);
        return ans;
    }
};