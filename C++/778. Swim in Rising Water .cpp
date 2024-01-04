class Solution {
private:
    bool isValid(int row, int col, int n) {
        if(row >= 0 && row < n && col >= 0 && col < n) 
            return true;
        return false;
    }

public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));
        distance[0][0] = grid[0][0];

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 
        // { time , { row, col } }
        pq.push({grid[0][0], {0, 0}});
        int delR[] = {-1,0,1,0};
        int delC[] = {0,1,0,-1};

        while(!pq.empty()) {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == n-1 && col == n-1) return time;

            for(int i = 0; i < 4; i++) {
                int newR = row + delR[i];
                int newC = col + delC[i];

                if(isValid(newR,newC,n)) {
                    int time1 = max(time, grid[newR][newC]);
                    if (time1 < distance[newR][newC]) {
                        distance[newR][newC] = time1;
                        pq.push({time1, {newR, newC}});
                    
                    }
                }
            }
        }
        return 0;
    }
};
