class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size(), N = matrix[0].size();
        
        for(int i = 0; i < M; i++){
            if(binary_search(matrix[i].begin(), matrix[i].end(), target)) return true;
        }

        return false;
    }
};