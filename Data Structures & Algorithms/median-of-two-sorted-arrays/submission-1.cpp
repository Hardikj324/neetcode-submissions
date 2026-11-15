class Solution {
public:
 double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    double sum = 0;
    double answer;
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    if (nums1.size() % 2 == 0)
    {
        sum = nums1[nums1.size() / 2] + nums1[(nums1.size() / 2) - 1];
        answer = sum / 2;
    }
    else
    {
        sum = nums1[(nums1.size() - 1) / 2];
        answer = sum;
    }

    return answer;
}
};
