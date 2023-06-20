class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n,-1);
        if(n<(2*k+1)){
            return res;
        }
        if(k==0){
            return nums;
        }
        long long int sum=0;
        for(int i=0;i<(2*k+1);i++){
            sum+=nums[i];
        }
        for(int i=k;i<n-k;i++){
            res[i]=sum/(2*k+1);
            if(i==n-k-1){
                break;
            }
            sum-=nums[i-k];
            sum+=nums[i+k+1];
        }
        return res;
    }
};