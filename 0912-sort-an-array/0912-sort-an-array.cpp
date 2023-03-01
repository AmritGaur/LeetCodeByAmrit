class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(pq.empty()!=true){
            int x=pq.top();
            pq.pop();
            v.push_back(x);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};