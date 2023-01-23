class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int m= trust.size();
        if(n==1){
            return 1;
        }
        unordered_map<int,int>mp;
        for(int i=0;i<m;i++){
            int x=trust[i][0];
            int y=trust[i][1];
            mp[x]=-1;
            if(mp[y]!=-1){
            mp[y]+=1;
            }
        }
        for(auto u:mp){
            if(u.second==n-1){
                return u.first;
            }
        }
        return -1;
    }
};