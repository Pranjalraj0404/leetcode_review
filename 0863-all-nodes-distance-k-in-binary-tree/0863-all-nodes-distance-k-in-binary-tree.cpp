/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void put(TreeNode* root, TreeNode* target,unordered_map<TreeNode* , TreeNode* > &mpp ){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
           if(cur->left){
            mpp[cur->left] = cur;
            q.push(cur->left);
           }
           if(cur->right){
            mpp[cur->right] = cur;
            q.push(cur->right);
           }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mpp;
        
        put(root,target,mpp);
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i  = 0 ; i < size; i++){
                TreeNode* cur = q.front(); q.pop();
                if(cur->left && !visited[cur->left]){
                    q.push(cur->left);
                    visited[cur->left] =  true;
                }
                if(cur->right && !visited[cur->right]){
                    q.push(cur->right);
                    visited[cur->right] =  true;
                }
                if(mpp.count(cur) && !visited[mpp[cur]]){
                    q.push(mpp[cur]);
                    visited[mpp[cur]] =  true;
                }
            }
        } 
        vector<int>result;
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            result.push_back(cur->val);
        }
        return result;
    }
};