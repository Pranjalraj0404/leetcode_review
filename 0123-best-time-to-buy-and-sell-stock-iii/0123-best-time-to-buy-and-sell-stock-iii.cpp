class Solution {
public:

    int profit(int index,int buy,vector<int>& prices,vector<vector<vector<int>>> &dp,int cap ){
        if(cap == 0)return 0;
        if(index == prices.size()) return 0;
        int win = 0 ;
        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];
        if(buy == 0){
            int take = -prices[index] + profit(index +1 ,1,prices,dp,cap);
            int nottake = 0 + profit(index +1 ,0 ,prices,dp,cap);
            win = max(take, nottake);
        }
        else{
            int sell = +prices[index] + profit(index+1,0,prices,dp,cap-1);
            int notsell = 0 + profit(index+1,1,prices,dp,cap);
            win += max(sell,notsell);
        }
        return dp[index][buy][cap] = win;
    }

    int maxProfit(vector<int>& prices) {
        int cap = 2;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return profit(0,0,prices,dp,cap);
    }
};