// Time:  ctor: O(n), shortest: O(a + b), a, b is occurences of word1, word2
// Space: O(n)

class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); ++i) {
            wordIndex[words[i]].emplace_back(i);
        }
    }

    int shortest(string word1, string word2) {
        const vector<int>& indexes1 = wordIndex[word1];
        const vector<int>& indexes2 = wordIndex[word2];

        int i = 0, j = 0, dist = INT_MAX;
        while (i < indexes1.size() && j < indexes2.size()) {
            dist = min(dist, abs(indexes1[i] - indexes2[j]));
            indexes1[i] < indexes2[j] ? ++i : ++j;
        }
        return dist;
    }

private:
    unordered_map<string, vector<int>> wordIndex;
};
