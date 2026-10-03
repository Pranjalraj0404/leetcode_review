class Solution {
public:
    int check(int row , int col, vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp){
        if(row == 0 && col == 0) return 1;
        if(row < 0 || col < 0) return 0;
        if(obstacleGrid[row][col] == 1) return 0;
        if(dp[row][col] != -1) return dp[row][col];
        int left = check(row-1,col,obstacleGrid,dp);
        int right = check(row,col-1,obstacleGrid,dp);
        return dp[row][col] = left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return check(m-1,n-1,obstacleGrid,dp);
    }
};