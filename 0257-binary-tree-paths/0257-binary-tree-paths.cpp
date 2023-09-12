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
    private:
    void getPath(TreeNode* root, string current_path, vector<string>& result) {
        if (!root) {
            return;
        }

        if (current_path.empty()) {
            current_path += to_string(root->val);
        } else {
            current_path += "->" + to_string(root->val);
        }

        if (!root->left && !root->right) {
            result.push_back(current_path);
        } else {
            getPath(root->left, current_path, result);
            getPath(root->right, current_path, result);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) {
            string current_path = "";
            getPath(root, current_path, result);
        }
        return result;
    }
};