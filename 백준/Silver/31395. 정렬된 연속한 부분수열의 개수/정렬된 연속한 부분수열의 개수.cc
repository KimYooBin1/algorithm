#include <cstring>
#include <iostream>

#define MAX_SIZE 200001
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int arr[MAX_SIZE];
long long sum[MAX_SIZE];
void init(){
    long long s = 0;
    for (long long i = 1; i < MAX_SIZE; i++) {
        s += i;
        sum[i] = s;
    }
}

int main(){
    FIO;
    init();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr[n+1] = 0;
    int s = 0, e = 0;
    long long result = 0;
    while (s <= e && e < n) {
        if(arr[e] < arr[e+1]){
            e++;
        }
        else{
//            cout << s << " " << e << "\n";
            result += sum[e - s + 1];
            s = ++e;
        }
    }
    cout << result << "\n";
    return 0;
}