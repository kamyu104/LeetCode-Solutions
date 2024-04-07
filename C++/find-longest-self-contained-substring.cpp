// Time:  O(n + 26^3 * logn)
// Space: O(n)

// hash table, binary search
class Solution {
public:
    int maxSubstringLength(string s) {
        vector<vector<int>> idxs(26);
        for (int i = 0; i < size(s); ++i) {
            idxs[s[i] - 'a'].emplace_back(i);
        }
        const auto& check = [&](int left, int right) {
            for (const auto& x : idxs) {
                if (empty(x) || x.back() < left || x[0] > right || (left <= x[0] && x.back() <= right)) {
                    continue;
                }
                const int i = distance(cbegin(x), lower_bound(cbegin(x), cend(x), left));
                if (i != size(x) && x[i] <= right) {
                    return false;
                }
            }
            return true;
        };

        int result = -1;
        for (const auto& x : idxs) {
            if (empty(x)) {
                continue;
            }
            const int left = x[0];
            for (const auto& y : idxs) {
                if (empty(y)) {
                    continue;
                }
                const int right = y.back();
                if (left <= right && result < right - left + 1 && right - left + 1 != size(s) && check(left, right)) {
                    result = right - left + 1;
                }
            }
        }
        return result;
    }
};

// Time:  O(n + 26^3 * logn)
// Space: O(n)
// hash table, binary search
class Solution2 {
public:
    int maxSubstringLength(string s) {
        vector<vector<int>> idxs(26);
        for (int i = 0; i < size(s); ++i) {
            idxs[s[i] - 'a'].emplace_back(i);
        }
        const auto& check = [&](int left, int right) {
            for (const auto& x : idxs) {
                if (empty(x)) {
                    continue;
                }
                const int l = distance(cbegin(x), lower_bound(cbegin(x), cend(x), left));
                const int r = distance(cbegin(x), upper_bound(cbegin(x), cend(x), right)) - 1;
                if (!(r - l + 1 == size(x) || r - l + 1 == 0)) {
                    return false;
                }
            }
            return true;
        };

        int result = -1;
        for (const auto& x : idxs) {
            if (empty(x)) {
                continue;
            }
            const int left = x[0];
            for (const auto& y : idxs) {
                if (empty(y)) {
                    continue;
                }
                const int right = y.back();
                if (left <= right && right - left + 1 != size(s) && check(left, right)) {
                    result = max(result, right - left + 1);
                }
            }
        }
        return result;
    }
};

// Time:  O(26 * n)
// Space: O(n)
// freq table, two pointers
class Solution3 {
public:
    int maxSubstringLength(string s) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        const auto& update = [&](auto& cnt2, char x, int d, int& distinct, int& valid) {
            const int k = x - 'a';
            if (cnt2[k] == cnt[k]) {
                --valid;
            }
            if (cnt2[k] == 0) {
                ++distinct;
            }
            cnt2[k] += d;
            if (cnt2[k] == 0) {
                --distinct;
            }
            if (cnt2[k] == cnt[k]) {
                ++valid;
            }
         };

        const int total = accumulate(cbegin(cnt), cend(cnt), 0, [](const int accu, const int x) {
            return accu + (x != 0 ? 1 : 0);
        });
        int result = -1;
        for (int l = 1; l < total; ++l) {
            vector<int> cnt2(26);
            for (int right = 0, left = 0, distinct = 0, valid = 0; right < size(s); ++right) {
                update(cnt2, s[right], +1, distinct, valid);
                while (distinct == l + 1) {
                    update(cnt2, s[left++], -1, distinct, valid);
                }
                if (valid == l) {
                    result = max(result, right - left + 1);
                }
            }
        }
        return result;
    }
};

// Time:  O(26^2 * n)
// Space: O(26)
// hash table, brute force
class Solution5 {
public:
    int maxSubstringLength(string s) {
        vector<int> left(26, -1), right(26, -1);
        for (int i = 0; i < size(s); ++i) {
            const int x = s[i] - 'a';
            if (left[x] == -1) {
                left[x] = i;
            }
            right[x] = i;
        }
        const auto& check = [&](int l, int r) {
            for (int i = l; i <= r; ++i) {
                const int x = s[i] - 'a';
                if (!(l <= left[x] && right[x] <= r))  {
                    return false;
                }
            }
            return true;
        };

        int result = -1;
        for (const auto& l : left) {
            if (l == -1) {
                continue;
            }
            for (const auto& r : right) {
                if (r == -1) {
                    continue;
                }
                if (l <= r && result < r - l + 1 && r - l + 1 != size(s) && check(l, r)) {
                    result = r - l + 1;
                }
            }
        }
        return result;
    }
};
