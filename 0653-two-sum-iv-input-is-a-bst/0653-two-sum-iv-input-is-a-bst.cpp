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
    bool target(TreeNode* root, int k, unordered_set<int> &st){
        if(!root){
            return false;
        }
        
        if(target(root->left, k, st)){
            return true;
        }
        int val = root->val;
        if(st.find(k-val) != st.end()){
            return true;
        }
        st.insert(val);
        if(target(root->right, k, st)){
            return true;
        }
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return target(root, k, st);
    }
};