#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    string str(num % 2 == 0 ? "Even" : "Odd");
    return str;
}