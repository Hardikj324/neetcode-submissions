class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        unordered_map<int, int> value_to_index; // maps value → index (0-based)

        for (int i = 0; i < numbers.size(); i++)
        {
            int complement = target - numbers[i];
            if (value_to_index.count(complement))
            {
                // +1 to convert to 1-based indexing if required
                return {value_to_index[complement] + 1, i + 1};
            }
            value_to_index[numbers[i]] = i;
        }
        return {}; // No pair found
    }
};