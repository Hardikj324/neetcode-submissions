class Solution {
public:
    void solver(vector<int>& candidates, int target,int sum,int i,vector<int> &vec,set<vector<int>> &st){

        if(sum==target){
            st.insert(vec);
            return ;
        }
        if(i==candidates.size() || sum>target){
            return ;
        }

        vec.push_back(candidates[i]);
        solver(candidates,target,sum+candidates[i],i+1,vec,st);
        vec.pop_back();
        while(i<candidates.size()-1 && candidates[i]==candidates[i+1]){
            i++;
        }
        solver(candidates,target,sum,i+1,vec,st);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> st;
        sort(candidates.begin(),candidates.end());
        vector<int> vec;
        solver(candidates,target,0,0,vec,st);
        return vector<vector<int>> (st.begin(),st.end());
    }
};