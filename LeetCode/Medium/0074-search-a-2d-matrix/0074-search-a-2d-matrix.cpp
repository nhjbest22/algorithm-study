class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // non-decreasing order

        int M = matrix.size(), N = matrix[0].size();
        vector<int> firstElement;

        if(target < matrix[0][0]) return false;

        for(int i = 0; i < M; i++)
            firstElement.push_back(matrix[i][0]);


        auto it = upper_bound(firstElement.begin(), firstElement.end(), target);
        it--;

        int idx = it - firstElement.begin();

        return binary_search(matrix[idx].begin(), matrix[idx].end(), target);
    }
};