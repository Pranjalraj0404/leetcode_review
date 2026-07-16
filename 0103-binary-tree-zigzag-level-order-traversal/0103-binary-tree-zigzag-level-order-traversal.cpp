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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);
        int flag = true;
        while(!q.empty()){
            vector<int>s;
            int size = q.size();
            
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();
                s.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if (!flag) reverse(s.begin(), s.end());
            ans.push_back(s);
            flag = !flag;
        }
        return ans;
    }
};