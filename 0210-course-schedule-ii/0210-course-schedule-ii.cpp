/*class Solution {
public:
    bool dfs(vector<bool>&v1,vector<bool>&v2,vector<int> adj[],int s,stack<int>&st){
        v1[s]=true;
        v2[s]=true;
        for(int u:adj[s]){
            if(!v1[u]){
                if(dfs(v1,v2,adj,u,st)){
                    return true;
                }
                else if(v2[u]){
                    return true;
                }
            }
        }
        st.push(s);
        v2[s]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n= numCourses;    
        vector<int> adj[n];
        vector<int>ans(0);
        for(int i=0;i<prerequisites.size();i++){
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int>st;
        vector<bool>v1(n,false);
        vector<bool>v2(n,false);
        for(int i=0;i<n;i++){
            if(!v1[i]){
            if(dfs(v1,v2,adj,i,st)){
                
                return ans ;
            }}
        }
        while(st.empty()==false){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};*/
/*class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indeg(n,0);
        vector<int> adj[n];
        queue<int> q;
        vector<int> topo;
        for(auto it:prerequisites) adj[it[1]].push_back(it[0]);
        for(int i=0;i<n;i++){
            for(auto it:adj[i]) indeg[it]++;
        }
        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                 q.push(i);

        while(!q.empty()){
            int node = q.front();q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        if(topo.size()==n) return topo;
       return vector<int>();
    }
};*/

class Solution
{
  public:
    vector<int> findOrder(int n,vector<vector<int>> &prerequisites) 
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
