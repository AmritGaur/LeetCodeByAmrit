class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>adj[n];
        vector<int>indegree(n);
        for(int i=0;i<n;i++){
            for(int it: graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(q.empty()==false){
            int x=q.front();
            q.pop();
            ans.push_back(x);
            for(int u:adj[x]){
                indegree[u]--;
                if(indegree[u]==0){
                    q.push(u);
                }
            }
        }
        sort(ans.begin(),ans.end());
     return ans;   
  }
};