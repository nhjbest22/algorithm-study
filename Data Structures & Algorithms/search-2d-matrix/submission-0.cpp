class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();

        // matrix[mid][0] <= target 인 mid의 최댓값
        int yes = -1, no = M;
        while(yes + 1 < no){
            int mid = (yes + no)/2;

            if(matrix[mid][0] <= target) yes = mid;
            else no = mid;
        }

        if(yes == -1) return false;

        int row = yes;
        yes = -1, no = N;

        while(yes + 1 < no){
            int mid = (yes + no) / 2;

            if(matrix[row][mid] <= target) yes = mid;
            else no = mid;
        }

        if(yes == -1 || matrix[row][yes] != target) return false;
        
        return true;
    }
};
