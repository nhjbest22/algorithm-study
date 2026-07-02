class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int st = 0, en = arr1.size() - 1;
        int N = arr1.size();
        int isOccured[1'005] = {0, };

        int rank = 1;
        
        for(auto& num: arr2)
            isOccured[num] = rank++;

        while(st < en){
            while(st < N && isOccured[arr1[st]]){
                st++;
            }

            while(en >= 0 && !isOccured[arr1[en]]){
                en--;
            }

            if(st > en) break;

            swap(arr1[st], arr1[en]);
        }

        sort(arr1.begin(), arr1.begin() + st, [&](const int& a, const int& b){
            if(a != b) return isOccured[a] < isOccured[b];

            return false;
        });
        sort(arr1.begin() + st, arr1.end());

        return arr1;
    }
};