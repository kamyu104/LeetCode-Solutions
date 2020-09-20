// Time:  O(n * 2^(n - 1))
// Space: O(n)

class Solution {
public:
    int maxUniqueSplit(string s) {
        int result = 1;
        int total = 1 << (size(s) - 1);
        for (uint32_t mask = 0; mask < total;)  {
            if(__builtin_popcount(mask) < result) {
                ++mask;
                continue;
            }
            unordered_set<string> lookup;
            string curr;
            bool unique = true;
            for (uint32_t i = 0, base = total / 2; i < size(s); ++i, base >>= 1) {
                curr.push_back(s[i]);
                if ((mask & base) || base == 0) {
                    if (!lookup.emplace(curr).second) {
                        unique = false;
                        mask = base ? (mask | (base - 1)) + 1 : mask + 1;  // pruning, try next mask without base
                        break;
                    }
                    curr.clear();
                }
            }
            if (!unique) {
                continue;
            }
            result = max(result, int(size(lookup)));
            ++mask;
        }
        return result;
    }
};
