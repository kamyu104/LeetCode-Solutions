// Time:  O(n)
// Space: O(1)

// counting sort
class Solution {
public:
    string sortVowels(string s) {
        const auto& inplace_counting_sort = [](vector<int> *nums, bool is_reverse) {
            if (empty(*nums)) {
                return;
            }
            const int max_num = *max_element(cbegin(*nums), cend(*nums));
            vector<int> count(max_num + 1);
            for (const auto& num : *nums) {
                ++count[num];
            }
            for (int i = 1; i < size(count); ++i) {
                count[i] += count[i - 1];
            }
            for (int i = size(*nums) - 1; i >= 0; --i) {  // inplace but unstable sort
                while ((*nums)[i] >= 0) {
                    --count[(*nums)[i]];
                    const int j = count[(*nums)[i]];
                    tie((*nums)[i], (*nums)[j]) = pair((*nums)[j], ~(*nums)[i]);
                }
            }
            for (auto& num : *nums) {
                num = ~num;  // restore values
            }
            if (is_reverse) {  // unstable sort
                reverse(begin(*nums), end(*nums));
            }
        };
    
        static const string VOWELS = "AEIOUaeiou";
        unordered_map<char, int> LOOKUP;
        for (int i = 0; i < size(VOWELS); ++i) {
            LOOKUP[VOWELS[i]] = i;
        }
        vector<int> vowels;
        for (const auto& x : s) {
            if (LOOKUP.count(x)) {
                vowels.push_back(LOOKUP[x]);
            }
        }
        inplace_counting_sort(&vowels, true);
        string result;
        for (const auto& x : s) {
            if (LOOKUP.count(x)) {
                result.push_back(VOWELS[vowels.back()]);
                vowels.pop_back();
            } else {
                result.push_back(x);
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort
class Solution2 {
public:
    string sortVowels(string s) {
        static const string VOWELS = "AEIOUaeiou";
        static const unordered_set<char> LOOKUP(cbegin(VOWELS), cend(VOWELS));
        string vowels;
        for (const auto& x : s) {
            if (LOOKUP.count(x)) {
                vowels.push_back(x);
            }
        }
        sort(rbegin(vowels), rend(vowels));
        string result;
        for (const auto& x : s) {
            if (LOOKUP.count(x)) {
                result.push_back(vowels.back());
                vowels.pop_back();
            } else {
                result.push_back(x);
            }
        }
        return result;
    }
};
