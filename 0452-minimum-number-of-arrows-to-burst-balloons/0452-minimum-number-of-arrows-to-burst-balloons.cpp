class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return(a[1]<b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),cmp);
        int c=1;
        int end= points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]>end){
                end=points[i][1];
                c++;
            }
            else{
            continue;
            }
        }
        return c;
    }
};