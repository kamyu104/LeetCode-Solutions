//1210. Minimum Moves to Reach Target with Rotations


class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        map<pair<pair<int,int>,pair<int,int>>,int>vis;
        set<pair<int,pair<pair<int,int>,pair<int,int>>>>q;
        q.insert({0,{{0,0},{0,1}}});
        while(!q.empty()){
            auto it=q.begin();
            int x1=it->second.first.first;
            int y1=it->second.first.second;
            int x2=it->second.second.first;
            int y2=it->second.second.second;
            int cost=it->first;
            if(x1==n-1 && y1==n-2 && x2==n-1 && y2==n-1){
                return cost;
            }
            if(vis[{{x1,y1},{x2,y2}}]==0){
                if(y1+1<n && y2+1<n && grid[x1][y1+1]!=1 && grid[x2][y2+1]!=1){
                    q.insert({cost+1,{{x1,y1+1},{x2,y2+1}}});
                }
                if(x1+1<n && x2+1<n && grid[x1+1][y1]!=1 && grid[x2+1][y2]!=1){
                    q.insert({cost+1,{{x1+1,y1},{x2+1,y2}}});
                }
                if(x1==x2 && x1+1<n && y1+1<n && x2+1<n && y2-1>=0 && grid[x2+1][y2-1]!=1 && grid[x1+1][y1+1]!=1){
                    q.insert({cost+1,{{x1,y1},{x2+1,y2-1}}});
                }
                if(y1==y2 && x1+1<n && y1+1<n && x2-1>=0 && y2+1<n && grid[x2-1][y2+1]!=1 && grid[x1+1][y1+1]!=1){
                    q.insert({cost+1,{{x1,y1},{x2-1,y2+1}}});
                }
                vis[{{x1,y1},{x2,y2}}]=1;
            }
            q.erase(it);
        }
        return -1;
    }
};