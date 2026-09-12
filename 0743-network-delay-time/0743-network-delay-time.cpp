class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(int i = 0 ; i < times.size();i++){
            int src = times[i][0];
            int dest = times[i][1];
            int time = times[i][2];
            adj[src].push_back({dest,time});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> cost(n+1,1e9);
        cost[k] = 0;
        q.push({0,{k,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int time = it.first;
            int node = it.second.first;
            int weight = it.second.second;

            for(auto edge : adj[node]){
                int nextnode = edge.first;
                int timet = edge.second;
                
                if(weight + timet < cost[nextnode]){
                    cost[nextnode] = weight + timet;
                    q.push({time+1,{nextnode,weight + timet}});
                }
            }
        }
        int ans = 0;
        for(int i = 1 ; i<=n ;i++){
            if(cost[i] == 1e9) return -1;
            ans = max(ans,cost[i]);
        }
        return ans;
    }
};