class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char>q1;
        queue<char>q2;
        int c1,c2;
        for(int i=0;i<senate.size();i++){
            q1.push(senate[i]);
            if(senate[i]=='R'){
                c1++;
            }
            else{
                c2++;
            }
        }
        if(c1==0){
            return "Dire";
        }
        else if(c2==0){
            return "Radiant";
        }
        while(q1.size()!=1){
            char temp=q1.front();
            q1.pop();
            
            char x=q1.front();
            if(!q2.empty()){
                char y=q2.front();
                if(y!=temp){
                    q1.push(y);
                    q2.pop();
                    continue;
                }
                
            }
            if(temp==x){
                q2.push(x);
            }
            else{
                q1.pop();
                q1.push(temp);
            }  
        }
        if(q1.front()=='R'){
            return "Radiant";
        }
        return "Dire";
    }
};