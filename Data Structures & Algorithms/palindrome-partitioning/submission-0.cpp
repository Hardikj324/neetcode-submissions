class Solution {
public:
    bool is_valid(string s){
        int i = s.size() - 1;
        int j = 0;

        while(j<i){
            if(s[i]!=s[j]){
                return false;
            }
            i--;
            j++;
        }
        return true;
    }

    void solver(string s,vector<string> &temp,vector<vector<string>>& vec,int i){
        if(i==s.size() && temp.size()>0){
            vec.push_back(temp);
            return ;
        }
        string str = "";
        for(int j = i;j<s.size();j++){
            str += s[j];
            if(is_valid(str)){
                temp.push_back(str);
                solver(s,temp,vec,j+1);
                temp.pop_back(); 
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> vec;

        solver(s,temp,vec,0);
        return vec;
    }
};
