class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        int x=image[sr][sc];
        image[sr][sc]=color;
        q.push({sr,sc});
        vis[sr][sc];
       /* for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(image[i][j]==0){
                    vis[i][j]=true;
                }
                else {
                    continue;
                }
            }
        }*/
        int dr[]={0,-1,0,1};
        int dc[]={-1,0,1,0};
        while(q.empty()==false){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && vis[nrow][ncol]==false && image[nrow][ncol]==x){
                    vis[nrow][ncol]=true;
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};