class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=true;
                }
                else if(grid[i][j]==1 && (i==m-1 || i==0 || j==n-1 || j==0)){
                    vis[i][j]=true;
                    q.push({i,j});
                }
                else {
                    continue;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(q.empty()==false){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow= row+dr[i];
                int ncol= col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==false){
                vis[nrow][ncol]=true;
                q.push({nrow,ncol});
            }  
                
        }  
    }
        int ct=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==false){
                    vis[i][j]=true;
                    ct++;
                }
            }
        }
        return ct;
    }
};