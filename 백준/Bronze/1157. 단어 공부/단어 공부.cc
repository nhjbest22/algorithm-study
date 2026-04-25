#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[26];

int main (){
    string str;
    int maxpos;
    cin >> str;
    for (int i = 0 ; i < str.size(); i++){
        str[i] = tolower(str[i]);
        arr[str[i] - 'a']++;
    }
    
    int max = -1; int max_pos;
    for (int i = 0 ; i < 26 ; i ++){
        if (max < arr[i]){
            max = arr[i];
            max_pos = i;
        }
        else if (max == arr[i])
            max_pos = -1;
    }
    if (max_pos == -1){
        cout<<"?";
        return 0;
    }
    cout<<char(max_pos + 'A');
    return 0;
}