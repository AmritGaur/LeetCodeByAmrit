/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void vOt(TreeNode* root,  map<int,map<int,multiset<int>>>&mp,int l,int b){
        if(root==NULL){
            return ;
        }
        mp[l][b].insert(root->val);
        vOt(root->left,mp,l-1,b+1);
        vOt(root->right,mp,l+1,b+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int,map<int,multiset<int>>>mp;
        int lw;
        vOt(root,mp,0,0);
        vector<vector<int>>v;
        for(auto x:mp){
            vector<int>col;
            for(auto y:x.second){
            col.insert(col.end(),y.second.begin(),y.second.end());
        }
            v.push_back(col);
         
    }
        return v;
    }
};