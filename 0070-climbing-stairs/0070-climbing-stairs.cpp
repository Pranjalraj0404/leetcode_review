class Solution {
public:
    // int cnt(int n){
    //     if(n == 0) return 1;
    //     if(n == 1) return 1;
    //     int left = cnt(n-1);
    //     int right = cnt(n-2);
    //     return left+ right;

    // }
    int climbStairs(int n) {
        // return cnt(n);
        if (n <= 2) return n;
        int prev2 = 1;
        int prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};