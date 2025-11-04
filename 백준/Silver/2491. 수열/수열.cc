#include<cstring>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    FIO;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int length = 1;
    int max_num = arr[0];
    int result1 = 0;
    for (int i = 1; i < n; i++) {
        if(max_num > arr[i]) {
            result1 = max(result1, length);
            length = 0;
        }
        max_num = arr[i];
        length++;
    }
    result1 = max(result1, length);

    int result2 = 0;
    int min_num = arr[0];
    length = 1;
    for (int i = 1; i < n; i++) {
        if(min_num < arr[i]) {
            result2 = max(result2, length);
            length = 0;
        }
        min_num = arr[i];
        length++;
    }
    result2 = max(result2, length);

    cout << max(result1, result2) << "\n";
}