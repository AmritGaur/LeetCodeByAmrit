class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m-1;
        int y=n-1;
        int back=m+n-1;
        while(x>=0 && y>=0){
            if(nums1[x]>nums2[y]){
                nums1[back]=nums1[x];
                back--;
                x--;
            }
            else if(nums1[x]<=nums2[y]){
                nums1[back]=nums2[y];
                back--;
                y--;
            }
        }
        while(y>=0){
             nums1[back]=nums2[y];
                back--;
                y--;
        }
    }
};