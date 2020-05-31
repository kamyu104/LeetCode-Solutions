// Time:  O(n * k)
// Space: O(2^k)

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<int> lookup;
        const int base = 1 << k;
        if (base > s.length()) {
            return false;
        }
        int num = 0;
        for (int i = 0; i < s.length(); ++i) {
            num = (num << 1) + (s[i] - '0');
            if (i >= k - 1) {
                lookup.emplace(num);
                num -= (s[i - k + 1] - '0') * (base >> 1);
            }
        }
        return lookup.size() == base;
    }
};

// Time:  O(n * k)
// Space: O(k * 2^k)
class Solution2 {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> lookup;
        const int base = 1 << k;
        if (base > s.length()) {
            return false;
        }
        for (int i = 0; i + k - 1 < s.length(); ++i) {
            lookup.emplace(s.substr(i, k));
        }
        return lookup.size() == base;
    }
};
