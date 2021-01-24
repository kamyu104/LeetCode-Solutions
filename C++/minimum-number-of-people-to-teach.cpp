// Time:  O(n * m^2)
// Space: O(n * m)

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        vector<unordered_set<int>> language_sets;
        for (const auto& language : languages) {
            language_sets.emplace_back(cbegin(language), cend(language));
        }
        unordered_set<int> candidates;
        for (const auto& f : friendships) {
            if (empty(intersect(language_sets[f[0] - 1], language_sets[f[1] - 1]))) {
                candidates.emplace(f[0] - 1);
                candidates.emplace(f[1] - 1);
            }
        }
        vector<int> count(n);
        for (const auto& i : candidates) {
            for (const auto& l : language_sets[i]) {
                ++count[l - 1];
            }
        }
        return size(candidates) - *max_element(cbegin(count), cend(count));
    }

private:
    unordered_set<int> intersect(const unordered_set<int>& a, const unordered_set<int>& b) {
        if (size(a) > size(b)) {
            return intersect(b, a);
        }
        unordered_set<int> result;
        for (const auto& x : a) {
            if (b.count(x)) {
                result.emplace(x);
            }
        }
        return result;
    }
};
