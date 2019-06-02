// Time:  O(m + n), m is the length of source
//                , n is the length of target
// Space: O(m)

// greedy solution
class Solution {
public:
    int shortestWay(string source, string target) {
        vector<vector<int>> lookup(source.size() + 1, vector<int>(26, -1));
        vector<int> find_char_next_pos(26, -1);
        for (int i = source.length() - 1; i >= 0; --i) {
            find_char_next_pos[source[i] - 'a'] = i + 1;
            lookup[i] = find_char_next_pos;
        }
        
        int result = 1, start = 0;
        for (const auto& c : target) {
            start = lookup[start][c - 'a'];
            if (start != -1) {
                continue;
            }
            ++result;
            start = lookup[0][c - 'a'];
            if (start == -1) {
                return -1;
            }
        }
        return result;
    }
};
