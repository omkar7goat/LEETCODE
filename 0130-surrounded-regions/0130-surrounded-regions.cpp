class Solution {
public:
    void solve(vector<vector<char>>& v) {
        int n =v.size(),m=v[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0)||(i==n-1)||(j==0)||(j==m-1)){
                    if(v[i][j]=='O'){
                        q.push({i,j});
                        vis[i][j]=1;
                    }
                }
            }
        }
        vector<int>delr={0,0,-1,1};
        vector<int>delc={1,-1,0,0};
        while(!q.empty()){
            int currqsize=q.size();
            while(currqsize--){
                int currrow=q.front().first;
                int currcol=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newrow=currrow+delr[k];
                    int newcol=currcol+delc[k];
                    if((newrow>=0)&&(newrow<=n-1)&&(newcol>=0)&&(newcol<=m-1)&&(vis[newrow][newcol]==-1)){
                        if(v[newrow][newcol]=='O'){
                            q.push({newrow,newcol});
                            vis[newrow][newcol]=1;
                        }
                    }
                }
            }
        }

          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if((v[i][j]=='O')&&(vis[i][j]==-1)){
                v[i][j]='X';
               }
            }
        }
       
    }
};