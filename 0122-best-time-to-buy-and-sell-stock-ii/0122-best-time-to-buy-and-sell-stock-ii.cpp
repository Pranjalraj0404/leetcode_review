class Solution {
public:
    int profit(int index,int buy,vector<int>& prices,vector<vector<int>> &dp ){
        if(index == prices.size()) return 0;
        int win = 0 ;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy == 0){
            int take = -prices[index] + profit(index +1 ,1,prices,dp);
            int nottake = 0 + profit(index +1 ,0 ,prices,dp);
             win = max(take, nottake);
        }
        else{
            int sell = +prices[index] + profit(index+1,0,prices,dp);
            int notsell = 0 + profit(index+1,1,prices,dp);
            win += max(sell,notsell);
        }
        return dp[index][buy] = win;
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        // return profit(0,0,prices,dp);
        
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        
        for(int ind = n-1 ; ind >= 0 ;ind--){
            for(int buy = 0 ; buy <= 1 ; buy++){
        
            int win =0;
        
            if(buy == 0){
            int take = -prices[ind] + dp[ind+1][1];
            int nottake = 0 + dp[ind+1][0];
            win = max(take, nottake);
            }
            else{
                int sell = +prices[ind] + dp[ind+1][0];
                int notsell = 0 + dp[ind+1][1];
                win += max(sell,notsell);
            }
            dp[ind][buy] = win;
         }
        }
        return dp[0][0];
    }
};