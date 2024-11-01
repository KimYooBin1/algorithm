#include <cstring>
#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int arr[602][602];
int arr1[301][301];
int main(){
    FIO;
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    for (int i = 0; i < h + x; i++) {
        for (int j = 0; j < w + y; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (x <= i && y <= j) {
                arr1[i][j] = arr[i][j] - arr1[i - x][j - y];
            }else{
                arr1[i][j] = arr[i][j];
            }
            cout << arr1[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}