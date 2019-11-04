// Time:  O((m + n)logn), m is the number of queries, n is the number of words
// Space: O(n)

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> words_freq;
        for (const auto& word : words) {
            words_freq.emplace_back(f(word));
        }
        sort(words_freq.begin(), words_freq.end());
        vector<int> result;
        for (const auto& query : queries) {
            const auto& it = upper_bound(words_freq.cbegin(), words_freq.cend(), f(query));
            result.emplace_back(distance(it, words_freq.cend()));
        }
        return result;
    }

private:
    int f(const string& word) {
        const auto& smallest = *min_element(word.cbegin(), word.cend());
        return count(word.cbegin(), word.cend(), smallest);
    }
};
