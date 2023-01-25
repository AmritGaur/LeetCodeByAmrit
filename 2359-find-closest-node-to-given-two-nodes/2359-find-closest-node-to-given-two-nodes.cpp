/*class Solution {
public:
    void dfs1(vector<int>& edges,map<int,int>&mp,int s){
        int ct=0;
        mp[s]=ct;
        ct++;
        if(edges[s]==-1){
            return;
        }
        dfs1(edges,mp,edges[s]);
        return;
    }
    void dfs2(vector<int>& edges,map<int,int>&mp,int &ans,int s){
        int cy=0;
        int ck=0;
        if(mp.find(s)!=mp.end()){
            if(mp[s]<cy){
                mp[s]=cy;
            }
            ck=min(mp[s],ck);
        }
        cy++;
        if(edges[s]==-1){
            return;
        }
        dfs2(edges,mp,ans,edges[s]);
        return;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        map<int,int>mp;
        int ans=INT_MAX;
        dfs1(edges,mp,node1);
        dfs2(edges,mp,ans,node2);
        /*if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }*/
        class Solution {
public:
    void dfs(int node, vector<int>& edges, vector<int>& distance, vector<bool>& visited){
        visited[node] = true;
        int neighbor = edges[node];
        if (neighbor != -1 && visited[neighbor] == false) {
            distance[neighbor] = distance[node] + 1;
            dfs(neighbor, edges, distance, visited);
        }
    }
    //we are using DFS to solve this problem
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        int ans = -1;
        int minDist = INT_MAX;
        //dist1 store the distance from node1 to all the neighbour nodes and dist2 store the distance from node2 to all the neighbour nodes
        vector<int> dist1(n, 0), dist2(n, 0);
        //visited array helps us to identify wheather we visited to particular node form node1 or not similarly for visited2
        vector<bool> visited1(n, false), visited2(n, false);
        //calling dfs from both the nodes i.e. node1 and node2
        dfs(node1, edges, dist1, visited1);
        dfs(node2, edges, dist2, visited2);

        for(int currNode = 0; currNode < n; currNode++){
            if(visited1[currNode] == true && visited2[currNode] == true && minDist > max(dist1[currNode], dist2[currNode])){
                minDist = max(dist1[currNode], dist2[currNode]);
                ans = currNode;
            }
        }
        return ans;
    }


};