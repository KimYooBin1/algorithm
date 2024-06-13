#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 100001
using namespace std;
int main(){
    FIO;
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int s = 0;
    int e = n-1;
    int result = INT_MAX;
    int r_s = 0;
    int r_e = 0;
    while (s < e) {
//        cout << s << " " << e << "\n";
        int sum = arr[s] + arr[e];
//        cout << sum << "\n";
//        cout << sum << " " << result << "\n";
        if(sum < 0){
            if(abs(sum) < abs(result)){
                result = sum;
                r_s = s;
                r_e = e;
            }
            s++;
        } else if (0 < sum) {
            if(abs(sum) < abs(result)){
                result = sum;
                r_s = s;
                r_e = e;
            }
            e--;
        }
        else{
            cout<<arr[s]<<" "<<arr[e]<<"\n";
            return 0;
        }
    }
    cout << arr[r_s] << " " << arr[r_e] << "\n";
}