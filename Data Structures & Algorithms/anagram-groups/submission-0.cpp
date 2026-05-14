class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        int n = strs.size();
        vector<bool> isCovered(n, false);

        for(int i=0;i<n;i++){
            if(isCovered[i]==true)
                continue;

            isCovered[i]=true;
            vector<string> curr;
            curr.push_back(strs[i]);
            
            vector<int> count(26, 0);
            for(auto &x: strs[i]){
                count[x-'a']++;
            }

            for(int j=i+1;j<n;j++){
                if(isCovered[j]==true)
                    continue;

                vector<int> test = count;
                for(auto &x: strs[j]){
                    test[x-'a']--;
                }
                bool flag = true;
                for(int k=0; k<26; k++){
                    if(test[k]!=0){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    isCovered[j]=true;
                    curr.push_back(strs[j]);
                }
            }
            res.push_back(curr);
        }
        return res;
    }
};
