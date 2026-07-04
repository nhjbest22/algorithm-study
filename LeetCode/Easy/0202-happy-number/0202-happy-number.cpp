class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;
        while(n != 1){
            if(us.find(n) != us.end()) 
                return false;

            us.insert(n);

            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }

            n = sum;
        }

        return true;
    }
};