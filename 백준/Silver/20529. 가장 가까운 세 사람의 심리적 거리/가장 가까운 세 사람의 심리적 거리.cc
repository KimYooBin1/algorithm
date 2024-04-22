#include<cstring>
#include<iostream>
#include<map>
#include<cmath>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100000
using namespace std;

int calc(string str1, string str2){
    int result = 0;
    for (int i = 0; i < 4; i++) {
        if(str1[i] != str2[i]) result++;
    }
    return result;
}

int main(){
    FIO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; i++) {
            cin>>arr[i];
        }
        if(n>32) {
            cout<<0<<"\n";
            continue;;
        }
        int result = 20;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int z = j + 1; z < n; z++) {
                    result = min(result, calc(arr[i], arr[j]) + calc(arr[i], arr[z]) + calc(arr[j], arr[z]));
                }
            }
        }
        cout << result << "\n";
    }
}
