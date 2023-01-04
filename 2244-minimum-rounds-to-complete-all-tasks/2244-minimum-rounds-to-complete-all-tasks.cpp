class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
       unordered_map<int,int>mp;
       for(int i=0;i<tasks.size();i++){
           mp[tasks[i]]++;
       }
        int ct=0;
       for(auto x:mp){
           int y=x.second;
           if(y<2){
               return -1;
           }
           while(y!=0){
               if(y%3==0){
                   y=y-3;
                   ct++;
               }
               else if(y%2==0){
                   y=y-2;
                   ct++;
               }
               else if(y-3>=0){
                    y=y-3;
                   ct++;
               }
               
           }
           if(y!=0){
               return -1;
           }
       }
        return ct;
    }
};