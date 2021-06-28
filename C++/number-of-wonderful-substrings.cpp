// Time:  O(n)
// Space: O(2^10)

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        static const int ALPHABET_SIZE = 10;
        vector<int> count(pow(2, ALPHABET_SIZE));
        count[0] = 1;
        long long result = 0;
        int curr = 0;
        for (const auto& c : word) {
            curr ^= 1 << (c - 'a');
            result += count[curr];
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                result += count[curr ^ (1 << i)];
            }
            ++count[curr];
        }
        return result;
    }
};
