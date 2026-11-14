class Solution {
public:
//memo
    int check(int index ,vector<int>& coins, int amount , vector<vector<int>> dp){
        if(index == 0){
            if(amount%coins[index] == 0) return amount/coins[index];
            else return 1e9;
        }
        if(dp[index][amount] != -1) return dp[coins[index]][amount];
        int nottake = check(index-1,coins,amount,dp);
        int take= 1e9;
        if (coins[index] <= amount) take = 1 + check(index,coins,amount - coins[index],dp);
        return dp[index][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        // //memo
        // int ans = check(n-1,coins,amount,dp);
        for(int tar = 0; tar <= amount; tar++) {
            if(tar % coins[0] == 0)
                dp[0][tar] = tar / coins[0];
            else
                dp[0][tar] = 1e9;
        }

        for(int index = 1 ; index < n;index++){
            for(int tar = 0; tar <= amount; tar++){
            int nottake = dp[index-1][tar];
            int take= 1e9;
            if (coins[index] <= tar) take = 1 + dp[index][tar - coins[index]];
            dp[index][tar] = min(take,nottake);
            }
        }
        int ans=  dp[n-1][amount];

       return ans >= 1e9 ? -1 : ans;
    }
};