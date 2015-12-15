// Time:  O(nlogn) ~ O(n^2)
// Space: O(n)

// Sorting + Pruning + Bit Manipulation
class Solution {
public:
    int maxProduct(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) { return a.length() > b.length(); });
        vector<int> bits(words.size());
        for (int i = 0; i < words.size(); ++i) {
            for (const auto& c : words[i]) {
                bits[i] |= (1 << (c - 'a'));
            }
        }
        int max_product = 0;
        for (int i = 0; i + 1 < words.size() && pow(words[i].length(), 2) > max_product; ++i) {
            for (int j = i + 1; j < words.size() && words[i].length() * words[j].length() > max_product; ++j) {
                if (!(bits[i] & bits[j])) {
                    max_product = words[i].length() * words[j].length();
                }
            }
        }
        return max_product;
    }
};
