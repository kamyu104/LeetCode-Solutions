// Time:  O(eloge + e * n), e = len(events)
// Space: O(e + n)

// simulation
class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        static const int l = size(string("id"));

        vector<int> result(numberOfUsers), lookup(numberOfUsers, 1);
        sort(begin(events), end(events), [](const auto& a, const auto& b) {
            return pair(stoi(a[1]), a[0] == "MESSAGE" ? 1 : 0) < pair(stoi(b[1]), b[0] == "MESSAGE" ? 1 : 0);
        });

        for (const auto& e : events) {
            if (e[0] == "OFFLINE") {
                lookup[stoi(e[2])] = stoi(e[1]) + 60;
                continue;
            }
            if (e[2] == "ALL") {
                for (int i = 0; i < size(result); ++i) {
                    ++result[i];
                }
            } else if (e[2] == "HERE") {
                for (int i = 0; i < size(result); ++i) {
                    if (lookup[i] <= stoi(e[1])) {
                        ++result[i];
                    }
                }
            } else {
                for (int i = 0, j = 0; i < size(e[2]); ++i) {
                    if (i + 1 == size(e[2]) || e[2][i + 1] == ' ') {
                        ++result[stoi(e[2].substr(j + l, i - (j + l) + 1))];
                        j = (i + 1) + 1;
                    }
                }
            }
        }
        return result;
    }
};
