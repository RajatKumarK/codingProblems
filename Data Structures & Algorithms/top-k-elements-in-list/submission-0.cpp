class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;
        for(auto &x: nums){
            mp[x]++;
        }
        vector<pair<int, int>> arr;
        for(auto &x: mp){
            arr.push_back({x.second, x.first});
        }
        sort(arr.begin(), arr.end(), greater<pair<int, int>>());
        for(int i=0;i<k;i++){
            res.push_back(arr[i].second);
        }
        return res;
    }
};
