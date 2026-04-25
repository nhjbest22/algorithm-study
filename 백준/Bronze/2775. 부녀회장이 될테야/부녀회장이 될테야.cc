#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int arr[15][15];
int main (){
    int sum;
    for (int i = 1;i<=14;i++){
        arr[0][i] = i;
    }
    for (int i = 1;i<=14;i++){
        sum = 0;
        for (int j = 1; j <= 14; j ++){
            sum+= arr[i-1][j];
            arr[i][j] = sum;
        }
    }
    int Tcase;
    int col, row;
    cin >> Tcase;
    for (int i =0 ; i < Tcase;i++){
        cin >>col;
        cin>>row;
        cout<<arr[col][row]<<endl;
    }
    return 0;
}