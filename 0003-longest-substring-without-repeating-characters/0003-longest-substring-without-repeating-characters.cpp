class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int len=0;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            if(mp.size()!=0 && mp.find(s[i])!=mp.end()){
                len=min(i-mp[s[i]],len+1);
                maxi=max(maxi,len);
                mp[s[i]]=i;
            }
            else{
                mp[s[i]]=i;
                len++;
                maxi=max(maxi,len);
            }
        }
        return maxi;
    }          
};