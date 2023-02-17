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
    void diff(TreeNode* root,int &ans,int &prev){
        if(root==NULL){
            return;
        }
        diff(root->left,ans,prev);
        if(prev!=-1){
            ans=min((root->val)-prev,ans);

        }
        prev=root->val;
        diff(root->right,ans,prev);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        int ans=INT_MAX;
        int prev=-1;
        diff(root,ans,prev);
        return ans;
    }
};