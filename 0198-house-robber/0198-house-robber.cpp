class Solution {
public:
    int check(int node, vector<int>& nums,vector<int> &dp){
        if(node == 0) return nums[0];
        if(node < 0) return 0;
        if(dp[node] != -1) return dp[node];
        int pick = nums[node] + check(node-2,nums,dp);
        int notpick = 0 + check(node-1,nums,dp);
        return dp[node] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return check(nums.size() - 1 , nums,dp);
    }
};