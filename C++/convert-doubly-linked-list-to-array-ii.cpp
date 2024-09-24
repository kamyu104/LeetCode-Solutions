// Time:  O(n)
// Space: O(1)

// linked list
class Solution {
public:
	vector<int> toArray(Node *node){
        for (; node->prev; node = node->prev);
        vector<int> result;
        for (; node; node = node->next) {
            result.emplace_back(node->val);
        }
        return result;
    }
};
