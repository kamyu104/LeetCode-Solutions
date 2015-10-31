// Time:  O(n)
// Space: O(10) = O(1)

// One pass solution.
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> s_lookup, g_lookup;
        int A = 0, B = 0;
        const int n = min(secret.length(), guess.length());
        for (int i = 0; i < n; ++i) {
            const char s = secret[i];
            const char g = guess[i];
            if (s == g) {
                ++A;
            } else {
                (s_lookup[g] > 0) ? --s_lookup[g], ++B : ++g_lookup[g];
                (g_lookup[s] > 0) ? --g_lookup[s], ++B : ++s_lookup[s]; 
             }
        }
        return to_string(A).append("A").append(to_string(B).append("B"));
    }
};

// Two pass solution.
class Solution2 {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> lookup;
        int A = 0, B = 0;
        for (const auto& s : secret) {
            ++lookup[s];
        }
        for (const auto& g : guess) {
            if (lookup[g]) {
                --lookup[g];
                ++B;
            }
        }
        const int n = min(secret.length(), guess.length());
        for (int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) {
                ++A, --B;
            }
        }
        return to_string(A).append("A").append(to_string(B).append("B"));
    }
};
