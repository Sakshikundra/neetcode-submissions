class Solution {
    vector<vector<int>>ans;
    vector<int>curr;
    
private:
   void dfs(int i,vector<int>&nums){
    //base case 
   
    
        ans.push_back(curr);
    
    


    //for loop
    for (int j=i;j<nums.size();j++){
        if( j>i && nums[j]==nums[j-1]){
            continue;
        }

        curr.push_back(nums[j]);
        dfs(j+1 , nums);
        
        curr.pop_back();
    }
    
   }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(0,nums);
        return ans;
    }
};
