// Time:  O(26 * n)
// Space: O(n)

// hash table
class Solution {
public:
    long long countMagicalPairs(string s) {
        vector<int> nxt(size(s), size(s)), lookup1(26, size(s));
        for (int i = size(s) - 1; i >= 0; --i) {
            nxt[i] = lookup1[s[i] - 'a'];
            lookup1[s[i] - 'a'] = i;
        }
        vector<int> right;
        for (int i = 0; i < size(s); ++i) {
            if (lookup1[s[i] - 'a'] == i) {
                right.emplace_back(i);
            }
        }
        int64_t result = 0;
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
                result += static_cast<int64_t>(left[d] - (d + 1 < size(left) ? left[d + 1] : -1)) * ((d + 1 < size(right) ? right[d + 1] : size(s)) - right[d]);
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
    long long countMagicalPairs(string s) {
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
        int64_t result = 0;
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
                result += static_cast<int64_t>(arr[j] - (j + 1 < size(arr) ? arr[j + 1] : -1)) * right[i + 1][j];
            }
        }
        return result;
    }
};
