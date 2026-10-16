class Solution {
public:
    int check(int index,int k , vector<int> & prices , int cnt, int buy,vector<vector<vector<int>>> &dp){
        if(cnt == k) return 0;
        if(index == prices.size()) return 0;
        if(dp[index][buy][cnt] != -1) return dp[index][buy][cnt] ;
        if(buy == 0){
            return dp[index][buy][cnt] = max(check(index+1,k,prices,cnt,0,dp),
            -prices[index]+check(index+1,k,prices,cnt,1,dp));
        }
        else{
            return dp[index][buy][cnt] =  max(check(index+1,k,prices,cnt,1,dp),
            +prices[index]+check(index+1,k,prices,cnt+1,0,dp));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return check(0,k,prices,0,0,dp);
    }
};