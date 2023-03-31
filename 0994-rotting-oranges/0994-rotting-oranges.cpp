class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
                else if(grid[i][j]==0){
                    vis[i][j]=true;
                }
                else{
                vis[i][j]=false;
            }}
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        int minTime=0;
        while(q.empty()==false){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tim=q.front().second;
            q.pop();
            minTime=max(minTime,tim);
            for(int i=0;i<4;i++){
                int nrow= row+dr[i];
                int ncol= col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                vis[nrow][ncol]=true;
                q.push({{nrow,ncol},tim+1});
            }  
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    return -1;
                }
            }
        }
        return minTime;
    }
};