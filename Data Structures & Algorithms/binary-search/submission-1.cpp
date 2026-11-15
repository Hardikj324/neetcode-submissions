class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int i=0;
        while(s<=e){
            i = s+e;
            i = i/2;
            if(nums[i]==target){
                return i;
            }
            else if (nums[i]>target){
                e=i-1;
            }
            else if (nums[i]<target){
                s=i+1;
            }

        }
        return -1;
    }
    
};
