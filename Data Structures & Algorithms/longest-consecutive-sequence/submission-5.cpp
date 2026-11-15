class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        int longest = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int num : s)
        {
            if (!s.count(num - 1))
            {
                int curr = num;
                int streak = 1;
                while (s.count(curr + 1))
                {
                    curr++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }

};
