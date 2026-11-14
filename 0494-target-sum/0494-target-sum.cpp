class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;
        for (auto it : nums) sum += it;
        if (abs(target) > sum || (sum + target) % 2 != 0)
            return 0;
        int goal = (sum + target) / 2;
        vector<vector<int>> dp(n, vector<int>(goal + 1, 0));
        if (nums[0] == 0)
            dp[0][0] = 2;
        else
            dp[0][0] = 1;

        if (nums[0] != 0 && nums[0] <= goal)
            dp[0][nums[0]] = 1;

        for (int index = 1; index < n; index++) {
            for (int tar = 0; tar <= goal; tar++) {

                int nottake = dp[index - 1][tar];

                int take = 0;
                if (nums[index] <= tar)
                    take = dp[index - 1][tar - nums[index]];

                dp[index][tar] = take + nottake;
            }
        }

        return dp[n - 1][goal];
    }
};