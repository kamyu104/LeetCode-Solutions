// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        return accumulate(cbegin(source), cend(source), 0LL) == accumulate(cbegin(target), cend(target), 0LL);
    }
};
