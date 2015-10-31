// Time:  O(n)
// Space: O(10) = O(1)

// One pass solution.
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> lookup, lookup_B;
        int A = 0, B = 0;
        for (const auto& s : secret) {
            ++lookup[s];
        }
        for (int i = 0; i < secret.length() && i < guess.length(); ++i) {
            if (lookup[guess[i]]) {
                --lookup[guess[i]];
                if (secret[i] == guess[i]) {
                    ++A;
                } else {
                    ++lookup_B[guess[i]];
                    ++B;
                }
            } else if (lookup_B[guess[i]] && secret[i] == guess[i]) {
                --lookup_B[guess[i]];
                --B, ++A;
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
        for (int i = 0; i < secret.length() && i < guess.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++A, --B;
            }
        }
        return to_string(A).append("A").append(to_string(B).append("B"));
    }
};
