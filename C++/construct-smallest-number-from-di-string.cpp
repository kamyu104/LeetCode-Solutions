// Time:  O(n)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    string smallestNumber(string pattern) {
        string result;
        for (int i = 0; i <= size(pattern); ++i) {
            if (!(i == size(pattern) || pattern[i] == 'I')) {
                continue;
            }
            const int start = size(result) + 1;
            for (int j = i + 1; j >= start; --j) {
                result.push_back('0' + j);
            }
        }
        return result;
    }
};
