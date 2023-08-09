class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n=nums.size();
        int front=n-1;
        int back=n-1;
        int ct=0;
        for(int i=n-1;i>0;i--){
            if(nums[i]<=nums[i-1]){
                front=i-1;
                ct++;
            }
            else{
               break; 
            }
        }
        
        if(ct==n-1){
            sort(nums.begin(),nums.end());
            return;
        }
        front--;       
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[front]){
                back=i;
                break;
            }
        }
        int temp=nums[front];
        nums[front]=nums[back];
        nums[back]=temp;
        partial_sort(nums.begin()+front+1,nums.end(),nums.end());
        return;
    }
};