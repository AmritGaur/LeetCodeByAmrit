class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int alt=0;
        int n= gain.size();
        for(int i=0;i<n;i++){
            alt+=gain[i];
            ans=max(ans,alt);
        }
        return ans;
    }
};