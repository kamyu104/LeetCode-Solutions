// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string s = "";
        for (auto& str : strs) {
            auto rev{str};
            reverse(rev.begin(), rev.end());
            s += max(str, rev);
        }
        string result = "a";
        for (auto i = 0, st = 0; i < strs.size(); st += strs[i++].size()) {
            auto rev{strs[i]}, body{s.substr(st + strs[i].length())};
            body += s.substr(0, st);
            reverse(rev.begin(), rev.end());
            for (const auto& p : {strs[i], rev}) {
                for (auto j = 0; j < strs[i].size(); ++j) {
                    if (p[j] >= result[0]) {
                        string tmp{p.substr(j)};
                        tmp += body;
                        tmp += p.substr(0, j);
                        result = max(result, tmp);
                    }
                }
            }
        }
        return result;
    }
};
