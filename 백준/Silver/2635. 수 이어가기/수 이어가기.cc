#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int calc(int num1, int num2) {
    int len = 0;
    if(num1 - num2 < 0) return len;
    len += calc(num2, num1 - num2) + 1;
    return len;
}

int main(){
    FIO;
    int num;
    cin >> num;
    int max_len = -1;
    int max_num = 0;
    for (int i = 1; i <= 30000; i++) {
        int len = calc(num, i);
        if(max_len < len){
            max_len = len;
            max_num = i;
        }
    }
    int first = num, second = max_num;
//    cout << max_num << "\n";
    cout << max_len + 2 << "\n" << first << " ";
    while(0 <= second){
        int tmp = first;
        first = second;
        second = tmp - second;
        cout << first << " ";
    }
}