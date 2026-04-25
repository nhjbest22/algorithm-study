#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <utility>

using namespace std;
int main (){
    int A, B, C, D;
    cin >> A>> B>>C>>D;
    int temp_1 = min(C-A,A);
    int temp_2 = min(B, D-B);
    int m = min(temp_1, temp_2);
    cout<<m;
    return 0;
}