class Solution {

vector<vector<int>> ans;
vector<int> curr ;
vector<bool> used;
private:
void dfs ( vector<int>&nums){
    if (curr.size()==nums.size()){
     ans.push_back(curr);
     return ;}


    for (int i=0 ;i<nums.size();i++){
        if (used[i])
        continue;

        //choose 
        curr.push_back(nums[i]);
        used[i]=true;
        dfs(nums);
        curr.pop_back();
        used[i]=false;
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(),false);

        dfs(nums);

        return ans;
    }
};
