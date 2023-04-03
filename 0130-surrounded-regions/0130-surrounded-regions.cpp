class Solution {
public:
    void solve(vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='X'){
                    vis[i][j]=true;
                }
                else if(board[i][j]=='O' && (i==m-1 || i==0 || j==n-1 || j==0)){
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
            //int mini=INT_MAX;
            for(int i=0;i<4;i++){
                int nrow= row+dr[i];
                int ncol= col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==false){
                vis[nrow][ncol]=true;
                q.push({nrow,ncol});
            }  
                
        }  
    }
    for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false){
                    board[i][j]='X';
                }
            }
        }
    return;}
};