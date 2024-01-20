// Time:  O(nlogn)
// Space: O(n)

// sort, line sweep, coordinate compression
class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        unordered_set<int> set_y(cbegin(y), cend(y));
        vector<int> sorted_set_y(cbegin(set_y), cend(set_y));
        sort(begin(sorted_set_y), end(sorted_set_y));
        unordered_map<int, int> val_to_idx;
        for (int i = 0; i < size(sorted_set_y); ++i) {
            val_to_idx[sorted_set_y[i]] = i;
        }
        vector<int> cnts(2 * size(val_to_idx) + 1);
        for (int i = 0; i + 1 < size(y); ++i) {
            // [y[i], y[i+1]) <=> [y[i], y[i+1]-0.5] <=> [2*y[i], 2*y[i+1]-1]
            const int left = 2 * val_to_idx[y[i]], right = 2 * val_to_idx[y[i + 1]] + (y[i] < y[i + 1] ? -1 : +1);
            ++cnts[min(left, right)];
            --cnts[max(left, right) + 1];
        }
        // [y[i], y[i]] <=> [2*y[i], 2*y[i]]
        ++cnts[2 * val_to_idx[y.back()]];
        --cnts[2 * val_to_idx[y.back()] + 1];
        int result = 0, cnt = 0;
        for (const auto& c : cnts) {
            cnt += c;
            result = max(result, cnt);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, line sweep
class Solution2 {
public:
    int maxIntersectionCount(vector<int>& y) {
        vector<pair<int, int>> events;
        for (int i = 0; i + 1 < size(y); ++i) {
            // [y[i], y[i+1]) <=> [y[i], y[i+1]-0.5] <=> [2*y[i], 2*y[i+1]-1]
            const int left = 2 * y[i], right = 2 * y[i + 1] + (y[i] < y[i + 1] ? -1 : +1);
            events.emplace_back(min(left, right), +1);
            events.emplace_back(max(left, right) + 1, -1);
        }
        // [y[i], y[i]] <=> [2*y[i], 2*y[i]]
        events.emplace_back(2 * y.back(), +1);
        events.emplace_back(2 * y.back() + 1, -1);
        sort(begin(events), end(events));
        int result = 0, cnt = 0;
        for (const auto& [_, c] : events) {
            cnt += c;
            result = max(result, cnt);
        }
        return result;
    }
};
