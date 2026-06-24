class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int index, vector<int>& candidates, int target) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(target < 0)
            return;

        for(int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if(i > index && candidates[i] == candidates[i - 1])
                continue;

            // Optimization
            if(candidates[i] > target)
                break;

            curr.push_back(candidates[i]);

            // i+1 because each number can be used only once
            dfs(i + 1, candidates, target - candidates[i]);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        dfs(0, candidates, target);

        return ans;
    }
};