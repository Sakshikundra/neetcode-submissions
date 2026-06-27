class Solution {
    vector<vector<int>> ans;
    vector<int> curr;
    void dfs(int index,
             vector<int>& nums,
             int target){
                 if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(index == nums.size() || target < 0)
            return;

        //take 
curr.push_back(nums[index]);
dfs(index,
            nums,
            target - nums[index]);

        curr.pop_back();
        // Skip
        dfs(index + 1,
            nums,
            target);

             }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0,nums,target);
        return ans;
    }
};
