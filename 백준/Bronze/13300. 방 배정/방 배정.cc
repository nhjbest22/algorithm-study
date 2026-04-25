#include <bits/stdc++.h>
using namespace std;
int arr[2][10000];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int num1, num2;
    int temp1, temp2;
    int rnum = 0;
    int S,Y;
    cin>>num1>>num2;
    while(num1--){
        cin>>S>>Y;
        arr[S][Y]++;
    }
    for (int i = 0; i < 6;i++){
        if (arr[0][i+1] != 0){
            temp1 = arr[0][i+1]/num2;
            if (arr[0][i+1] <= temp1*num2)
                rnum += temp1;
            else
                rnum += (temp1) + 1;
        }
        if (arr[1][i+1]){
            temp1 = arr[1][i+1]/num2;
            if (arr[1][i+1] <= temp1*num2)
                rnum += temp1;
            else
                rnum += (temp1) + 1;
        }
    }
    cout<<rnum;
    return 0;
}