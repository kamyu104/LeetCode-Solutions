// Time:  O(n * b), n is the length of gene string, b is size of bank
// Space: O(b)

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string, bool> lookup;
        for (const auto& b : bank) {
            lookup.emplace(b, false);
        }

        queue<pair<string, int>> q;
        q.emplace(start, 0);
        while (!q.empty()) {
            string cur;
            int level;
            tie(cur, level) = q.front(); q.pop();

            if (cur == end) {
                return level;
            }

            for (int i = 0; i < cur.size(); ++i) {
                auto cur_copy = cur;
                for (const auto& c : {'A', 'T', 'C', 'G'}) {
                    if (cur_copy[i] == c) {
                        continue;
                    }
                    cur_copy[i] = c;
                    if (lookup.count(cur_copy) && lookup[cur_copy] == false) {
                        q.emplace(cur_copy, level + 1);
                        lookup[cur_copy] = true;
                    }
                }
            }
        }

        return -1;
    }
};
