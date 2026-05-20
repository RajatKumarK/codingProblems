/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL){
            return NULL;
        }
        if(mp.find(node->val)!=mp.end()){
            return mp[node->val];
        }
        Node *curr = new Node(node->val);
        mp.insert({node->val, curr});

        for(auto &x: node->neighbors){
            curr->neighbors.push_back(cloneGraph(x));
        }
        return curr;
    }
};
