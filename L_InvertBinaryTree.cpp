// class Solution {
// public:
//     TreeNode* invertTree(TreeNode* root) {
//         if(!root)
//         return NULL;
//         invertTree(root->left);
//         invertTree(root->right);
//         TreeNode* temp;
//         temp=root->left;
//         root->left=root->right;
//         root->right=temp;
//         return root;
//     }
// };