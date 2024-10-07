#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;

int main(){
    FIO;
    int N, M;
    cin >> N >> M;
    vector<int> num1(N);
    vector<int> num2(M);
    vector<int> result(N+M, 0);
    string str1, str2;
    cin >> str1 >> str2;
    for (int i = 0; i < str1.length(); i++) {
        num1[i] = str1[i] - '0';
    }
    for (int i = 0; i < str2.length(); i++) {
        num2[i] = str2[i] - '0';
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    //num1 의 i번째 index와 num2 의 j번째 index의 결과
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int mul = num1[i] * num2[j];
            result[i + j] += mul;

        }
    }
    for (int i = 0; i < N + M; i++) {
        if((result[i] / 10) == 0) continue;
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }
    reverse(result.begin(), result.end());
    bool check = false;
    for (int i = 0; i < N + M; i++) {
        if(!result[i] && !check) continue;
        check = true;
        cout<<result[i];
    }
    if(!check){
        cout<<0;
    }
    cout << "\n";

}
