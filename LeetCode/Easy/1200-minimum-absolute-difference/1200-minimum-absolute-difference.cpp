class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());
        int MIN = INT32_MAX;
        for(int i = 1; i< arr.size(); i++){
            int diff = arr[i] - arr[i-1];
            MIN = min(MIN, diff);
        }

        for(int i = 1; i< arr.size(); i++){
            int diff = arr[i] - arr[i-1];

            if(diff != MIN) continue;

            ans.push_back({arr[i-1], arr[i]});
        }

        return ans;
    }
};