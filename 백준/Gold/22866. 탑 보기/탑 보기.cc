#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct T {
    int index;
    int height;
};

struct r {
    int size;
};

int main() {
    FIO;
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }

    stack<T> s1;
    stack<T> s2;
    vector<int> v1(n, -1);
    vector<int> v2(n, -1);
    vector<r> result(n);
    for (int i = 0; i < n; i++) {
        while (!s1.empty()) {
            // 현재 건물보다 작거나 같으면 제외한다.
            if (s1.top().height > v[i]) break;
            s1.pop();
        }
        result[i].size += s1.size();
        if (!s1.empty()) {
            v1[i] = s1.top().index;
        }
        s1.push({i, v[i]});
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        while (!s2.empty()) {
            // 현재 건물보다 작거나 같으면 제외한다.
            if (s2.top().height > v[i]) break;
            s2.pop();
        }
        result[n - 1 - i].size += s2.size();
        if (!s2.empty()) {
            v2[i] = n - s2.top().index - 1;
        }
        s2.push({i, v[i]});
    }

    reverse(v2.begin(), v2.end());

    // for (auto a : v1) {
    //     cout<<a<<" ";
    // }
    // cout << "\n\n";
    // for (auto a : v2) {
    //     cout<<a<<" ";
    // }
    // cout << "\n";


    for (int i=0;i<n;i++){
        cout<<result[i].size<<" ";
        if (result[i].size != 0) {
//            cout<<"\n"<<v1[i]<<" "<<v2[i]<<" "<<i<<"\n"<<":";
            if (v1[i] == -1) {
                cout<<v2[i] + 1;
            }else if (abs(i - v1[i]) > abs(v2[i] - i)){
                cout<<v2[i] + 1;
            }else cout<<v1[i] + 1;
        }
        cout << "\n";
    }


}