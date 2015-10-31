// Time:  O(n)
// Space: O(10) = O(1)

// One pass solution.
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> s_map, g_map;
        int A = 0, B = 0;
        const int n = min(secret.length(), guess.length());
        for (int i = 0; i < n; ++i) {
            const char s = secret[i];
            const char g = guess[i];
            if (s == g) {
                ++A;
            } else {
                (s_map[g] > 0) ? --s_map[g], ++B : ++g_map[g];
                (g_map[s] > 0) ? --g_map[s], ++B : ++s_map[s]; 
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
