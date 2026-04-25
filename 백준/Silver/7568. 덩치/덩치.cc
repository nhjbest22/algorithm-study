#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[26];

int main (){
    int num;
    int count = 1;
    cin >> num;
    int arr_h[num+5];
    int arr_w[num+5];
    for (int i =0; i< num; i ++){
        cin >> arr_h[i]>>arr_w[i];
    }
    for (int i = 0 ; i < num ; i ++){
        count = 1;
        for (int j = 0; (j < num);j++ ){
            if (i != j){
                if (arr_h[i] < arr_h[j] && arr_w[i] < arr_w[j])
                    count++;
            }
        }
        cout<<count<<" ";
    }

    return 0;
}