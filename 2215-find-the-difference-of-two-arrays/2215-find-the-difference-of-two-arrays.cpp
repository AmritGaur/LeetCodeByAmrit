class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>v;
        vector<int>layer;
        for(int i=0;i<nums1.size();i++){
            int x=nums1[i];
            if(find(nums2.begin(),nums2.end(),x)==nums2.end() && find(layer.begin(),layer.end(),x)==layer.end()){
                layer.push_back(x);
            }
        }
        v.push_back(layer);
        layer.clear();
        for(int i=0;i<nums2.size();i++){
            int y=nums2[i];
            if(find(nums1.begin(),nums1.end(),y)==nums1.end() && find(layer.begin(),layer.end(),y)==layer.end()){
                layer.push_back(y);
            }
        }
        v.push_back(layer);
        return v;
    }
};