#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string str;
    int n;
    cin >> str >> n;
    
    for(int i = 0; i < n; i++) cout<<str;
    return 0;
}