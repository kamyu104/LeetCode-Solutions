// Time:  O(n)
// Space: O(w)

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.cbegin(), wordlist.cend());
        unordered_map<string, string> caps, vows;
        for (const auto& word : wordlist) {
            const auto& lower = tolow(word);
            caps.emplace(lower, word);
            vows.emplace(todev(lower), word);
        }

        for (auto& query : queries) {
            if (words.count(query)) {
                continue;
            }
            const auto& lower = tolow(query);
            const auto& devow = todev(lower);
            if (caps.count(lower)) {
                query = caps[lower];
            } else if (vows.count(devow)) {
                query = vows[devow];
            } else {
                query = "";
            }
        }
        return queries;
    }

private:
    string tolow(string word) {
        for (auto& c: word) {
            c = tolower(c);
        }
        return word;
    }

    string todev(string word) {
        static unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        for (auto& c: word) {
            if (vowels.count(c)) {
                c = '*';
            }
        }
        return word;
    }
};
