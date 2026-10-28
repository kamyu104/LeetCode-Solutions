// Time:  O(26 * n)
// Space: O(n)

// hash table
class Solution {
public:
    int countMagicalPairs(string s) {
        vector<int> nxt(size(s), size(s)), lookup1(26, size(s));
        for (int i = size(s) - 1; i >= 0; --i) {
            nxt[i] = lookup1[s[i] - 'a'];
            lookup1[s[i] - 'a'] = i;
        }
        vector<int> right;
        for (const auto& x : lookup1) {
            if (x != size(s)) {
                right.emplace_back(x);
            }
        }
        ranges::sort(right);
        int result = 0;
        vector<int> left, lookup2(26, -1);
        for (int j = 0; j + 1 < size(s); ++j) {
            if (lookup2[s[j] - 'a'] != -1) {
                left.erase(ranges::find(left, lookup2[s[j] - 'a']));
            }
            left.emplace(begin(left), j);
            lookup2[s[j] - 'a'] = j;
            right.erase(begin(right));
            if (nxt[j] != size(s)) {
                right.emplace(ranges::lower_bound(right, nxt[j]), nxt[j]);
            }
            for (int d = 0; d < min(size(left), size(right)); ++d) {
                result += (left[d] - (d + 1 < size(left) ? left[d + 1] : -1)) * ((d + 1 < size(right) ? right[d + 1] : size(s)) - right[d]);
            }
        }
        return result;
    }
};

// Time:  O(26 * n)
// Space: O(26 * n)
// prefix sum, hash table
class Solution2 {
public:
    int countMagicalPairs(string s) {
        vector<vector<int>> right(size(s));
        vector<char> order;
        vector<int> lookup(26, -1);
        for (int i = size(s) - 1; i >= 1; --i) {
            if (lookup[s[i] - 'a'] != -1) {
                order.erase(ranges::find(order, s[i]));
            }
            order.emplace(begin(order), s[i]);
            lookup[s[i] - 'a'] = i;
            vector<int> arr;
            arr.reserve(size(order));
            for (const auto& x : order) {
                arr.emplace_back(lookup[x - 'a']);
            }
            for (int j = 0; j < size(arr); ++j) {
                right[i].emplace_back((j + 1 < size(arr) ? arr[j + 1] : size(s)) - arr[j]);
            }
        }
        int result = 0;
        order.clear();
        lookup.assign(26, -1);
        for (int i = 0; i + 1 < size(s); ++i) {
            if (lookup[s[i] - 'a'] != -1) {
                order.erase(ranges::find(order, s[i]));
            }
            order.insert(begin(order), s[i]);
            lookup[s[i] - 'a'] = i;
            vector<int> arr;
            arr.reserve(size(order));
            for (const auto& x : order) {
                arr.emplace_back(lookup[x - 'a']);
            }
            for (int j = 0; j < min(size(arr), size(right[i + 1])); ++j) {
                result += (arr[j] - (j + 1 < size(arr) ? arr[j + 1] : -1)) * right[i + 1][j];
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force, bitmask
class Solution3 {
public:
    int countMagicalPairs(string s) {
        int result = 0;
        for (int j = 0; j + 1 < size(s); ++j) {
            vector<int> left;
            int mask = 0;
            for (int i = j; i >= 0; --i) {
                if (!(mask & (1 << (s[i] - 'a')))) {
                    mask |= 1 << (s[i] - 'a');
                    left.emplace_back(0);
                }
                ++left.back();
            }
            int right = 0, d = -1;
            mask = 0;
            for (int k = j + 1; k < size(s); ++k) {
                if (!(mask & (1 << (s[k] - 'a')))) {
                    if (0 <= d && d < size(left)) {
                        result += left[d] * right;
                    }
                    mask |= 1 << (s[k] - 'a');
                    right = 0;
                    ++d;
                }
                ++right;
            }
            if (d < size(left)) {
                result += left[d] * right;
            }
        }
        return result;
    }
};
