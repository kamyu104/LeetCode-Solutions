// Time:  O(n + klogk)
// Space: O(k)

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        unordered_map<int, int> count;
        for (const auto& x : A) {
            ++count[x];
        }
        vector<int> keys;
        for (const auto& kvp : count) {
            keys.emplace_back(kvp.first);
        }
        sort(keys.begin(), keys.end(),
             [](int i, int j) {
                 return abs(i) < abs(j);
             });
        for (const auto& x : keys) {
            if (count[x] > count[2 * x]) {
                return false;
            }
            count[2 * x] -= count[x];
        }
        return true;
    }
};
