// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int fillCups(vector<int>& amount) {
        return max(*max_element(cbegin(amount), cend(amount)),
                   (accumulate(cbegin(amount), cend(amount), 0) + 1) / 2);
    }
};

// Time:  O(1)
// Space: O(1)
// constructive algorithms
class Solution2 {
public:
    int fillCups(vector<int>& amount) {
        const int mx = *max_element(cbegin(amount), cend(amount));
        const int total = accumulate(cbegin(amount), cend(amount), 0);
        return total - mx <= mx ? mx : (total + 1) / 2;
    }
};
