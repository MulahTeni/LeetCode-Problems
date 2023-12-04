class Solution {
public:
    bool resAdd(vector<int>& tmp, int num){
        while(!tmp.empty()){
            if(tmp.back()<0)        return true;
            if(num>tmp.back())
                tmp.pop_back();
                if(tmp.size()<1)    return true;
            else if(num==tmp.back()){
                tmp.pop_back();
                return false;
            }else if(num<tmp.back())
                return false;
        }
        return true;
    }


    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(int i=0; i<asteroids.size(); i++){
            if(res.size()<1)    res.push_back(asteroids[i]);
            else if(res.back()>0 && asteroids[i]<0){
                if(resAdd(res, -asteroids[i]))
                                res.push_back(asteroids[i]);
            }else               res.push_back(asteroids[i]);
        }
        return res;
    }
};