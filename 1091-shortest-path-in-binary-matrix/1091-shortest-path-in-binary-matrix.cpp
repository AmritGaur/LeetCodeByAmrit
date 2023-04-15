class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>>q;
        int n= grid.size();
        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }
        if(n==1){
            return 1;
        }
        dis[0][0]=0;
        vis[0][0]=true;
        q.push({0,{0,0}});
        int dr[]={0,0,1,1,1,-1,-1,-1};
        int dc[]={-1,1,0,1,-1,0,1,-1}; 
        while(q.empty()==false){
            auto it= q.front();
            q.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0;i<8;i++){
                int row=r+dr[i];
                int col=c+dc[i];
                if(row>=0 && col>=0 && row<n && col<n && grid[row][col]==0 && dis[row][col]>d+1 && !vis[row][col]){
                    dis[row][col]=d+1;
                    if(row==n-1 && col==n-1){
                           return d+2;
                     }
                    q.push({d+1,{row,col}});
                    vis[row][col]=true;
                }
            }
        }
        return -1;
    }
};