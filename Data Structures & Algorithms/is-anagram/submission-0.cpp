class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for(auto &x: s){
            count[x-'a']++;
        }
        for(auto &x: t){
            count[x-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0)
                return false;
        }
        return true;
    }
};
