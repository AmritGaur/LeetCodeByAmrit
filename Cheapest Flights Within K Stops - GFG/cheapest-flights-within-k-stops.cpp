//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        vector<bool>vis(n,false);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        int x=0;
        while(!q.empty()){
            int x=q.front().first;
            int dis=q.front().second.second;
            int prev=q.front().second.first;
            q.pop();
            if(x>K){
                continue;
            }
            for(int i=0;i<adj[prev].size();i++){
                int next=adj[prev][i].first;
                int nextDis=adj[prev][i].second;
                if(dist[next]>dis+nextDis && x<=K){
                    dist[next]=dis+nextDis;
                    q.push({x+1,{next,dist[next]}});
                }
            }
            
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends