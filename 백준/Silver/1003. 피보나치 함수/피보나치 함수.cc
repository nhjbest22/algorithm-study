#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>

int arr[40][2];

using namespace std;
int main (){
    arr[0][0] = 1; arr[0][1] = 0;arr[1][0] = 0; arr[1][1] = 1;arr[2][0] = 1; arr[2][1] = 1; arr[3][0] = 1; arr[3][1] = 2;
    for (int i = 4; i <= 40;i++){
        arr[i][0] = arr[i-1][0] + arr[i-2][0];
        arr[i][1] = arr[i-1][1] + arr[i-2][1];
    }
    int x;
    int num;
    scanf("%d",&num);
    while (num--){
        scanf("%d",&x);
        printf("%d %d\n",arr[x][0],arr[x][1]);
    }
    return 0;
}