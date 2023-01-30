class Solution {
public:
    /*bool dfsCycle(vector<int>adj[], int s,  vector<bool>&vis, vector<bool>&vis2){
        vis[s]=true;
        vis2[s]=true;
        for(int u:adj[s]){
            if(!vis[u]){
            if(dfsCycle(adj,u,vis,vis2)==true){
                return true;
            }
                else if(vis2[u]){
                    return true;
                }
        }}
        vis2[s]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       
        int n= numCourses;
        int m=prerequisites.size();
      
        vector<int>adj[n];
        vector<bool>vis(n,false);
        vector<bool>vis2(n,false);
        for(int i=0;i<m;i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        int s=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
        if( dfsCycle(adj,i,vis,vis2)){
            return false;
        }
            }}
        return true;
    }*/
    bool dfs(int i, vector<int>& v, vector<int>& v1, vector<int>adj[]){
        v[i]=1;
        v1[i]=1;
        for(auto it: adj[i]){
            if(!v[it]){
                if(dfs(it, v, v1, adj)){return true;}
            }
            else if(v1[it]){return true;}
        }
        v1[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>v(n, 0), v1(n, 0);
        for(int i=0; i<n; i++){
            if(!v[i]){
                if(dfs(i, v, v1, adj)){return false;}
            }
        }
        return true;
    }
};