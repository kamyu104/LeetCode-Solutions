// Time:  O(n)
// Space: O(n)

// hash table, prefix sum
class Solution {
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

public:
    int longestBalanced(string s) {
        const auto& count1 = [&]() {
            int result = 0, cnt = 0;
            for (int i = 0; i < size(s); ++i) {
                ++cnt;
                if (i + 1 == size(s) || s[i + 1] != s[i]) {
                    result = max(result, cnt);
                    cnt = 0;
                }
            }
            return result;
        };

        const auto& count2 = [&](auto a, auto b) {
            int result = 0, cnt = 0;
            unordered_map<int, int> lookup = {{cnt, -1}};
            for (int i = 0; i < size(s); ++i) {
                if (s[i] == a) {
                    ++cnt;
                } else if (s[i] == b) {
                    --cnt;
                } else {
                    cnt = 0;
                    lookup = {{cnt, i}};
                    continue;
                }
                if (lookup.count(cnt)) {
                    result = max(result, i - lookup[cnt]);
                } else {
                    lookup[cnt] = i;
                }
            }
            return result;
        };
    
        const auto& count3 = [&]() {
            int result = 0, a = 0, b = 0;
            unordered_map<pair<int, int>, int, PairHash<int>> lookup = {{{a, b}, -1}};
            for (int i = 0; i < size(s); ++i) {
                if (s[i] == 'a') {
                    ++a;
                } else if (s[i] == 'b') {
                    ++b;
                } else {
                    --a;
                    --b;
                }
                if (lookup.count({a, b})) {
                    result = max(result, i - lookup[{a, b}]);
                } else {
                    lookup[{a, b}] = i;
                }
            }
            return result;
        };
        
        return max({count1(), 
                    count2('a', 'b'), count2('b', 'c'), count2('c', 'a'),
                    count3()});
    }
};
