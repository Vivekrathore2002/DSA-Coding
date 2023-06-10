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

//  https://www.youtube.com/watch?v=JBYs5J4skZE&ab_channel=CodewithAlisha

class Solution {
public:
int findmaxpath(TreeNode* A,int& ans){
    if(!A) return 0;
    int left = findmaxpath(A->left,ans);
    int right = findmaxpath(A->right,ans);
    int straightpath = max(A->val,max(left+A->val,right+A->val));
    int curvedpath = left+right+ A->val;
    ans = max(ans,max(straightpath,curvedpath));
    return straightpath;
}
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        findmaxpath(root,ans);
        return ans;
    }
};