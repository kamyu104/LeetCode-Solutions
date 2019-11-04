// Time:  O(n)
// Space: O(k)

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        int result = 0, i = 0;
        unordered_set<int> lookup;
        for (int j = 0; j < S.length(); ++j) {
            while (lookup.count(S[j])) {
                lookup.erase(S[i]);
                ++i;
            }
            lookup.emplace(S[j]);
            result += int(j - i + 1 >= K);
        }
        return result;
    }
};
