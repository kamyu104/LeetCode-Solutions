// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        unordered_map<int, int> lookup;
        vector<int> prefix = {0};
        int result = numeric_limits<int>::min();
        for (int i = 0; i < size(flowers); ++i) {
            prefix.emplace_back(flowers[i] > 0 ? prefix.back() + flowers[i] : prefix.back());
            if (!lookup.count(flowers[i])) {
                lookup[flowers[i]] = i;
                continue;
            }
            result = max(result, (flowers[i] < 0) ? 2 * flowers[i] + prefix[i + 1] - prefix[lookup[flowers[i]]] : prefix[i + 1] - prefix[lookup[flowers[i]]]);
        }
        return result;
    }
};
