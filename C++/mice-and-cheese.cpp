// Time:  O(n)
// Space: O(1)

// greedy, quick select
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        for (int i = 0; i < size(reward1); ++i) {
            reward1[i] -= reward2[i];
        }
        nth_element(begin(reward1), begin(reward1) + (k - 1), end(reward1), greater<int>());
        return accumulate(cbegin(reward1), cbegin(reward1) + k,
                          accumulate(cbegin(reward2), cend(reward2), 0));
    }
};
