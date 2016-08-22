// Time:  O(n)
// Space: O(d), d is the max depth of the paths

class Solution {
public:
    int lengthLongestPath(string input) {
        input.push_back('\n');

        size_t max_len = 0;
        unordered_map<int, int> path_len;
        path_len[0] = 0;

        for (auto i = input.find("\n"), prev_i = 0ul;
             i != string::npos;
             prev_i = i + 1, i = input.find("\n", i + 1)) {

            const auto line = input.substr(prev_i, i - prev_i);
            const auto name = line.substr(line.find_first_not_of("\t"));
            const auto depth = line.length() - name.length();

            if (name.find('.') != string::npos) {
                max_len = max(max_len, path_len[depth] + name.length());
            } else {
                path_len[depth + 1] = path_len[depth] + name.length() + 1;
            }
        }
        return max_len;
    }
};
