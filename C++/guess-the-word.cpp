// Time:  O(n^2)
// Space: O(n)

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        for (int i = 0, n = 0; i < 10 && n < 6; ++i) {
            unordered_map<string, int> count;
            for (const auto& w1 : wordlist) {
                for (const auto& w2 : wordlist) {
                    if (match(w1, w2) == 0) {
                        ++count[w1];
                    }
                }
            }
            string guess;
            for (const auto& w : wordlist) {
                if (guess.empty() ||
                    count[w] < count[guess]) {
                    guess = w;
                }
            }
            n = master.guess(guess);
            vector<string> new_wordlist;
            for (const auto& w : wordlist) {
                if (match(w, guess) == n) {
                    new_wordlist.emplace_back(w);
                }
            }
            wordlist = new_wordlist;
        }
    }

private:
    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < a.length(); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};
