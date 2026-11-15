class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> res;

        for (int a : asteroids) {
            bool des = false;
            while(!res.empty() && a<0 && res.back()>0){
                if(res.back()<abs(a)){
                    res.pop_back();
                }
                else if(res.back()>abs(a)){
                    des = true;
                    break;
                }
                else{
                    res.pop_back();
                    des = true;
                    break;
                }
            }
            if(!des){
                res.push_back(a);
            }
        }

        
        return res;
    }
};