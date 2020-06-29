// Time:  O(n)
// Space: O(k)

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        if (arr.size() % 2) {
            return false;
        }
        unordered_map<int, int> count;
        for (const auto& i : arr) {
            ++count[(i % k + k) % k];
        }
        for (int i = 0; i < k; ++i) {
            if ((!i && count[i] % 2) ||
                (i && count[i] != count[k - i])) {
                    return false;
            }
        }
        return true;
    }
};
