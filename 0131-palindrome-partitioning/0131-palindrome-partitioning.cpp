class Solution {
public:
    
    bool isPal(string s, int start, int end) {
    while (start <= end) {
      if (s[start++] != s[end--])
        return false;
    }
    return true;
  }
        
    void help(int index,string s,vector<vector<string>>&res,vector<string>&v){
        if(index==s.size()){
            res.push_back(v);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(isPal(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                help(i+1,s,res,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        help(0,s,res,v);
        return res;
    }
};