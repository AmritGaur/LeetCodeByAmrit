class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int x=1;
        int sc=0;
        int ec=n-1;
        int sr=0;
        int er=n-1;
        vector<vector<int>>res(n,vector<int>(n,0));
        while(x<=n*n){
        for(int i=sc;i<=ec;i++){
            res[sr][i]=x;
            x++;
        }
            sr++;
        for(int i=sr;x<=n*n && i<=er;i++){
             res[i][ec]=x;
            x++;
        }
            ec--;
        for(int i=ec;x<=n*n && i>=sc;i--){
            res[er][i]=x;
            x++;
        }
            er--;    
        for(int i=er; x<=n*n && i>=sr;i--){
            res[i][sc]=x;
            x++;
        }
            sc++;    
            
            }
        return res;
    }
};