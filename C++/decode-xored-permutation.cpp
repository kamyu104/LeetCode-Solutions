// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int curr = 0;
        for (int i = 1; i <= size(encoded) + 1; ++i) {
            curr ^= i;
            if (i < size(encoded) && i % 2 == 1) {
                curr ^= encoded[i];
            }
        }
        vector<int> result = {curr};
        for (const auto& x: encoded) {
            result.emplace_back(result.back() ^ x);
        }
        return result;
    }
};
