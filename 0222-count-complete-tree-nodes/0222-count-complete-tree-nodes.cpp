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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int leftHeight = 0, rightHeight = 0;
        TreeNode* leftNode = root;
        TreeNode* rightNode = root;
        
        while (leftNode != nullptr) {
            leftNode = leftNode->left;
            leftHeight++;
        }
        
        while (rightNode != nullptr) {
            rightNode = rightNode->right;
            rightHeight++;
        }
        
        if (leftHeight == rightHeight) {
            // The tree is a complete binary tree, so we can calculate the node count directly
            return pow(2, leftHeight) - 1;
        } else {
            // The tree is not complete, so we count the nodes recursively
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }
};