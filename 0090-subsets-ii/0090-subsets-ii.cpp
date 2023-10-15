class Solution {
public:
    
    void fn(set<vector<int>>&s,vector<int>&nums,int i,int n,vector<int>help){
        if(i==n){
            s.insert(help);
            return;
        }
        help.push_back(nums[i]);
        fn(s,nums,i+1,n,help);
        help.pop_back();
        fn(s,nums,i+1,n,help);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>help;
        vector<vector<int>>ans;
        set<vector<int>>s;
        int i=0;
        int n=nums.size();
        bool z=true;
        fn(s,nums,i,n,help);
        for(auto x:s){
            ans.push_back(x);
        }
        return ans;
    }
};