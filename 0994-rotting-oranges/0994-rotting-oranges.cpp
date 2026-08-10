class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int cr[] = {-1, 0, 0, 1};
        int cc[] = {0, -1, 1, 0};

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {

                    int nr = r + cr[j];
                    int nc = c + cc[j];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }
        if (fresh > 0)
            return -1;

        return minutes;
    }
};