#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct student {
    int sex;
    int index;
};

int main(){
    FIO;
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    vector<student> s(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        s[i].sex = a;
        s[i].index = b;
    }
    for (int i = 0; i < s.size(); i++) {
        int sex = s[i].sex;
        int index = s[i].index;
        // 남자, 배수 변경
        if(sex == 1){
            int index_tmp = index;
            while(true){
                arr[index_tmp] = 1 - arr[index_tmp];
                index_tmp += index;
                if(n < index_tmp) break;
            }
        }
        // 여자, 대칭인지 확인
        else{
            arr[index] = 1 - arr[index];
            int index1 = index - 1;
            int index2 = index + 1;
            while(0 < index1 && index2 <= n){
                if(arr[index1] != arr[index2]) break;
                arr[index1] = 1 - arr[index1];
                arr[index2] = 1 - arr[index2];
                index1--;
                index2++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
//    cout << "\n";
}