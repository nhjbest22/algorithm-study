#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main (){
    string str_1, str_2;
    cin >> str_1>> str_2;
    reverse(str_1.begin(), str_1.end());
    reverse(str_2.begin(), str_2.end());

    if (stoi(str_1) >  stoi(str_2)){
        cout<<str_1;
    }
    else {cout<<str_2;}
    return 0;
}
