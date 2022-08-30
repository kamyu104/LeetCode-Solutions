// Time:  O(n * l), l = max(g for g in garbage) = O(10)
// Space: O(1)

// simulation
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const auto& find_lasts = [&]() {
            unordered_map<char, int> lookup;
            for (int i = size(garbage) - 1; i >= 0; --i) {
                for (const auto& c : garbage[i]) {
                    if (!lookup.count(c)) {
                        lookup[c] = i;
                        if (size(lookup) == 3) {
                            return lookup;
                        }
                    }
                }
            }
            return lookup;
        };
        vector<int> lasts;
        for (const auto& [_, v] : find_lasts()) {
            lasts.emplace_back(v);
        }
        sort(rbegin(lasts), rend(lasts));
        int result = 0;
        for (int i = 0, curr = 0; i < size(garbage); ++i) {
            for (; !empty(lasts) && lasts.back() == i; lasts.pop_back()) {
                result += curr;
            }
            if (i < size(travel)) {
                curr += travel[i];
            }
            result += size(garbage[i]);
        }
        return result;
    }
};

// Time:  O(n * l), l = max(g for g in garbage) = O(10)
// Space: O(1)
// simulation
class Solution2 {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int result = 0;
        for (const auto& t : "MPG") {
            int curr = 0;
            for (int i = 0; i < size(garbage); ++i) {
                const int cnt = count(cbegin(garbage[i]), cend(garbage[i]), t);
                if (cnt) {
                    result += curr + cnt;
                    curr = 0;
                }
                if (i < size(travel)) {
                    curr += travel[i];
                }
            }
        }
        return result;
    }
};
