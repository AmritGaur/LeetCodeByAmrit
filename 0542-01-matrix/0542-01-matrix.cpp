class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>ans(m,vector<int>(n,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    vis[i][j]=true;
                    q.push({{i,j},0});
                }
                else{
                    continue;
                   }
        }
    }
        int dr[]={-1,0,1,0};
        int dc[]={0,-1,0,1};
        while(q.empty()==false){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            //int mini=INT_MAX;
            for(int i=0;i<4;i++){
                int nrow= row+dr[i];
                int ncol= col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==false){
                ans[nrow][ncol]=dis+1;
                vis[nrow][ncol]=true;
                q.push({{nrow,ncol},dis+1});
            }}  
                
        }
          return ans;               
}
};