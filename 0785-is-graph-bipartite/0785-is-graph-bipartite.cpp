class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        queue<pair<int,int>> q;
        vector<int> vis(v,-1);
        for(int i = 0 ; i < v ; i++){
            if(vis[i] == -1){
                vis[i] = 1;
                q.push({i,1});
            }

            while(!q.empty()){
            int node = q.front().first;
            int col = q.front().second;
            q.pop();
            for(auto it : graph[node]){
                if(vis[it] == -1){
                    vis[it] = !col;
                    q.push({it,!col});
                }
            else if (vis[it] == col) {
                return false;
            }
            }
            }
        }
        return true;
    }
};