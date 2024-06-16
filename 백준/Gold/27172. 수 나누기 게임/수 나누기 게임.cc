#include<iostream>
#include<cstring>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 1000001
using namespace std;
int main(){
    FIO;
    int n;
    cin >> n;
    int v[n];
    int m[MAX_SIZE];
    int result[n];
    // 해당 num에 대한 점수
//    map<int, int> m;
    int max_element = 0;
    memset(m, -1, sizeof(m));
    memset(result, 0, sizeof(result));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = i;
        if(max_element < v[i]) max_element = v[i];
    }
    for (int i = 1; i <= max_element; i++) {
        //해당 수는 알아볼 필요가 없다
        if(m[i] == -1) continue;
        for (int j = i * 2; j <= max_element; j += i) {
            // 양 숫자가 모두 v에 존재할때
            if (m[j] != -1) {
                result[m[i]]++;
                result[m[j]]--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<result[i]<<" ";
    }
    cout << "\n";
    return 0;
}
