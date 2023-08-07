class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n=numRows;
        vector<vector<int>>nums(n);
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i+1;j++){
                if(j==0 || j==i){
                nums[i].push_back(1);
            }
                else{
            int x= nums[i-1][j-1]+nums[i-1][j];
            nums[i].push_back(x);}
        }}
        return nums;
    }
};