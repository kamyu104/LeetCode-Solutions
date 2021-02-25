// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<string> sortFeatures(vector<string>& features, vector<string>& responses) {
        unordered_set<string> features_set(cbegin(features), cend(features));
        unordered_map<string, int> order;
        for (int i = 0; i < size(features); ++i) {
            order[features[i]] = i;
        }
        unordered_map<string, int> freq;
        for (const auto&r : responses) {
            const auto& words = split(r, ' ');
            unordered_set<string> words_set(cbegin(words), cend(words));
            for (const auto& word : words_set) {
                if (features_set.count(word)) {
                    ++freq[word];
                }
            }
        }
        sort(begin(features), end(features),
             [&freq, &order](const auto& a, const auto& b) {
                 return pair(-freq[a], order[a]) < pair(-freq[b], order[b]);
             });
        return features;
    }

private:
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            if (!empty(token)) {
                tokens.emplace_back(token);
            }
        }
        return tokens;
    }
};
