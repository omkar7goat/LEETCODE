class Solution {
public:
   void f(int i, int j ,int n ,int m ,int color ,vector<vector<int>>& image, vector<vector<int>>& vis,int sourcecolor){
   if((i>=n)||(j>=m)|| (i<0) || (j<0) ||  (vis[i][j]!=-1) || (image[i][j]!=sourcecolor))return;
    image[i][j]=color;vis[i][j]=1;
    f(i+1,j,n,m,color,image,vis,sourcecolor); //down
    f(i-1,j,n,m,color,image,vis,sourcecolor); // up
    f(i,j+1,n,m,color,image,vis,sourcecolor); //right
    f(i,j-1,n,m,color,image,vis,sourcecolor);  //left

   }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,-1));
           int sourcecolor=image[sr][sc];
        f(sr,sc,n,m,color,image,vis, sourcecolor);
        return image;
    }
};