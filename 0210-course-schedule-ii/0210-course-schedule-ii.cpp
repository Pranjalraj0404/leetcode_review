class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj,vector<int>& vis, vector<int>& path,vector<int>& order) {
    vis[node] = 1;
    path[node] =1;

    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, path, order) ==  true) return true;
        }
        else if (path[it] == true) return true;
    }

    path[node] = 0;
    order.push_back(node);
    return false;
}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<int> order;
        vector<vector<int>> adj(numCourses);
        for (auto edge : prerequisites) {
            int course = edge[0];
            int prerequisite = edge[1];
            adj[prerequisite].push_back(course);
        }

        for(int i = 0 ; i <  numCourses ;i++){
            if(!vis[i]){
           if(dfs(i, adj, vis, path, order)) return {};
        }
        }
        reverse(order.begin(), order.end());
        return order;

    }
};