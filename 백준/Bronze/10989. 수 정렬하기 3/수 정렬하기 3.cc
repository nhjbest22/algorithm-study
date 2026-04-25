#include <iostream>
#include <cstdio>
using namespace std;

int arr[10005];
int main (){
    //vector<int> v;
    int num, get;
    scanf("%d",&num);
    getchar();
    while (num--){
        scanf("%d",&get);
        getchar();
        arr[get]++;
    }
    for (int i =1;i <= 10000;i++){
        if (arr[i]){
            while(arr[i]--)
                printf("%d\n",i);
        }
    }
    return 0;
}
