class Solution {
public:
    string winningPlayer(int x, int y) {
        bool Alice = false;

        while(x >= 1 && y >= 4){
            x -= 1;
            y -= 4;

            Alice = !Alice;
        }

        return Alice ? "Alice" : "Bob";
    }
};