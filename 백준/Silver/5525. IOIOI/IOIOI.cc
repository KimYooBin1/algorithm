#include<cstring>
#include<iostream>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    int size = 0;
    int result = 0;
    for (int i = 0; i < m; i++) {
        if(str[i] == 'O') continue;
        while(str[i+1] == 'O' && str[i+2] == 'I'){
            size++;
            if(size == n){
                result++;
                size--;
            }
            i += 2;
        }
        size = 0;
    }
    cout << result << "\n";
}
