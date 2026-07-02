class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int digit = 0;
            while(num){
                digit += num % 10;
                num /= 10;
            }

            num = digit;
        }

        return num;
    }
};