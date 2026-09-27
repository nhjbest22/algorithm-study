class Solution {
public:
    bool hasDuplicate(vector<int>& nuss) {
        unordered_set<int> us;
        for(int nus: nuss){
            if(us.find(nus) != us.end()) return true;

            us.insert(nus);
        }

        return false;
    }
};