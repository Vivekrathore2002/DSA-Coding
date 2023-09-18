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
//  https://www.youtube.com/watch?v=80Zug6D1_r4&t=1109s
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector < int > inorder;
        TreeNode * cur = root;
        while (cur != NULL) {
            if (cur -> left == NULL) {
            inorder.push_back(cur -> val);
            cur = cur -> right;
            } else {
            TreeNode * prev = cur -> left;
            while (prev -> right != NULL && prev -> right != cur) {
                prev = prev -> right;
            }

            if (prev -> right == NULL) {
                prev -> right = cur;
                cur = cur -> left;
            } else {
                prev -> right = NULL;
                inorder.push_back(cur -> val);
                cur = cur -> right;
            }
            }
        }
        return inorder;
    }
};