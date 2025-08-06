// Time:  O(n)
// Space: O(n)

// backward simulation, doubly linked list
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        vector<int> left(size(s));
        iota(begin(left), end(left), -1);
        vector<int> right(size(s));
        iota(begin(right), end(right), 1);
        auto cnt = static_cast<int64_t>(size(s) + 1) * size(s) / 2;
        if (cnt < k) {
            return -1;
        }
        int t = size(order) - 1;
        for (; t >= 0; --t) {
            const auto& i = order[t];
            const auto& l = left[i];
            const auto& r = right[i];
            cnt -= static_cast<int64_t>(i - l) * (r - i);
            if (cnt < k) {
                break;
            }
            if (l >= 0) {
                right[l] = r;
            }
            if (r < size(left)) {
                left[r] = l;
            }
        }
        return t;
    }
};
