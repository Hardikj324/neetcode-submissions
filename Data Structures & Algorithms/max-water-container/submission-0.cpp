class Solution {
public:
    int maxArea(vector<int> &heights)
{
    int max_capacity = 0;
    int cur_max;
    for (int i = 0; i < heights.size() - 1; i++)
    {
        for (int j = i + 1; j < heights.size(); j++)
        {
            cur_max = min(heights[i], heights[j]) * (j - i);
            max_capacity = max(max_capacity, cur_max);
        }
    }
    return max_capacity;
}
};
