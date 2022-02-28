// Time:  O(n * p)
// Space: O(1)

// string
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        return count_if(cbegin(words), cend(words),
                        [&pref](const auto& x) {
                            return x.compare(0, size(pref), pref) == 0;
                        });
    }
};
