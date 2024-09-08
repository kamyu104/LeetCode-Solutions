// Time:  O(nlogn + nlogr) = O(nlogr)
// Space: O(1)

// binary search, greedy
class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        const auto& binary_search_right = [](int left, int right, const auto& check) {
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (!check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        };

        sort(begin(start), end(start));
        return binary_search_right(1, (start.back() + d) - start.front(), [&](int x) {
            int64_t curr = start[0];
            for (int i = 1; i < size(start); ++i) {
                curr = max(curr + x, static_cast<int64_t>(start[i]));
                if (curr > start[i] + d) {
                    return false;
                }
            }
            return true;
        });
    }
};
