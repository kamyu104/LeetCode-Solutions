// Time:  O(n)
// Space: O(1)

// brute force, linear search (binary search doesn't work)
class Solution {
public:
    vector<string> splitMessage(string message, int limit) {
        int cnt = 1, l = 1;
        for (int total = size(message) + 1, base = 1; 3 + l * 2 < limit && total + (3 + l) * cnt > limit * cnt;) {
            ++cnt;
            if (cnt == 10 * base) {
                ++l;
                base *= 10;
            }
            total += l;
        }
        if (3 + l * 2 >= limit) {
            return {};
        }
        vector<string> result;
        for (int i = 0, j = 0; i < cnt; ++i) {
            const int l = limit - (3 + size(to_string(i + 1)) + size(to_string(cnt)));
            result.emplace_back(message.substr(j, l) + '<' + to_string(i + 1) + '/' + to_string(cnt) + '>');
            j += l;
        }
        return result;
    }
};
