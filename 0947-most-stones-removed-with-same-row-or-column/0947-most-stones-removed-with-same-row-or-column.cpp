class Solution {
public:
    int findpar(int node , vector<int> &parent){
        if(parent[node] == node) return node;
        return parent[node] = findpar(parent[node],parent);
    }

    void mergebysize(int u , int v,vector<int> &parent, vector<int> &rank){
        int paru = findpar(u,parent);
        int parv = findpar(v,parent);
        if(paru == parv) return ; 
        if(rank[paru] > rank[parv]){
            parent[parv] = paru;
            rank[paru] += rank[parv];
        }
        else{
            parent[paru] = parv;
            rank[parv] += rank[paru];
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0 ;
        int maxcol = 0;
        for(auto it : stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        int n = maxrow + maxcol + 2;
        vector<int> parent(n);
        vector<int> rank(n,1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        unordered_map<int, int> stonevalid;
        for(auto it : stones){
            int node = it[0];
            int adjnode = it[1] + maxrow+1;
            mergebysize(node,adjnode, parent, rank);
            stonevalid[node] = 1;
            stonevalid[adjnode] = 1;
        }
        int cnt = 0 ;
        for(auto it :stonevalid){
            if(findpar(it.first,parent) == it.first){
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};