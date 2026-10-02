class Solution {
public:
    int calpath(int row,int col,vector<vector<int>> &dp){
        if(row == 0 && col == 0) return 1;
        if(row<0 || col < 0) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int up = calpath(row-1,col,dp);
        int left = calpath(row,col-1,dp);
        return dp[row][col] = up+left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // return calpath(m-1,n-1, dp);
        
        dp[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                int up = 0, left = 0;
                if (i > 0) up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};