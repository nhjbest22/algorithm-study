class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        
        int curX = 0, curY = N-1;

        while(curX < M && curY >= 0){
            auto& cur = matrix[curX][curY];
            
            if(cur == target) return true;

            if(cur > target) curY--;
            else curX++;
        }

        return false;
    }
};