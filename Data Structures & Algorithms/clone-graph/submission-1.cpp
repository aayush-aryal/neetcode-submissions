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
    unordered_map<Node*,Node*> clonemap;
    queue<Node*> q;
    set<Node*> visited;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        return nullptr;
        dfs(node);
        return clonemap[node];
        
    }
    // dfs with visited nodes so it prevents repeated and go through each node and add it to its neighbors vector
    Node* dfs(Node* node){
        if (node==nullptr){
            return nullptr;
        }
        if (visited.find(node)!=visited.end()){
            return clonemap[node];
        }
        visited.insert(node);
        // for the node now create its copy
        Node* copy= new Node(node->val);
        // store the copy in the map
        clonemap[node]=copy;
        for (Node* n: node->neighbors){
            copy->neighbors.push_back(dfs(n));
        }
        return copy;
    }

};
