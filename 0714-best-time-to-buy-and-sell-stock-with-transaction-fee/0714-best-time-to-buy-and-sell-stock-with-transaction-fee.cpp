class Solution {
public:
    int market(vector<int>& prices, int fee, int index,int buy,vector<vector<int>> &dp){
        if (index==prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy==0){
            return dp[index][buy] = max(market(prices,fee,index+1,0,dp),
            -prices[index]+market(prices,fee,index+1,1,dp));
        }
        else{
            return dp[index][buy] = max(market(prices,fee,index+1,1,dp),
            +prices[index]-fee+market(prices,fee,index+1,0,dp));
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp (prices.size(),vector<int>(2,-1));
        return market(prices,fee,0,0,dp);
    }
};