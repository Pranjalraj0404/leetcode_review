class Solution {
public:
    int findpar(int u ,vector<int> &parent){
        if(parent[u] == u) return u;
        return parent[u] = findpar(parent[u],parent) ;
    }
    int merge(int u , int v, vector<int> &parent, vector<int> &rank){
        int paru = findpar(u,parent);
        int parv = findpar(v,parent);
        if(paru == parv) return 1;
        if(rank[paru] > rank[parv]){
            parent[parv] = paru;
        }
        else if(rank[parv] > rank[paru]){
            parent[paru] = parv;
        } else{
            parent[parv] = paru;
            rank[paru]++;
        }
        return 0;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>parent(n+1);
        vector<int>rank(n+1,1);
        for(int i = 0 ; i<=n;i++){
            parent[i]=i;
        }
        int extra = 0;
        for(auto it : connections){
            extra += merge(it[0],it[1],parent,rank);
        }
         int components = 0;
        for (int i = 0; i < n; i++) {
            if (findpar(i, parent) == i)
                components++;
        }

        if(extra >= components-1) return components-1;
        else return -1;

    }
};