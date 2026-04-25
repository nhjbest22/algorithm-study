#include <bits/stdc++.h>

using namespace std;

int arr[15];

int main (){
    int num, M, count;
    int result = 0;
    cin>>num>>M; count = num;
    while (num--){
        cin>>arr[count-num-1];
    }
    count--;
    while(1){
        if (M == 0)
            {
                cout<<result; return 0;}
        if (arr[count] <= M){
            result += M/arr[count];
            M %= arr[count];
        }
        count--;
    }
}