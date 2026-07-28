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
    bool check(TreeNode* root,long long a,long long b){
        if(root == NULL) return true;
        if(root->val <= a || root->val >= b){
            return false;
        }
        return check(root->left,a,root->val)&& check(root->right,root->val,b);
    }
    bool isValidBST(TreeNode* root) {
        long long a = LLONG_MIN;
        long long b = LLONG_MAX;
        return check(root,a,b);
    }
};