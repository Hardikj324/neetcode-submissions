class Solution {
public:
   bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int right = matrix[0].size() - 1;
    int left = 0;
    int down = matrix.size() - 1;
    int up = 0;

    while (left <= right && down >= up)
    {
        if (matrix[up][right] == target)
        {
            return true;
        }
        else if (target < matrix[up][right])
        {
            right--;
        }
        else
        {
            up++;
        }
    }
    return false;
}
};
