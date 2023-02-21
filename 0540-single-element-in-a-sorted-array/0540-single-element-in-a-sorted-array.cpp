class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                i++;
                continue;
            }
            else{
                return nums[i];
            }
        }
        return nums[n-1];
    }
};