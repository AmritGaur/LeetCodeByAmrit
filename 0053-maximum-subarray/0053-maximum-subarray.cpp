class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0];
        int ans=sum;
        for(int i=1;i<n;i++){
            if(sum+nums[i]>nums[i]){
                sum+=nums[i];
            }
            else{
                sum=nums[i];
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};