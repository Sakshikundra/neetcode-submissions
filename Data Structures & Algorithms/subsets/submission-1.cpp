class Solution {
    vector<vector<int>> ans ;
    vector<int> curr;

private:

   void dfs(int i , vector <int>& nums){
        //base case 
        if (i==nums.size()){
        ans.push_back(curr);
        return ;}
        
         curr.push_back(nums[i]);
         dfs(i+1,nums);

         curr.pop_back();

         //do not take 
         dfs(i+1,nums);

        

   }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};
