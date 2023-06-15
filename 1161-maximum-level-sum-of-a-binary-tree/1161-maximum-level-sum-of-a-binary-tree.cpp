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
//  https://www.youtube.com/watch?v=IG82aXSrIgs&ab_channel=CODEKARLO
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;  // Track the current level
        int maxLevel = 1;  // Track the level with the highest sum
        int maxSum = INT_MIN;  // Track the highest sum
        while (!q.empty()) {
            int size = q.size();
            int sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                sum += temp->val;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                maxLevel = level;
            }
            level++;  // Move to the next level
        }
        return maxLevel;
    }
};
