class Solution {
private:
    bool solve(int i,
               string &s,
               unordered_set<string> &st,
               vector<int> &dp)
    {
        // Base case
        if(i == s.size())
            return true;

        // Memoization
        if(dp[i] != -1)
            return dp[i];

        string temp = "";

        for(int j = i; j < s.size(); j++)
        {
            temp += s[j];

            if(st.count(temp))
            {
                if(solve(j + 1, s, st, dp))
                    return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(),
                                 wordDict.end());

        vector<int> dp(s.size(), -1);

        return solve(0, s, st, dp);
    }
};