class Solution {

    vector <vector<int >> ans;
        vector<int> curr;
public:
    void dfs(int i ,vector<int>&nums){
        

        //base case 
        if (i==nums.size()){
            ans.push_back(curr);
            return ;

        }
        //take 
        curr.push_back (nums[i]);
        dfs(i+1,nums);
        

        //undo 
        curr.pop_back();
        //skip 
        dfs(i + 1, nums);
    
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans ;
    }
};
