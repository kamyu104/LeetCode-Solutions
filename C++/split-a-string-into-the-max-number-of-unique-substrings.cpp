// Time:  O(n * 2^(n - 1))
// Space: O(n)

class Solution {
public:
    int maxUniqueSplit(string s) {
        int result = 1;
        int total = 1 << (size(s) - 1);
        for (uint32_t mask = 0; mask < total; ++mask)  {
            if(__builtin_popcount(mask) < result) {
                continue;
            }
            unordered_set<string> lookup;
            string curr;
            bool unique = true;
            for (uint32_t i = 0, base = 1; i < size(s); ++i, base <<= 1) {
                curr.push_back(s[i]);
                if ((mask & base) || base == total) {
                    if (!lookup.emplace(curr).second) {
                        unique = false;
                        break;
                    }
                    curr.clear();
                }
            }
            if (!unique) {
                continue;
            }
            result = max(result, int(size(lookup)));
        }
        return result;
    }
};
