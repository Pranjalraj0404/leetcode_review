class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int row,int col) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == '1' &&
                    !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        int cnt = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    bfs(grid, vis, i, j);
                }
            }
        }
        return cnt;
    }
};