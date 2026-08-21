class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int> &vis , int node){
        for (int nei : graph[node]) {
            if(vis[nei] == 0){
                vis[nei]= 3 - vis[node];
                if(!dfs(graph,vis,nei)) return false;
            }
            else if (vis[nei] == vis[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v,0);
        for(int i = 0 ; i < v ;i++){
            if(vis[i] == 0){
               vis[i] = 1;
                if(!dfs(graph,vis,i)) return false;
            }
        }
        return true;
    }
};