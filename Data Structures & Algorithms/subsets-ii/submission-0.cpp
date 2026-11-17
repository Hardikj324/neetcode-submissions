class Solution {
public:
    void solver(vector<int>& nums,set<vector<int>> &st,vector<int> &temp,int i){
        if(i==nums.size()){
            st.insert(temp);
            return ;
        }

        temp.push_back(nums[i]);
        solver(nums,st,temp,i+1);
        temp.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]){
            i++;
        }
        solver(nums,st,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        solver(nums,st,temp,0);
        vector<vector<int>> res(st.begin(),st.end());
        return res;        
    }
};
