// Time:  O(h + v), h = len(hBars), v = len(vBars)
// Space: O(h + v)

// array, hash table
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        const auto& max_gap = [&](const auto& arr) {
            int result = 1;
            unordered_set<int> lookup(cbegin(arr), cend(arr));
            while (!empty(lookup)) {
                const int x = *begin(lookup);
                int left = x;
                for (; lookup.count(left - 1); --left);
                int right = x;
                for (; lookup.count(right + 1); ++right);
                for (int i = left; i <= right; ++i) {
                    lookup.erase(i);
                }
                result = max(result, (right - left + 1) + 1);
            }
            return result;
        };

        const int l = min(max_gap(hBars), max_gap(vBars));
        return l * l;
    }
};

// Time:  O(hlogh + vlogv), h = len(hBars), v = len(vBars)
// Space: O(1)
// array, sort
class Solution2 {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        const auto& max_gap = [&](auto& arr) {
            sort(begin(arr), end(arr));
            int result = 1;
            for (int i = 0, l = 1; i < size(arr); ++i) {
                result = max(result, ++l);
                if (i + 1 < size(arr) && arr[i + 1] != arr[i] + 1) {
                    l = 1;
                }
            }
            return result;
        };

        const int l = min(max_gap(hBars), max_gap(vBars));
        return l * l;
    }
};
