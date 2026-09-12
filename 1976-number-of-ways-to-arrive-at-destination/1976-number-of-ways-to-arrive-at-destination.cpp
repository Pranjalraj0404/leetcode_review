class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<int>ways(n,0);
        vector<long long>dist(n,1e18);
        dist[0]=0;
        ways[0]=1;
        int mod = (int)(1e9+7);
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long wei = it.first;
            int node = it.second;
            if (wei > dist[node])
                continue;
            for(auto edge : adj[node]){
                int newnode = edge.first;
                long long newwei = edge.second;
                if(newwei+wei < dist[newnode]){
                    dist[newnode] = newwei+wei ;
                    ways[newnode] = ways[node];
                    pq.push({newwei+wei , newnode});
                }
                else if(newwei + wei == dist[newnode]){
                    ways[newnode] =(ways[newnode] + ways[node])%mod ;
                }
            }
        }
            return ways[n-1];
    }
};