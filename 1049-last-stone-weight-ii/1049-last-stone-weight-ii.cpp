class Solution {
public:
    bool check(vector<int>& stones, int total,int index, vector<vector<int>> &dp){
        if(total == 0) return true;
        if(index == stones.size()) return false;
    
        if(dp[index][total] != -1) return dp[index][total];

        bool nottake = check(stones,total,index+1,dp);

        bool take = false;
        if(stones[index] <= total) take = check(stones,total-stones[index],index+1,dp);
        return dp[index][total] =  (take || nottake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int totalsum = 0;
        for(int i = 0 ; i < stones.size() ; i++){
            totalsum += stones[i];
        }
        int target = totalsum / 2;
        vector<vector<int>> dp(stones.size(),vector<int>(totalsum+1,-1));
        for (int s = target; s >= 0; s--) {
            if (check(stones, s, 0, dp)) {
                return totalsum - 2 * s;
            }
        }

        return 0;
        // int mini = 1e9;
        // for(int total = 0; total <= totalsum ; total++){
        //     int s1 = dp[stones.size()-1][total];
        //     int s2 = totalsum - s1;
        //     mini = min(mini,abs(s1 - s2));
        // }
        // return mini;
    }
};