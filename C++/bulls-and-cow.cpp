// Time:  O(n)
// Space: O(10) = O(1)

// Two pass solution.
class Solution {
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
