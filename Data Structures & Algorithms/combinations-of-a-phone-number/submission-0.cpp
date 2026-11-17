class Solution {
public:
unordered_map<char, string> phoneMap = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    void solver(string digits,vector<string> &vec,string temp,int i){
        if(i==digits.size()){
            vec.push_back(temp);
            return ;
        }

        string s = phoneMap[digits[i]];

        for(int j=0;j<s.size();j++){
            temp.push_back(s[j]);
            solver(digits,vec,temp,i+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="") return {};
       vector<string> vec;
       string temp = "";
        solver(digits,vec,temp,0);
        return vec;
    }
};
