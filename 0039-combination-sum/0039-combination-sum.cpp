class Solution {
public:
    
    void fn(vector<int>&v,vector<vector<int>>&ans,vector<int>& candidates,int target,int sum,int n,int i){
    
        if(sum==0 ){
            ans.push_back(v);
            v.pop_back();
            return;
        }
        if(sum<0 || i==n){
            v.pop_back();
            return;
        }
        v.push_back(candidates[i]);
        fn(v,ans,candidates,target,sum-candidates[i],n,i);
        fn(v,ans,candidates,target,sum,n,i+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum=target;
        vector<int>v;
        vector<vector<int>>ans;
        int n=candidates.size();
        int i=0;
        fn(v,ans,candidates,target,sum,n,0);
        return ans;
    }
};