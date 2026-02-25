#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main() {
    FIO;
    int h, w;
    cin >> h >> w;
    vector<int> v(w);
    for (int i = 0; i < w; i++) {
        cin >> v[i];

    }
    int result = 0;
    stack<int> s;
    int max_len = v[0];
    s.push(v[0]);
    for (int i = 1; i < w; i++) {
        if (v[i] < max_len) {
            s.push(v[i]);
        }else if (v[i] == max_len || v[i] > max_len) {
            while (!s.empty()) {
                result += max_len - s.top();
                s.pop();
            }
            max_len = v[i];
            s.push(v[i]);
        }
    }
    int max_len2 = -1;
    while (!s.empty()) {
        if (max_len2 == -1) {
            max_len2 = s.top(); s.pop();
            continue;
        }
        int height = s.top(); s.pop();
        if (height >= max_len2) {
            max_len2 = height;
        }else {
            result += max_len2 - height;
        }
    }
    cout<<result<<"\n";
}