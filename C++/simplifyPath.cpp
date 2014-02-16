// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> dirs;

            for(auto i = path.cbegin(); i != path.cend();) {
                ++i;  // write here is to make sure i is not end

                auto j = find(i, path.cend(), '/');
                string dir = string(i, j);

                if(!dir.empty() && dir != ".") {
                    if(dir == "..") {
                        if(!dirs.empty()) dirs.pop_back();
                    }
                    else
                        dirs.push_back(dir);
                }
                i = j; // i may be end
            }

            if(dirs.empty()) return "/";

            string ans;
            for(auto dir : dirs) {
                ans.append("/" + dir);
            }

            return ans;
        }
};
