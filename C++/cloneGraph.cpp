// Time Complexity: O(n)
// Space Complexity: O(n)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    public:
        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            if(!node)
                return nullptr;
            unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
            copied[node] = new UndirectedGraphNode(node->label);
            queue<const UndirectedGraphNode *> q;
            q.push(node);
            while(!q.empty()) {
                auto node = q.front();
                q.pop();

                for(auto n : node->neighbors) {
                    if(copied.find(n) == copied.end()) {
                        copied[n] = new UndirectedGraphNode(n->label);
                        q.push(n);
                    }

                    copied[node]->neighbors.push_back(copied[n]);
                }
            }

            return copied[node];
        }
};
