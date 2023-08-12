class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x=nums[0];
        int ct=0;
        for(int i=0;i<nums.size();i++){
            if(ct==0){
                x=nums[i];
            }
            if(x==nums[i]){
                ct++;   
            }
            else{
                ct--;
            }
        }
        return x;
    }
};