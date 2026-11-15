class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums1.size();
        unordered_map<int,int> mp;
        int prev = -1;
        vector<int> res(n,-1);

        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                prev = st.top();
            }
            else{
                prev = -1;
            }
            st.push(nums2[i]);

            mp[nums2[i]] = prev; 
        }

        for(int i=0;i<n;i++){
            res[i] = mp[nums1[i]];
        }


        return res;
    }
};