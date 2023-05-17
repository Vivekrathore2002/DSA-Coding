class Solution {
public:
    void inorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root == nullptr)
            return;
        inorderTraversal(root->left, vec);
        vec.push_back(root->val);
        inorderTraversal(root->right, vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        inorderTraversal(root, vec);
        return vec[k - 1];  // Adjust index to be 0-based
    }
};
