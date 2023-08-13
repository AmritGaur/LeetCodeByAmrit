class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,vector<int>>mp;
        int n= nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        int start=0;
        int end=n-1;
        while(start<end){
            if(nums[start]+nums[end]==target){
                v.push_back(mp[nums[start]].front());
                v.push_back(mp[nums[end]].back());
                break;
            }
            else if(nums[start]+nums[end]<target){
                start++;
            }
            else{
                end--;
            }
        }
        return v;
    }
};