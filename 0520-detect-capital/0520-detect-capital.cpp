class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0;
        int sml=0;
        if((int)word[0]<97){
            for(int i=1;i<word.length();i++){
                if((int)word[i]<97){
                    cap++;
                }
                else{
                    sml++;
                }
            }
            if(cap==0){
                return true;
            }
            else if(sml==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            for(int i=1;i<word.length();i++){
                if((int)word[i]<97){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};