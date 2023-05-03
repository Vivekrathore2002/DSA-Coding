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
    bool isleaf(TreeNode* root){
        if(!root){return false;}
        return !root->left && !root->right;
    }
    void chk(TreeNode* root, int& sum, int i){
        if(root){
            if(isleaf(root)){sum+=root->val*i; return;}
            chk(root->left, sum, 1);
            chk(root->right, sum, 0);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(!root){return sum;}
        chk(root, sum, 0);
        return sum;
    }
};