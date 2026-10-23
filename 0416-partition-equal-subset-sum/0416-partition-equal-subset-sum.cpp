class Solution {
public:
    bool check(int index,int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0 ) return true;
        if(index == nums.size()) return false;
        if(dp[index][target] != -1) return dp[index][target];
        bool nottake = check(index+1,target,nums,dp);
        bool take = false;
        if(nums[index] <= target) take = check(index+1,target-nums[index],nums,dp);
        return dp[index][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(int it : nums) target += it;
        if (target % 2 != 0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return check(0,target/2,nums,dp);
    }
};