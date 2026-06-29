class Solution {
    vector<string> ans;

private:
    void dfs(int open, int close, int n, string curr)
    {
        // Base Case
        if (curr.size() == 2 * n)
        {
            ans.push_back(curr);
            return;
        }

        // Add '('
        if (open < n)
        {
            dfs(open + 1, close, n, curr + "(");
        }

        // Add ')'
        if (close < open)
        {
            dfs(open, close + 1, n, curr + ")");
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        dfs(0, 0, n, "");

        return ans;
    }
};