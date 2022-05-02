// Time:  O(n)
// Space: O(26)

// combinatorics
class Solution {
public:
    long long appealSum(string s) {
        vector<int> lookup(26, -1);
        int64_t result = 0;
        for (int i = 0; i < size(s); ++i) {
            result += (i - lookup[s[i] - 'a']) * (size(s) - i);
            lookup[s[i] - 'a'] = i;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(26)
// counting
class Solution2 {
public:
    long long appealSum(string s) {
        vector<int> lookup(26, -1);
        int64_t result = 0, cnt = 0;
        for (int i = 0; i < size(s); ++i) {
            cnt += i - lookup[s[i] - 'a'];
            lookup[s[i] - 'a'] = i;
            result += cnt;
        }
        return result;
    }
};
