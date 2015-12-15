// Time:  O(n) ~ O(n^2)
// Space: O(n)

// Counting Sort + Pruning + Bit Manipulation
class Solution {
public:
    int maxProduct(vector<string>& words) {
        words = counting_sort(words);
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

    vector<string> counting_sort(const vector<string>& words) {
        const int k = 1000;  // k is max length of words in the dictionary
        vector<vector<string>> buckets(k);
        for (const auto& word : words) {
            buckets[word.length()].emplace_back(word);
        }
        vector<string> res;
        for (int i = k - 1; i >= 0; --i) {
            if (!buckets[i].empty()) {
                move(buckets[i].begin(), buckets[i].end(), back_inserter(res));
            }
        }
        return res;
    }
};

// Time:  O(nlogn) ~ O(n^2)
// Space: O(n)
// Sorting + Pruning + Bit Manipulation
class Solution2 {
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
