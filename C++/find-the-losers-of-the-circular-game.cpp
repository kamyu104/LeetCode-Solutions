// Time:  O(n)
// Space: O(n)

// hash table, simulation
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> lookup(n);
        for (int i = 0, idx = 0; i < n; ++i) {
            if (lookup[idx]) {
                break;
            }
            lookup[idx] = true;
            idx = (idx + (i + 1) * k) % n;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!lookup[i]) {
                result.emplace_back(i + 1);
            }
        }
        return result;
    }
};
