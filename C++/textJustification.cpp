// LeetCode, Text Justification 
// Complexity:
//     O(n) time
//     O(1) space

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int L) {
	     vector<string> result;
	     const int n = words.size();
	     int begin = 0, len = 0;
	     for (int i = 0; i < n; ++i) {
	     	if (len + words[i].size() + (i - begin) > L) {
	            result.push_back(connect(words, begin, i - 1, len, L, false));
	            begin = i;
	            len = 0;
	        }
	              
	        len += words[i].size();
	    }
	    // last line
	    result.push_back(connect(words, begin, n - 1, len, L, true));
	    return result;
	}

	string connect(vector<string> &words, int begin, int end,
		int len, int L, bool is_last) {
		string s;
		int n = end - begin + 1;
		for (int i = 0; i < n; ++i) {
			s += words[begin + i];
			addSpaces(s, i, n - 1, L - len, is_last);
		}
		// for only one word in a line
		if (s.size() < L) s.append(L - s.size(), ' ');
		return s;
	}

	void addSpaces(string &s, int i, int n, int L, bool is_last) {
		if (n < 1 || i > n - 1) return;
		// for the last line of text, it should be left justified,
		// and no extra space is inserted between words.
		int spaces = is_last ? 1 : (L / n + (i < (L % n) ? 1 : 0));
		s.append(spaces, ' ');
	}
};