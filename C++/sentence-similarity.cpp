// Time:  O(n + p)
// Space: O(p)

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) {
            return false;
        }
        unordered_set<pair<string, string>, PairHash<string>> lookup;
        for (const auto& pair : pairs) {
            lookup.emplace(pair.first, pair.second);
            lookup.emplace(pair.second, pair.first);
        }
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] != words2[i] && 
                !lookup.count(make_pair(words1[i], words2[i]))) {
                return false;
            }
        }
        return true;
    }

private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
};
