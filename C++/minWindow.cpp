// Time Complexity: O(n), where n is string length
// Space Complexity: O(m), where m is alphabet size

class Solution {
    public:
        string minWindow(string S, string T) {
            if(S.empty() || S.length() < T.length()) return "";
            const int ASCII_MAX = 256;

            vector<int> expCnt(ASCII_MAX, 0);
            vector<int> curCnt(ASCII_MAX, 0);
            int cnt = 0;
            int start = 0;
            int min_width = INT_MAX;
            int min_start = 0;

            for(auto const &c : T) ++expCnt[c];

            for(int i = 0; i < S.length(); ++i) {
                if(expCnt[S[i]] > 0) {
                    ++curCnt[S[i]];
                    if(curCnt[S[i]] <= expCnt[S[i]]) // counting expected elements
                        ++cnt;
                }
                if(cnt == T.size()) { // if window meets the requirement
                    while(expCnt[S[start]] == 0 || curCnt[S[start]] > expCnt[S[start]]) { // adjust left bound of window
                        --curCnt[S[start]];
                        ++start;
                    }

                    if(min_width > i - start + 1) { // update minimum window
                        min_width = i - start + 1;
                        min_start = start;
                    }
                }
            }

            if(min_width == INT_MAX) return "";
            return S.substr(min_start, min_width);
        }
};
