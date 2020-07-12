// Time:  O(n)
// Space: O(1)

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        uint64_t root = 0;
        for (const auto& node : tree) {
            root ^= reinterpret_cast<uint64_t>(node);
            for (const auto& child : node->children) {
                root ^= reinterpret_cast<uint64_t>(child);
            }
        }
        return reinterpret_cast<Node *>(root);
    }
};
