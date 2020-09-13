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
        vector<vector<int>> H(size(wordlist), vector<int>(size(wordlist)));
        for (int i = 0; i < size(wordlist); ++i) {
            for (int j = 0; j < size(wordlist); ++j) {
                H[i][j] = match(wordlist[i], wordlist[j]);
            }
        }

        vector<int> possible(size(wordlist));
        iota(begin(possible), end(possible), 0);
        int n = 0;
        while (n < 6) {
            auto guess = solve(H, possible);
            n = master.guess(wordlist[guess]);
            vector<int> new_possible;
            for (const auto& j : possible) {
                if (H[guess][j] == n) {
                    new_possible.emplace_back(j);
                }
            }
            possible = move(new_possible);
        }
    }

private:
    int solve(const vector<vector<int>>& H,
              const vector<int>& possible) {

        int min_max_size = size(possible);
        int best_guess = -1; 
        for (const auto& guess : possible) {
            vector<vector<int>> groups(7);
            for (const auto& j : possible) {
                if (j != guess) {
                    groups[H[guess][j]].emplace_back(j);
                }
            }
            int max_group_i = 0;
            for (int i = 0; i < size(groups); ++i) {
                if (size(groups[i]) > size(groups[max_group_i])) {
                    max_group_i = i;
                }
            }
            if (size(groups[max_group_i]) < min_max_size) {
                min_max_size = size(groups[max_group_i]);
                best_guess = guess;
            }
        }
        return best_guess;
    }

    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};

// Time:  O(n^2)
// Space: O(n)
class Solution2 {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        vector<vector<int>> H(size(wordlist), vector<int>(size(wordlist)));
        for (int i = 0; i < size(wordlist); ++i) {
            for (int j = 0; j < size(wordlist); ++j) {
                H[i][j] = match(wordlist[i], wordlist[j]);
            }
        }

        vector<int> possible(size(wordlist));
        iota(begin(possible), end(possible), 0);
        int n = 0;
        while (n < 6) {
            auto guess = solve(H, possible);
            n = master.guess(wordlist[guess]);
            vector<int> new_possible;
            for (const auto& j : possible) {
                if (H[guess][j] == n) {
                    new_possible.emplace_back(j);
                }
            }
            possible = move(new_possible);
        }
    }

private:
    int solve(const vector<vector<int>>& H,
              const vector<int>& possible) {

        int min_max_size = size(possible);
        int best_guess = -1; 
        for (const auto& guess : possible) {
            vector<vector<int>> groups(7);
            for (const auto& j : possible) {
                if (j != guess) {
                    groups[H[guess][j]].emplace_back(j);
                }
            }
            int max_group_i = 0;
            if (size(groups[max_group_i]) < min_max_size) {
                min_max_size = size(groups[max_group_i]);
                best_guess = guess;
            }
        }
        return best_guess;
    }

    int match(const string& a, const string& b) {
        int matches = 0;
        for (int i = 0; i < size(a); ++i) {
            if (a[i] == b[i]) {
                ++matches;
            }
        }
        return matches;
    }
};
