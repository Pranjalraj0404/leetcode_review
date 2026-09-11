class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1) return -1;
        vector<vector<int>> vis(m, vector<int>(n,1e9));
        int nr[] = {-1,-1,-1,0,0,1,1,1};
        int nc[] = {-1,0,1,-1,1,-1,0,1};
        vis[0][0] = 1;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it  = q.front();
            q.pop();
            int dis = it.first ;
            int row  =  it.second.first;
            int col  = it.second.second;
            if (row == m - 1 && col == n - 1)
                return dis;
            for(int i = 0 ; i < 8 ; i++){
                int nrow = row + nr[i];
                int ncol = col + nc[i];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && dis + 1 < vis[nrow][ncol] && grid[nrow][ncol] == 0){
                    vis[nrow][ncol] = dis + 1;
                    q.push({dis +1, {nrow,ncol}});

                }
            }
        }
        return -1;
    }
};