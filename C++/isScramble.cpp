// Time Complexity: O(n^4),  due to enumeration of n, i, j, k in (f[n][i][j] and k)
// Space Complexity: O(n^3), due to hash of f[n][i][j]

class Solution {
    public:
        bool isScramble(string s1, string s2) {
            if(s1.size() != s2.size())
                return false;
            return isScramble(s1.size(), s1.begin(), s2.begin());
        }
    private:
        typedef string::const_iterator Iterator;
        map<tuple<int, Iterator, Iterator>, bool> hash;

        bool isScramble(int n, Iterator s1, Iterator s2) {
            // hash
            if( hash.find(make_tuple(n, s1, s2)) != hash.end()) return hash[make_tuple(n, s1, s2)];

            if(n == 1) return *s1 == *s2;

            // pruning
            int value1 = 0, value2=0;
            for (auto it1 = s1, it2 = s2; it1 != s1 + n; ++it1, ++it2) {
                value1 += (*it1-'a');
                value2 += (*it2-'a');
            }
            if (value1 != value2)
                return hash[make_tuple(n, s1, s2)] = false; 

            // recursive
            for(int k = 1; k < n; ++k) {
                if((isScramble(k, s1, s2) && isScramble(n - k, s1 + k, s2 + k))
                        || (isScramble(k, s1, s2 + n - k) && isScramble(n - k, s1 + k, s2)) ) {
                    return hash[make_tuple(n, s1, s2)] = true;
                }
            }

            return hash[make_tuple(n, s1, s2)] = false;
        }

};
