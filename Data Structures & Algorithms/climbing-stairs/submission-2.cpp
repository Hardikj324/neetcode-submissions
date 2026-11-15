class Solution {
public:
int combinations(int n, int r)
{
    if (r > n)
        return 0; 
    if (r == 0 || r == n)
        return 1; 

    long long result = 1; 
    for (int i = 1; i <= r; i++)
    {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int climbStairs(int n)
{
    int twos = 0;
    int ones = n;
    int output = 0;

    if (n == 0)
    {
        return 0;
    }

    while (ones >= 0)
    {
        output += combinations(twos + ones, twos);
        twos++;
        ones = ones - 2;
    }

    return output;
}
};
