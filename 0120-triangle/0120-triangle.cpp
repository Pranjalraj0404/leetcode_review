class Solution {
public:
    int check(int start ,int width,vector<vector<int>>& triangle,int size ,vector<vector<int>> &dp){
        if(start == size -1 ) return triangle[start][width];
        if(dp[start][width] != -1) return dp[start][width];
        int low = triangle[start][width]+check(start + 1, width,triangle,size,dp);
        int lowd = triangle[start][width] + check(start + 1, width+1,triangle,size,dp);
        return dp[start][width] = min(low,lowd);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // return check(0,0,triangle,n,dp);
        for(int j = 0 ; j < n ;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i = n-2 ; i >= 0 ; i--){
            for(int j = 0 ; j <= i ; j++){
                int di = triangle[i][j] + dp[i+1][j];
                int dia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(di,dia);
            }
        }
        return dp[0][0];
    }
};