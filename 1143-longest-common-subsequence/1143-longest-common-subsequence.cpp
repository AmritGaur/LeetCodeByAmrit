class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.length()+1;
        int n=text2.length()+1;
        int lcs[m][n];
        for(int i=0;i<n;i++){
            lcs[0][i]=0;
        }
        for(int i=0;i<m;i++){
            lcs[i][0]=0;
        }
        
        for(int i=1;i<=text1.length();i++){
            for(int j=1;j<=text2.length();j++){
                if(text1[i-1]==text2[j-1]){
                    lcs[i][j]= 1 + lcs[i-1][j-1];
                }
                else{
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
            }
        }
        return lcs[m-1][n-1];
    }
};