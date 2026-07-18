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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            TreeNode* cur = it.first;
            int x = it.second.first;
            int y = it.second.second;

            nodes[x][y].insert(cur->val);

            if(cur->left)
                q.push({cur->left,{x-1,y+1}});

            if(cur->right)
                q.push({cur->right,{x+1,y+1}});
        }

        vector<vector<int>> ans;
        for(auto &col : nodes){
            vector<int> temp;
            for(auto &row : col.second){
                for(int val : row.second)
                    temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};