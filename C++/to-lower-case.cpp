// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string toLowerCase(string str) {
        string result;
        for (const auto c : str) {
            if ('A' <= c && c <= 'Z') {
                result.push_back('a' + c - 'A');
            } else {
                result.push_back(c);
            }
        }
        return result;
    }
};
