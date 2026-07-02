#define f first
#define s second

class Solution {
public:
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
}

    bool isPossibble = false;
    bool findSafeWalk(vector<vector<int>>& grid, int k) {

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));

        int delR[] = {0,0,1,-1};
        int delC[] = {1,-1,0,0};

        deque<pair<int,pair<int,int>>> q;

        dist[0][0] = grid[0][0];
        q.push_back({dist[0][0],{0,0}});

        while(!q.empty()) {
            auto front = q.front();
            q.pop_front();

            int d = front.f;
            int r = front.s.f;
            int c = front.s.s;

            for(int i = 0; i < 4; i++) {
                int newR = delR[i] + r;
                int newC = delC[i] + c;

                if(isValid(newR,newC,n,m) && dist[newR][newC] > dist[r][c] + grid[newR][newC]) {

                    dist[newR][newC] = dist[r][c] + grid[newR][newC];

                    if(grid[newR][newC] == 0) 
                        q.push_front({dist[newR][newC],{newR,newC}});
                    else 
                        q.push_back({dist[newR][newC],{newR,newC}});
                }

            }

        }

        cout << dist[n-1][m-1];

        return dist[n-1][m-1] < k;




    }   
};