class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> mp;
        for(auto &x: nums){
            if(mp.find(x)!=mp.end()){
                return true;
            }
            mp.insert(x);
        }
        return false;
    }
};