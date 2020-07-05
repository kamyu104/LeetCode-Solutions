// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        return max(!left.empty() ? *max_element(cbegin(left), cend(left)) : 0,
                   !right.empty() ? n - *min_element(cbegin(right), cend(right)) : 0);
    }
};
