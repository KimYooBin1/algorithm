#include <iostream>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

bool check(string str){
    int len = str.length();
    int mid = len / 2;
    for (int i=0;i<mid;i++) {
        if (str[mid + i] != str[mid - i - 1]) return false;
    }
    return true;
}

int main() {
    FIO;
    int n;
    cin >> n;
    vector<string> v(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if(check(v[i])) count++;
    }
    cout << count * (count - 1) << "\n";
}
