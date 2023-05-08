class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum=0;
        int n=mat.size();
        for(int i=0;i<n;i++){
            if(i==n/2 && n%2==0){
                break;
            }
            sum+=mat[i][i];
            if(i==n/2 && n%2!=0){
                break;
            }
            sum+=mat[i][n-1-i];
            sum+=mat[n-1-i][n-1-i];
            sum+=mat[n-1-i][i];
        }
        return sum;
    }
};