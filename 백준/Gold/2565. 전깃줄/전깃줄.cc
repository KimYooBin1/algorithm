#include <iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>

#define MAX_SIZE 501
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main()
{
    FIO;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    v[0].first = v[1].second = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int line = 0;
    int result = 0;
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (v[j].second < v[i].second) {
                arr[i] = max(arr[i], arr[j] + 1);
            }
        }
        if (result < arr[i]) result = arr[i];
    }
    cout << n - result << "\n";
    return 0;
}
