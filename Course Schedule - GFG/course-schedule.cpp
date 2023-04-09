//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int>adj[n];
        vector<int>ans;
	    vector<int>indegree(n,0);
	    for(int i=0;i<prerequisites.size();i++){
	        for(int j=0;j<prerequisites[i].size();j++){
	            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(auto j=adj[i].begin();j!=adj[i].end();j++){
	            indegree[*j]+=1;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<n;i++){
	        if(indegree[i]==0){
	           q.push({i}); 
	        }
	    }
	    while(q.empty()==false){
	        int x = q.front();
	        ans.push_back(x);
	        q.pop();
	        for(int u:adj[x]){
	            indegree[u]--;
	            if(indegree[u]==0){
	               q.push(u); 
	           }
	        }
	    }
	    if(ans.size()!=n){
	        return vector<int>();
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends