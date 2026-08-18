// Time:  O(n)
// Space: O(n)

// prefix sum, greedy
class Solution {
public:
    int maximumGap(string skill, string station) {        
        vector<int> right(size(skill));
        for (int i = size(skill) - 1, j = size(station) - 1; i >= 0; --i) {
            for (; station[j] != skill[i]; --j);
            right[i] = j--;
        }
        int result = 0;
        for (int i = 0, j = 0; i + 1 < size(skill); ++i) {
            for (; station[j] != skill[i]; ++j);
            result = max(result, right[i + 1] - j++);
        }  
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// prefix sum, greedy
class Solution2 {
public:
    int maximumGap(string skill, string station) {
        vector<int> left(size(skill));
        for (int i = 0, j = 0; i < size(skill); ++i) {
            for (; station[j] != skill[i]; ++j);
            left[i] = j++;
        }  
        vector<int> right(size(skill));
        for (int i = size(skill) - 1, j = size(station) - 1; i >= 0; --i) {
            for (; station[j] != skill[i]; --j);
            right[i] = j--;
        }
        int result = 0;
        for (int i = 0; i + 1 < size(skill); ++i) {
            result = max(result, right[i + 1] - left[i]);
        }
        return result;
    }
};
