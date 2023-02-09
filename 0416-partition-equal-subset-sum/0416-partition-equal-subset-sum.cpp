class Solution {
public:
   bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i : nums) sum += i;

        if(sum % 2) return false;
        sum /= 2;

        vector<bool> dp(sum + 1), temp(sum + 1); 

        dp[0] = true;
        if(nums[0] <= sum) dp[nums[0]] = true;

        for(int i=1; i<n; i++) {
            for(int t=1; t<=sum; t++) {
                bool notTake = dp[t];
                bool take = t >= nums[i] ? dp[t - nums[i]] : false;
                temp[t] = take || notTake;
            }
            dp = temp;
        }
        return dp[sum];
    }
};