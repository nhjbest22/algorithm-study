class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        bool check[15][15];
        fill(&check[0][0], &check[0][0] + 15*15, false);

        int M = matrix.size(), N = matrix[0].size();

        int x = 0, y = 0;
        int dir = 0;

        while(1){
            if(x < 0 || x >= M|| y < 0 || y >= N) break;
            if(check[x][y] == true) break;

            check[x][y] = true;
            ans.push_back(matrix[x][y]);

            while(1){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(nx < 0 || nx >= M|| ny < 0 || ny >= N) break;
                if(check[nx][ny]) break;

                check[nx][ny] = true;
                ans.push_back(matrix[nx][ny]);

                x = nx; y = ny;
            }

            dir = (dir + 1)%4;

            x += dx[dir];
            y += dy[dir];
        }

        return ans;
    }
};