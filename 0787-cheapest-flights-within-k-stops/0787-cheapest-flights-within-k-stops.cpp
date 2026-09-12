class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i = 0 ; i <  flights.size() ; i++){
            int src = flights[i][0];
            int dest =  flights[i][1];
            int cost = flights[i][2];
            adj[src].push_back({dest,cost});
        }
        vector<int> dest(n,1e9);
        dest[src] = 0;
        queue<pair<int, pair<int, int>>> q;
        //ruka , node , kitna dur 
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int step = it.first;
            int node = it.second.first;
            int cost  = it.second.second;
            if (step > k)  continue;

            for(auto edge : adj[node]){
                int nextNode = edge.first;
                int price = edge.second;
            if(cost + price < dest[nextNode] ){
                dest[nextNode] = cost + price ;
                q.push({step+1,{nextNode,dest[nextNode]}});
            }
            }
        }
        return dest[dst] == 1e9 ? -1 : dest[dst]; 
    }
};