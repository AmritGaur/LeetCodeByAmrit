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
    void inorder(TreeNode* root,int&ans, int &prev){
        if(root->left!=NULL){
        inorder(root->left,ans,prev);
        }
        if(prev>=0){
            ans=min(ans,abs((root->val)-prev));
        }
        prev=root->val;
        if(root->right!=NULL){
        inorder(root->right,ans,prev);
    }
        return ;
    }
    int getMinimumDifference(TreeNode* root){
        int prev=-1;
        int ans=INT_MAX;
        inorder(root,ans,prev);
        return ans;}
};