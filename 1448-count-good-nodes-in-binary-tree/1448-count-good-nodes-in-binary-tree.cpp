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
int countGood(TreeNode* root,int maxSoFar){
    if(!root){
        return NULL;
    }
    int count =0;
    if(root->val>=maxSoFar){
        count++;
    }
    count+=countGood(root->left,max(maxSoFar,root->val));
    count+=countGood(root->right,max(maxSoFar,root->val));
    return count;
}
    int goodNodes(TreeNode* root) {
        return countGood(root,INT_MIN);
    }
};