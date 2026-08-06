class Solution {
public:
    void dfs(vector<int> &vis , vector<vector<int>>& isConnected, int i ){
        vis[i] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(vis, isConnected, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0 ;
        int V = isConnected.size();
        vector<int> vis(V,0);
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                cnt++;
                dfs(vis,isConnected, i);
            }
        }
        return cnt;
    }
};