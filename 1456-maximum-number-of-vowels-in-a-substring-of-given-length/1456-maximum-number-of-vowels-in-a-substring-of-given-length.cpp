class Solution {
public:
    bool vowel(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
            return true;
        }
        return false;
    }
    int maxi=0;
    int maxVowels(string s, int k) {
        queue<char>q;
        int ct=0;
        for(int i=0;i<k;i++){
            q.push(s[i]);
            if(vowel(s[i])){
                ct++;
            }
            maxi=max(maxi,ct);
        }
        for(int i=k;i<s.length();i++){
            char y=q.front();
            q.pop();
            if(vowel(y)){
                ct--;
            }
            q.push(s[i]);
            if(vowel(s[i])){
             ct++;   
            }
            maxi=max(maxi,ct);
        }
        return maxi;
    }
};