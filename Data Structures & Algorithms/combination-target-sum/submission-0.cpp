class Solution {
public:
    void solver(vector<int>& nums,int target,vector<int> &temp,vector<vector<int>> &ans,int i){

        if(target==0 && i<nums.size()){
            ans.push_back(temp);
            return ;
        }
        if(target<0){
            return ;
        }

        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            solver(nums,target-nums[j],temp,ans,j);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        solver(nums,target,temp,ans,0);

        return ans;
    }
};
