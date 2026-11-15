class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        unordered_map<int, int> num_map;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if complement exists in the map
            if (num_map.find(complement) != num_map.end()) {
                index.push_back(num_map[complement]);
                index.push_back(i);
                return index;
            }

            // Add current number with its index to the map
            num_map[nums[i]] = i;
        }

        return index; // Return an empty vector if no solution is found
    }
};
