class Solution {
vector<string>ans;
vector<string> phone ={
     "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
};

private:
void dfs (int index, string &digits, string & curr){
    

    if (index==digits.size()){
        ans.push_back(curr);
        return ;
    }

    string letters=phone[digits[index]-'0'];

    for (char ch:letters){
        curr.push_back(ch);
        dfs(index+1,digits,curr);
        curr.pop_back();

    } 

}

public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty())
            return {};

        string curr;

        dfs(0,digits,curr);

        return ans;
    
    }
};
