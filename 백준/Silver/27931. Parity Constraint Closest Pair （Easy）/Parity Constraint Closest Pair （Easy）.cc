#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    int index_even = -2;
    int index_add = -2;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            if (index_even == -2) index_even = i;
            else index_even = min(i, index_even);
        }
        else {
            if (index_add == -2) index_add = i;
            else index_add = min(i, index_add);
        }
    }



    int result_even = INT_MAX - 1;
    int result_add = INT_MAX - 1;
    for (int i = 0; i < n - 1; i++) {
        // cout << index_even << " " << index_add << "\n";
        // 지금 숫자가 짝수인 경우
        // 짝수가 나와야 짤수거리
        // 홀수가 나와야 홀수거리
        if (v[i] % 2 == 0) {
            // 짝수 인덱스 갱신
            if (index_even <= i && index_even != -2) {
                for (int j = i + 1; j < n; j++) {
                    if (v[j] % 2 == 0) {
                        index_even = j;
                        break;
                    }
                }
                // 더이상 짝수 숫자가 없다
                if (index_even <= i) index_even = -2;
            }
            // 홀수 인덱스 갱신
            if (index_add <= i && index_add != -2) {
                for (int j = i + 1; j < n; j++) {
                    if (v[j] % 2 != 0) {
                        index_add = j;
                        break;
                    }
                }
                // 더이상 홀수 숫자가 없다
                if (index_add <= i) index_add = -2;
            }

            // 짝수 거리 갱신
            if (index_even != -2) {
                result_even = min(result_even, v[index_even] - v[i]);
            }

            // 홀수 거리 갱신
            if (index_add != -2) {
                result_add = min(result_add, v[index_add] - v[i]);
            }
        }
        // 지금 숫자가 홀수인 경우
        // 짝수가 나와야 홀수거리
        // 홀수가 나와야 짝수거리
        else {
            // 짝수 인덱스 갱신
            if (index_even <= i && index_even != -2) {
                for (int j = i + 1; j < n; j++) {
                    if (v[j] % 2 == 0) {
                        index_even = j;
                        break;
                    }
                }
                // 더이상 짝수 숫자가 없다
                if (index_even <= i) index_even = -2;
            }
            // 홀수 인덱스 갱신
            if (index_add <= i && index_add != -2) {
                for (int j = i + 1; j < n; j++) {
                    if (v[j] % 2 != 0) {
                        index_add = j;
                        break;
                    }
                }
                // 더이상 홀수 숫자가 없다
                if (index_add <= i) index_add = -2;
            }

            // 짝수 거리 갱신
            if (index_even != -2) {
                result_add = min(result_add, v[index_even] - v[i]);
            }

            // 홀수 거리 갱신
            if (index_add != -2) {
                result_even = min(result_even, v[index_add] - v[i]);
            }
        }
    }
    cout << ((result_even != INT_MAX - 1) ? result_even : -1) << " " << ((result_add != INT_MAX - 1) ? result_add : -1) << "\n";

}