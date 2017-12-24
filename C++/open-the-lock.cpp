// Time:  O(k * n^k + d), n is the number of alphabets,
//                        k is the length of target,
//                        d is the size of deadends
// Space: O(k * n^k + d)

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        vector<string> q{"0000"};
        unordered_set<string> lookup{"0000"};
        int depth = 0;
        while (!q.empty()) {
            vector<string> next_q;
            for (const auto& node : q) {
                if (node == target) {
                    return depth;
                }
                if (dead.count(node)) {
                    continue;
                }
                for (int i = 0; i < 4; ++i) {
                    auto n = node[i] - '0';
                    for (const auto& d : {-1, 1}) {
                        auto nn = (n + d + 10) % 10;
                        auto neighbor = node;
                        neighbor[i] = '0' + nn;
                        if (!lookup.count(neighbor)) {
                            lookup.emplace(neighbor);
                            next_q.emplace_back(neighbor);
                        }
                    }
                }
            }
            swap(q, next_q);
            ++depth;
        }
        return -1;
    }
};
