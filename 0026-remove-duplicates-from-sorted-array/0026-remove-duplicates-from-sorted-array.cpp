class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        for(int i=1;i<nums.size();i++){
           if(nums[i]==nums[i-1]){
               nums[i-1]=101;
               c++;
           }
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<c;i++){
            nums.pop_back();
        }
        return n-c;
    }
};