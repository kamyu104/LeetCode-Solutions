// Time:  O(n * m), m is the number of targets
// Space: O(n)

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, string>> bucket(S.size());
        for (auto i = 0; i < indexes.size(); ++i)  {
            if (S.find(sources[i], indexes[i]) == indexes[i]) {
                bucket[indexes[i]] = {sources[i].size(), targets[i]};
            }
        }
        for (int i = S.size() - 1; i >= 0; --i) {
            S.replace(i, bucket[i].first, bucket[i].second);
        }
        return S;
    }
};
