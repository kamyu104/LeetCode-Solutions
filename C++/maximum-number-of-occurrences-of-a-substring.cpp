// Time:  O(n)
// Space: O(n)

// rolling hash (Rabin-Karp Algorithm)
class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        static const uint64_t M = 1000000007;
        static const uint64_t p = 113; 
        uint64_t power = pow(p, minSize - 1, M), rolling_hash = 0;

        int left = 0;
        unordered_map<int, int> lookup;
        unordered_map<char, int> count;
        for (int right = 0; right < s.length(); ++right) {
            ++count[s[right]];
            if (right - left + 1 > minSize) {
                --count[s[left]];
                rolling_hash = (rolling_hash + M - (s[left] * power) % M) % M;
                if (!count[s[left]]) {
                    count.erase(s[left]);
                }
                ++left;
            }
            rolling_hash = ((rolling_hash * p) % M + s[right]) % M;
            if (right - left + 1 == minSize && count.size() <= maxLetters) {
                ++lookup[rolling_hash];
            }
        }
        return lookup.empty()
               ? 0 
               : max_element(lookup.cbegin(), lookup.cend(), 
                             [](const auto& a, const auto& b) {
                                 return a.second < b.second;
                             })->second;
    }

private:
    uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
        a %= m;
        uint64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }
};

// Time:  O(m * n), m = 26
// Space: O(m * n)
class Solution2 {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> lookup;
        for (int right = minSize - 1; right < s.length(); ++right) {
            const auto& word = s.substr(right - minSize + 1, minSize);
            if (lookup.count(word)) {
                ++lookup[word];
            } else if (unique_count(word) <= maxLetters) {
                lookup[word] = 1;
            }
        }
        return lookup.empty()
               ? 0
               : max_element(lookup.cbegin(), lookup.cend(), 
                             [](const auto& a, const auto& b) {
                                 return a.second < b.second;
                             })->second;
    }

private:
    int unique_count(const string& word) {
        unordered_set<char> lookup;
        for (const auto& c : word) {
            lookup.emplace(c);
        }
        return lookup.size();
    }
};
