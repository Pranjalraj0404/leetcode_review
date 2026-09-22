class Solution {
public:

    int par(int node , vector<int> &parent){
        if(parent[node] == node) return node;
        return parent[node] = par(parent[node],parent);
    }

    bool isvalid(int newrow,int newcol,int n){
        return newrow>=0 && newrow <n && newcol >= 0 && newcol < n;
    }

    void merge(int u , int v , vector<int> &parent, vector<int> &size){
        int paru = par(u,parent);
        int parv= par(v,parent);
        if(paru == parv) return ;
        if(size[paru] > size[parv]){
            parent[parv] = paru;
            size[paru] += size[parv];
        }
        else {
            parent[paru] = parv;
            size[parv] += size[paru];
        } 
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>parent(n*n);
        vector<int> size(n*n,1);
        for(int row = 0 ; row< n*n;row++){
            parent[row] = row;
        }
        //rank group island dsu
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 0)  continue;
                int nr[] = {-1, 0, 0, 1};
                int nc[] = {0, -1, 1, 0};
                int node = row * n + col;
                for(int i = 0 ; i< 4 ; i++){
                    int newrow = row + nr[i];
                    int newcol = col + nc[i];
                if(isvalid(newrow,newcol,n) && grid[newrow][newcol] == 1){
                    int newrowno = newrow * n + newcol;
                    merge(node,newrowno,parent,size);
                }
             }
            }
        }

        //check karna 
        int maxi = 0;
        for(int row = 0 ; row < n ; row++){
            for(int col = 0 ; col < n ; col++){
                if(grid[row][col] == 1)  continue;
                int nr[] = {-1, 0, 0, 1};
                int nc[] = {0, -1, 1, 0};
                 int currSize = 1;
                 set<int> components;
                for(int i = 0; i < 4; i++) {
                int newrow = row + nr[i];
                int newcol = col + nc[i];

                if(isvalid(newrow, newcol, n) &&
                grid[newrow][newcol] == 1) {

                    int newNode = newrow * n + newcol;
                    int root = par(newNode, parent);

                    components.insert(root);
                }
            }
               for(int root : components) {
                    currSize += size[root];
                }
                maxi = max(maxi, currSize);
            }}
    if (maxi == 0) return n * n;

        return maxi;

    }
};