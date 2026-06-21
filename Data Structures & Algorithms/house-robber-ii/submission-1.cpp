class Solution {
private: 
int solve(int i ,vector<int>& nums ,vector<int>&dp){
    int n=nums.size();
    if (i>=n){return 0;}
    if (dp[i]!=-1){
        return dp[i];
    }
    //memo
    int take = nums[i]+solve(i+2,nums,dp);
    int skip=solve(i+1,nums,dp);
    return dp[i]=max(skip,take);
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n == 1)
            return nums[0];

        // Case 1: Remove Last
        vector<int> arr1(nums.begin(), nums.end() - 1);

        // Case 2: Remove First
        vector<int> arr2(nums.begin() + 1, nums.end());

        vector<int> dp1(arr1.size(), -1);
        vector<int> dp2(arr2.size(), -1);

        int ans1 = solve(0, arr1, dp1);

        int ans2 = solve(0, arr2, dp2);

        return max(ans1, ans2);
    }
};
