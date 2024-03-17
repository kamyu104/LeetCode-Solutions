// Time:  O(n + 26 * log(26))
// Space: O(26)

// greedy, counting sort, prefix sum
class Solution {
public:
    string minimizeStringValue(string s) {
        const auto& counting_sort = [](const auto& cnt) {
            vector<int> result(accumulate(cbegin(cnt), cend(cnt), 0));
            for (int i = 0, j = 0; i < size(cnt); ++i) {
                for (int _ = 0; _ < cnt[i]; ++_) {
                    result[j++] = i;
                }
            }
            return result;
        };

        const auto& fill = [&](const auto& cnt) {
            vector<int> result(26);
            vector<pair<int, int>> pairs(size(cnt));
            for (int i = 0; i < size(cnt); ++i) {
                pairs[i] = {cnt[i], i};
            }
            sort(begin(pairs), end(pairs));
            const int total = count(cbegin(s), cend(s), '?');
            int curr = 0, i = 0;
            for (; i + 1 < size(pairs); ++i) {
                if (curr + (pairs[i + 1].first - pairs[i].first) * (i + 1) > total) {
                    break;
                }
                curr += (pairs[i + 1].first - pairs[i].first) * (i + 1);
            }            
            const int q = (total - curr) / (i + 1);
            const int r = (total - curr) % (i + 1);
            for (int j = 0; j <= i; ++j) {
                result[pairs[j].second] = (pairs[i].first - pairs[j].first) + q;
            }
            vector<int> cnt2(26);
            for (int j = 0; j <= i; ++j) {
                ++cnt2[pairs[j].second];
            }
            const auto& idxs = counting_sort(cnt2);
            for (int _ = 0, j = 0; _ < r; ++_) {
                ++result[idxs[j++]];
            }
            return result;
        };

        vector<int> cnt(26);
        for (const auto& x : s) {
            if (x == '?') {
                continue;
            }
            ++cnt[x - 'a'];
        }
        const auto& idxs = counting_sort(fill(cnt));
        int i = 0;
        for (auto& x : s) {
            if (x != '?') {
                continue;
            }
            x = 'a' + idxs[i++];
        }
        return s;
    }
};

// Time:  O(n + n * log(26))
// Space: O(26)
// greedy, counting sort, heap
class Solution2 {
public:
    string minimizeStringValue(string s) {
        const auto& counting_sort = [](const auto& cnt) {
            vector<int> result(accumulate(cbegin(cnt), cend(cnt), 0));
            for (int i = 0, j = 0; i < size(cnt); ++i) {
                for (int _ = 0; _ < cnt[i]; ++_) {
                    result[j++] = i;
                }
            }
            return result;
        };

        vector<int> cnt(26);
        for (const auto& x : s) {
            if (x == '?') {
                continue;
            }
            ++cnt[x - 'a'];
        }
        vector<pair<int, int>> pairs(size(cnt));
        for (int i = 0; i < size(cnt); ++i) {
            pairs[i] = {cnt[i], i};
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap(cbegin(pairs), cend(pairs));
        vector<int> cnt2(26);
        const int total = count(cbegin(s), cend(s), '?');
        for (int _ = 0; _ < total; ++_) {
            const auto [c, i] = min_heap.top(); min_heap.pop();
            ++cnt2[i];
            min_heap.emplace(c + 1, i);
        }
        const auto& idxs = counting_sort(cnt2);
        int i = 0;
        for (auto& x : s) {
            if (x != '?') {
                continue;
            }
            x = 'a' + idxs[i++];
        }
        return s;
    }
};

// Time:  O(n + n * 26)
// Space: O(26)
// greedy, counting sort
class Solution3 {
public:
    string minimizeStringValue(string s) {
        const auto& counting_sort = [](const auto& cnt) {
            vector<int> result(accumulate(cbegin(cnt), cend(cnt), 0));
            for (int i = 0, j = 0; i < size(cnt); ++i) {
                for (int _ = 0; _ < cnt[i]; ++_) {
                    result[j++] = i;
                }
            }
            return result;
        };

        vector<int> cnt(26);
        for (const auto& x : s) {
            if (x == '?') {
                continue;
            }
            ++cnt[x - 'a'];
        }
        vector<int> cnt2(26);
        const int total = count(cbegin(s), cend(s), '?');
        for (int _ = 0; _ < total; ++_) {
            int min_i = 0;
            for (int i = 0; i < size(cnt); ++i) {
                if (cnt[min_i] + cnt2[min_i] > cnt[i] + cnt2[i]) {
                    min_i = i;
                }
            }
            ++cnt2[min_i];
        }
        const auto& idxs = counting_sort(cnt2);
        int i = 0;
        for (auto& x : s) {
            if (x != '?') {
                continue;
            }
            x = 'a' + idxs[i++];
        }
        return s;
    }
};
