// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            if(start == end) return 1;

            queue<string> current;
            unordered_set<string> isVisited;
            current.push(start);
            int cnt = current.size();
            int ans = 0;

            while(!current.empty()) {
                string s = current.front();
                current.pop();
                --cnt;
                unordered_set<string> nextStrs;
                getNext(s, dict, isVisited, nextStrs);
                for(auto str: nextStrs) {
                    if(str == end) {
                        // current depth: ans + 1
                        // so answer is (ans + 1) + 1
                        return ans + 2;
                    }
                    current.push(str);
                }
                if(cnt == 0) {
                    cnt = current.size();
                    ++ans;
                }
            }

            return 0;
        }
    private:
        void getNext(string s, unordered_set<string> &dict, unordered_set<string> &isVisited, unordered_set<string> &nextStrs) {
            for(int i = 0; i < s.length(); ++i) {
                string nextStr(s);
                for(char c = 'a'; c <= 'z'; ++c) {
                    if(c != nextStr[i]) {
                        swap(c, nextStr[i]);
                        if(dict.count(nextStr) && !isVisited.count(nextStr)) {
                            nextStrs.insert(nextStr);
                            isVisited.insert(nextStr);
                        }
                        swap(c, nextStr[i]);
                    } 
                }
            }
        }
};
