class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int x=0;
        int sc=0;
        int ec=matrix[0].size()-1;
        int sr=0;
        int er=matrix.size()-1;
        vector<int>res;
        int total=(m+1)*(n+1);
        while(x<total){
        for(int i=sc;i<=ec;i++){
            res.push_back(matrix[sr][i]);
            x++;
        }
            sr++;
        for(int i=sr;x<total && i<=er;i++){
            res.push_back(matrix[i][ec]);
            x++;
        }
            ec--;
        for(int i=ec;x<total && i>=sc;i--){
            res.push_back(matrix[er][i]);
            x++;
        }
            er--;    
        for(int i=er; x<total && i>=sr;i--){
            res.push_back(matrix[i][sc]);
            x++;
        }
            sc++;    
            
            }
        return res;
    }
};