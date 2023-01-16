class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>v;
        vector<int>x;
        
        //v.push_back(intervals[0]);
        int n= intervals.size();
        bool first=false;
        int mini= newInterval[0];
            int maxi= newInterval[1];
        for(int i=0;i<n;i++){
            if((mini>=intervals[i][0] && mini<=intervals[i][1]) || (maxi>=intervals[i][0] && maxi<=intervals[i][1])){
              mini=min(mini,(intervals[i][0]));
              maxi=max(maxi,intervals[i][1]);
                       if(v.size()>0 && first!=false){
                           v.pop_back();
                       }
                       x.push_back(mini);
                       x.push_back(maxi);
                       v.push_back(x);
                       x.clear();
                       first=true;

           
      }
            else if(mini<=intervals[i][1] && maxi>=intervals[i][0]){
                continue;
            }
            else{
                v.push_back(intervals[i]);
               // break;
            }
                       
   }
        if(v.size()==0 || first==false ){
            v.push_back(newInterval);
            sort(v.begin(),v.end());
        }
   return v;                    
}
};