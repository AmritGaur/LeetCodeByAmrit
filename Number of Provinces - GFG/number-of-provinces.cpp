//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int s, vector<int> ad[], vector<bool>&vis){
        vis[s]=true;
        for(int u:ad[s]){
            if(!vis[u]){
                dfs(u,ad,vis);
            }
        }
        return;
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> ad[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j && adj[i][j]==1){
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        vector<bool>vis(V,false);
        int ct=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,ad,vis);
                    ct++;
                }
            }
        return ct;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends