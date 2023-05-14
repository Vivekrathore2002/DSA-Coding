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
class Solution
{
public:
    // height is the max of the left and right subtree + 1
    // balance factor is the height of the left subtree - the height of the right subtree
    bool isBalanced(TreeNode *root)
    {
        bool result = true;
        helper(root, result);

        return result;
    }

    int helper(TreeNode *root, bool& balanced)
    {
        // base case if current node is null
        // if the boolean has been set to false
        // we do not care about the rest of the nodes
        // as it is already unbalanced
        if (root == nullptr || balanced == false)
        {
            return 0;
        }
        // traverse the left and right subtree until you reach a null node.
        int left_height = helper(root->left, balanced);
        int right_height = helper(root->right, balanced);

        // calculate the balance factor of the current level
        if (abs(left_height - right_height) > 1)
        {
            balanced = false;
        }
        //returns the height of the current level
        return max(left_height, right_height) + 1;
    }
};