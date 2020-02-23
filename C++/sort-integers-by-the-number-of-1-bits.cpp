// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(begin(arr), end(arr),
             [](const auto& a, const auto& b) {
                 return make_pair(__builtin_popcount(a), a) <
                        make_pair(__builtin_popcount(b), b);
             });
        return arr;
    }
};
