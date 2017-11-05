// Time:  O(n), n is the length of the source
// Space: O(k), k is the max length of a line

class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool in_block = false;
        vector<string> result;
        string newline;
        for (const auto& line : source) {
            for (int i = 0; i < line.length(); ++i) {
                if (!in_block && i + 1 < line.length() && line.substr(i, 2) == "/*") {
                    in_block = true;
                    ++i;
                } else if (in_block && i + 1 < line.length() && line.substr(i, 2) == "*/") {
                    in_block = false;
                    ++i;
                } else if (!in_block && i + 1 < line.length() && line.substr(i, 2) == "//") {
                    break;
                } else if (!in_block) {
                    newline.push_back(line[i]);
                }
            }
            if (!in_block && !newline.empty()) {
                result.emplace_back(move(newline));
            }
        }
        return result;
    }
};
