class Solution {
public:
 vector<int> productExceptSelf(vector<int> &nums)
{
    int product = 1;
    bool have_zero = false;
    int num_of_zero = 0;
    for (int x : nums)
    {
        if (x != 0)
        {
            product *= x;
        }
        else
        {
            have_zero = true;
            num_of_zero += 1;
        }
    }
    vector<int> output;
    for (int x : nums)
    {
        if (x != 0)
        {

            if (have_zero)
            {
                output.push_back(0);
            }
            else
            {
                output.push_back(product / x);
            }
        }
        else
        {
            if (num_of_zero <= 1)
                output.push_back(product);
            else
            {
                output.push_back(0);
            }
        }
    }

    return output;
}
};
