class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]+=1;
        int n=nums.size();
        int sum=0;
        int res=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem=rem+k; 
            }
            mp[rem]+=1;
            res+=mp[rem]-1;
        }
        return res;
    }
};