class Solution {
public:
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq_map;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        freq_map[nums[i]]++;
    }

    vector<pair<int, int>> freq_vector(freq_map.begin(), freq_map.end());
    vector<int> str;
    if (k > freq_map.size())
    {
        int n = k - freq_map.size();
        for (int i = 0; i < n; i++)
        {
            str.push_back(0);
        }
    }
    sort(freq_vector.begin(), freq_vector.end(), [](pair<int, int> &a, pair<int, int> &b)
         { return a.second > b.second; });
    int i = 0;
    for (auto k_element : freq_vector)
    {
        if (k <= i)
        {
            break;
        }
        str.push_back(k_element.first);
        i++;
    }
    sort(str.begin(), str.end());

    return str;
}
};
