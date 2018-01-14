// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < S.length(); ++i) {
            lookup[S[i]] = i;
        }
        int first = 0, last = 0;
        vector<int> result;
        for (int i = 0; i < S.length(); ++i) {
            last = max(last, lookup[S[i]]);
            if (i == last) {
                result.emplace_back(i - first + 1);
                first = i + 1;
            }
        }
        return result;
    }
};
