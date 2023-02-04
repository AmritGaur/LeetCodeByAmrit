class Solution {
public:
    bool dfs(int i, vector<int>& v, vector<int>& v1,vector<vector<int>>& graph){
        v[i]=1;
        v1[0]=1;
        for(auto it: graph[i]){
            
            if(!v[it]){
                v1[it]=1-v1[i];
                if(dfs(it, v, v1,graph)){
                    return true;
                }
            }
            else if(v1[it]==v1[i]){return true;}
        }
        //v1[i]=-1;
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>v(n, 0), v1(n, -1);
        for(int i=0; i<n; i++){
            if(!v[i]){
                if(dfs(i, v, v1, graph)){return false;}
            }
        }
        return true;
    }
};