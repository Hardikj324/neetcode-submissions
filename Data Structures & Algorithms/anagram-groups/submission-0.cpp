class Solution {
public:
   static int ind(vector<string> a, vector<string> b)
{
    return a.size() < b.size();
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> sort_pair;
    vector<vector<string>> group;
    for (int i = 0; i < strs.size(); i++)
    {
        string key = strs[i];
        sort(key.begin(), key.end());
        sort_pair[key].push_back(strs[i]);
    }

    for (auto p : sort_pair)
    {
        group.push_back(p.second);
    }
    sort(group.begin(), group.end(), ind);
    return group;
}

};
