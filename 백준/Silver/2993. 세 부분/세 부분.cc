#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    string str;
    cin >> str;
    int len = str.length();
    vector<string> v;
    for (int i = 1; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            string tmp1 = str.substr(0, i);
            string tmp2 = str.substr(i, j - i);
            string tmp3 = str.substr(j, len - j);
            reverse(tmp1.begin(), tmp1.end());
            reverse(tmp2.begin(), tmp2.end());
            reverse(tmp3.begin(), tmp3.end());
            string tmp_str = "";
            for (auto &a: tmp1) {
                tmp_str += a;
            }
            for (auto &a: tmp2) {
                tmp_str += a;
            }
            for (auto &a: tmp3) {
                tmp_str += a;
            }
            v.push_back(tmp_str);
        }
    }
    sort(v.begin(), v.end());

    cout << v[0] << "\n";
}