class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>v;
        int x=0;
        int y=0;
        int ct1=0;
        int ct2=0;
        if(nums.size()==1){
            v.push_back(nums[0]);
            return v;
        }
        for(int i=0;i<nums.size();i++){
            if(ct1==0 && y!=nums[i]){
                x=nums[i];
                ct1++;
            }
            else if(ct2==0 && x!=nums[i]){
                ct2++;  
                y=nums[i];
            }
            else if(nums[i]==x){
                ct1++;
            }
            else if(nums[i]==y){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
        }
        ct1=0;
        ct2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                ct1++;
            }
            else if(nums[i]==y){
                ct2++;
            }
        }
        if(ct1>(nums.size()/3)){
            v.push_back(x);
        }
        if(ct2>(nums.size()/3)){
            v.push_back(y);
        }
        return v;
    }
};