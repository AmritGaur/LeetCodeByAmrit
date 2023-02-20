class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=0;
        if(target>nums[e]){
            return e+1; 
        }
        if(target<nums[0]){
            return 0;
        }
        while(s<=e){
             mid= (s+e)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        /*if(mid==nums.size()-1&&nums[mid]<target){
            return nums.size();
        }*/
        if(nums[mid]<target){
            return mid+1;
        }
        return mid;
    }
};