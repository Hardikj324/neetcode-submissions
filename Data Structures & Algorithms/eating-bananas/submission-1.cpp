class Solution {
public:
    bool helper(vector<int> &piles,int m,int h){
        int count = 0;

        for(int i=0;i<piles.size();i++){
            int curr = piles[i];
            count += curr/m;
                if(curr%m!=0){
                    count++;
                }
            if(count>h){
                return false;
            }
        }
        
        return true;
    }
   int minEatingSpeed(vector<int> &piles, int h)
{
    int l = 1;
    int r = *max_element(piles.begin(),piles.end());
    int ans = 0;
    while(l<=r){
        int m = l + (r-l)/2;
        
        if(helper(piles,m,h)){
            ans = m;
            r = m-1;

        }
        else{
            l = m+1;
        }
    }

    return ans;
}
};
