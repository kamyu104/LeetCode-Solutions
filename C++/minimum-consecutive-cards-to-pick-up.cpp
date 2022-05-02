// Time:  O(n)
// Space: O(n)

// hash table
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        static const int INF = numeric_limits<int>::max();
        unordered_map<int, int> lookup;
        int result = INF;
        for (int i = 0; i < size(cards); ++i) {
            if (lookup.count(cards[i])) {
                result = min(result, i - lookup[cards[i]] + 1);
            }
            lookup[cards[i]] = i;
        }
        return result != INF ? result : -1;
    }
};
