#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int dh[26] = {
    -1, -1, -1, -1, -1, -1, -1, -1, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1,
};
int dx[26] = {
    -1, -1, -1, 0, 0, 0, 1, 1, 1,
    -1, -1, -1, 0, 0, 1, 1, 1,
    -1, -1, -1, 0, 0, 0, 1, 1, 1,
};
int dy[26] = {
    -1, 0, 1, -1, 0, 1, -1, 0, 1,
    -1, 0, 1, -1, 1, -1, 0, 1,
    -1, 0, 1, -1, 0, 1, -1, 0, 1,
};


int main() {
    int r, c, h;
    cin >> r >> c >> h;
    int a[h][r][c];
    vector<vector<vector<char>>> map(h, vector<vector<char>> (r, vector<char> (c, '.')));
    vector<vector<vector<char>>> result(h, vector<vector<char>> (r, vector<char> (c, '*')));
    for (int i = 0; i < h; i++) {
        for (int z = 0; z < r; z++) {
            for (int j = 0; j < c; j++) {
                cin >> map[i][z][j];
            }
        }
    }

    // for (auto a: map) {
    //     for (auto b: a) {
    //         for (auto c : b) {
    //             cout<<c;
    //         }
    //         cout<<"\n";
    //     }
    // }

    for (int z = 0; z < h; z++) {
        for (int x = 0; x < r; x++) {
            for (int y = 0; y < c; y++) {
                if (map[z][x][y] == '*') continue;
                int sum = 0;
                for (int index = 0; index < 26; index++) {
                    int nx = x + dx[index];
                    int ny = y + dy[index];
                    int nh = z + dh[index];
                    if (nx < 0 || ny < 0 || nh < 0) continue;
                    if (r <= nx || c <= ny || h <= nh) continue;
                    if (map[nh][nx][ny] != '*') continue;
                    sum++;
                }
                sum %= 10;
                // cout << sum << "\n";

                result[z][x][y] = sum + '0';
            }
        }
    }
    for (auto a: result) {
        for (auto b: a) {
            for (auto c : b) {
                cout<<c;
            }
            cout<<"\n";
        }
    }
}