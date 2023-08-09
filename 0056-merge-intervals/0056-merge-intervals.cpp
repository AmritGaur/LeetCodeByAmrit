class Solution {
public:
    
        static bool sortcol(const vector<int>&v1,const vector<int>&v2){
            return v1[0]<v2[0];
        }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(),sortcol);
        vector<vector<int>>v;
        vector<int>sub;
        int x=intervals[0][0];
        int y=intervals[0][1];
        sub.push_back(x);
        sub.push_back(y);
        v.push_back(sub);
        for(int i=1;i<intervals.size();i++){
            x=intervals[i][0];
            y=intervals[i][1];
            if(x >=v.back().front() && x<=v.back().back()){
                v.back().back()=max(v.back().back(),y);
            }
            else{
                sub.clear();
             sub.push_back(x);
             sub.push_back(y);
             v.push_back(sub);
            }
        }
        return v;
    }
};