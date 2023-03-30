class Solution {
public:
    void dfs(vector<int> adj[],int n,vector<bool>&vis,int s){
        vis[s]=true;
        for(auto u: adj[s]){
            if(vis[u]==false){
            dfs(adj,n,vis,u);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // LET'S CHECK IF EACH NODE IS VISITED,IF UNVISITED DO THE DFS TRAVERSAL AND INCREASE COUNT BY 1.
        int n= isConnected.size();
        vector<int> adj[n];
        
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            if(isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }}
        int ct=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,n,vis,i);
                ct++;
            }
        }
        return ct;
    }
};