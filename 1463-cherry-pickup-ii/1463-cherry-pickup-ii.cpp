class Solution {
public:
    int check(int row,int n, int m ,int alicestart,int bobstart, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp){
        if(alicestart < 0 || alicestart >= m || bobstart < 0 || bobstart >= m) return -1e8;

        if (dp[row][alicestart][bobstart] != -1) return dp[row][alicestart][bobstart];
        
        if(row == n-1){
            if(bobstart == alicestart) return  dp[row][alicestart][bobstart] =  grid[n-1][alicestart];
            else return  dp[row][alicestart][bobstart] = grid[n-1][alicestart] + grid[n-1][bobstart];
        }
        
        int maxi = -1e9;
        
        for(int d1 = -1 ; d1 <=1 ; d1++){
            for(int d2 = -1 ; d2 <= 1 ; d2++){
                int value = 0 ;
                if (alicestart == bobstart) value = grid[row][alicestart];
                else value = grid[row][alicestart] + grid[row][bobstart];
                 int result = check(row+1,n,m,alicestart+d1,bobstart+d2,grid,dp) + value;
                  maxi = max(maxi, result);
            }
        }
        return  dp[row][alicestart][bobstart] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return check(0,n,m,0,m-1,grid,dp);
    }
};