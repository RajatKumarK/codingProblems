class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& isVisited, int curr, int par){
        isVisited[curr]=true;
        for(auto &x: adj[curr]){
            if(x==par) continue;
            if(isVisited[x]==true)
                return false;
            else if(dfs(adj, isVisited, x, curr)==false)
                return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto &x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> isVisited(n, false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(isVisited[i]==false){
                if(dfs(adj, isVisited, i, -1)==false){
                    return false;
                }
                count++;
            }
        }
        if(count>1)
            return false;
        return true;
    }
};
