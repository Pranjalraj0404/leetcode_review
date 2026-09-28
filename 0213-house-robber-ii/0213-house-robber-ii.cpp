class Solution {
public:
    int check(vector<int>& nums,int start , int end){
        int n = nums.size();
        int curr = 0 ,prev = 0 , prev1 = 0;

        for(int i = start ; i <= end ; i++){
            int take = nums[i] + prev1;
            int nottake = prev;
            curr = max(take,nottake);
            prev1=prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n==1) return nums[0];
        int start = check(nums,0,n-2);
        int last = check(nums,1,n-1);
        return max(start,last);
    }
};