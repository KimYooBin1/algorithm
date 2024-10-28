#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int x, y;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main() {
    FIO;
    int n, m;
    cin >> n >> m;
    int map[n][m * 3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m * 3; j++) {
            cin >> map[i][j];
        }
    }
    int pixel[n][m];
    memset(pixel, 0, sizeof(pixel));
    int limit;
    cin >> limit;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int z = 0; z < 3; z++) {
                sum += map[i][3 * j + z];
            }
            sum /= 3;
            if(sum < limit) continue;
            pixel[i][j] = 1;
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << pixel[i][j] << " ";
//        }
//        cout << "\n";
//    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(pixel[i][j] != 1) continue;
            result++;
            pixel[i][j] = -1;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                tie(x, y) = q.front(); q.pop();
                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                    if (pixel[nx][ny] != 1) continue;
                    q.push({nx, ny});
                    pixel[nx][ny] = -1;
                }
            }
        }
    }
    cout << result << "\n";
}
