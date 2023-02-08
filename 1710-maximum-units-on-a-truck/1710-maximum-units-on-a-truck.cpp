class Solution {
public:
     static bool cmp(vector<int>&a,vector<int>&b){
        return (a[1]>b[1]);
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        int giv_cap=truckSize;
        int curr_cap=truckSize;
        int ans=0;
        for(int i=0;i<boxTypes.size();i++){
            if(curr_cap>=boxTypes[i][0]){
                curr_cap=curr_cap-boxTypes[i][0];
                ans+=(boxTypes[i][0]*boxTypes[i][1]);
            }
            else{
                ans+=(curr_cap*boxTypes[i][1]);
                curr_cap=0;
                break;
            }
        }
        return ans;
    }
};