// Time:  O(1)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    int fillCups(vector<int>& amount) {
        return max(*max_element(cbegin(amount), cend(amount)),
                   (accumulate(cbegin(amount), cend(amount), 0) + 1) / 2);
    }
};
