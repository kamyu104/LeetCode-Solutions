// Time:  O(n + m), m is the number of targets
// Space: O(n)

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<pair<int, string>> bucket(S.size());
        for (int i = 0; i < indexes.size(); ++i)  {
            if (S.find(sources[i], indexes[i]) == indexes[i]) {
                bucket[indexes[i]] = {sources[i].size(), targets[i]};
            }
        }
        string result;
        int last = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (bucket[i].first) {
                result += bucket[i].second;
                last = i + bucket[i].first;
            } else if (i >= last) {
                result.push_back(S[i]);
            }
        }
        return result;
    }
};
