// Time:  O(n * l)
// Space: O(n)

// freq table
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> cnt;
        string result;
        int mx = 0;
        for (int i = 0; i < size(messages); ++i) {
            cnt[senders[i]] += count(begin(messages[i]), end(messages[i]), ' ') + 1;
            if (cnt[senders[i]] > mx || (cnt[senders[i]] == mx && senders[i] > result)) {
                mx = cnt[senders[i]];
                result = senders[i];
            }
        }
        return result;
    }
};
