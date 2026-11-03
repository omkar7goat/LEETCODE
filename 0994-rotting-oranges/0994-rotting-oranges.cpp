class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1)count++;
            }
        }
        if(count==0)return 0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<int>deltar={0,0,1,-1};
        vector<int>deltac={1,-1,0,0};int ans=0;
        while(q.size()>0){
            int qsize=q.size();ans++;
            for(int k=0;k<qsize;k++){
                int currrow=q.front().first;
                int currcol=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int newrow=currrow+deltar[i];
                    int newcol=currcol+deltac[i];
                    if((newrow>=0)&&(newrow<=n-1)&&(newcol>=0)&&(newcol<=m-1)
                    &&(v[newrow][newcol]==1)){
                        v[newrow][newcol]=2;
                         q.push({newrow,newcol});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1)return -1;
            }
        }
        return ans-1;
    }
};