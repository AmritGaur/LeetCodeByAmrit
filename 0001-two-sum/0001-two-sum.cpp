class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int start=0;
        int end=nums.size()-1;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<=end;i++){
            mp[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        while(start<end){
            if(nums[start]+nums[end]==target){
                v.push_back(mp[nums[start]].front());
                v.push_back(mp[nums[end]].back());
                break;
            }
            else if(nums[start]+nums[end]>target){
                end--;
            }
            else{
                start++;
            }
        } 
        return v;
    }
};



































