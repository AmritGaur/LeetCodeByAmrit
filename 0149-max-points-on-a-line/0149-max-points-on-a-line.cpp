class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n= points.size();
        if(n==1){
            return 1;
        }
        int maxi=2;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int ct=0;
                for(int k=j+1;k<n;k++){
                    double slope;
    if((points[j][1]-points[i][1])*(points[k][0]-points[i][0])==(points[k][1]-points[i][1])*(points[j][0]-points[i][0])){
                    
                        ct++;
                    }
                }
                maxi=max(maxi,2+ct);
                ct=0;
            }
        }
        return maxi;
    }
};