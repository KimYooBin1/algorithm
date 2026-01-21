#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
void calc1(int n, int m, int r, vector<vector<int>> &v){
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = v[i][j];
            v[i][j] = v[n - i - 1][j];
            v[n - i - 1][j] = tmp;
        }
    }
}

void calc2(int n, int m, int r, vector<vector<int>> &v){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            int tmp = v[i][j];
            v[i][j] = v[i][m - j - 1];
            v[i][m - j - 1] = tmp;
        }
    }
}

void calc3(int &n, int &m, int r, vector<vector<int>> &v){
    vector<vector<int>> tmp(m, vector<int> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = v[n - j - 1][i];
        }
    }
    v.clear();
    v = tmp;

    int t =  n;
    n = m;
    m = t;
}

void calc4(int &n, int &m, int r, vector<vector<int>> &v){
    vector<vector<int>> tmp(m, vector<int> (n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = v[j][m - i - 1];
        }
    }

    v.clear();
    v = tmp;


    int t =  n;
    n = m;
    m = t;
}

void calc5(int n, int m, int r, vector<vector<int>> &v){
    vector<vector<int>> tmp(n, vector<int> (m));


    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            tmp[i][j] = v[n / 2 + i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) {
            tmp[i][j] = v[i][j - m / 2];
        }
    }

    for (int i = n / 2; i  < n; i++) {
        for (int j = m / 2; j  < m; j++) {
            tmp[i][j] = v[i - n / 2][j];
        }
    }

    for (int i = n / 2; i  < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            tmp[i][j] = v[i][j + m / 2];
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = tmp[i][j];
        }
    }
}

void calc6(int n, int m, int r, vector<vector<int>> &v){
    vector<vector<int>> tmp(n, vector<int> (m));


    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < m / 2; j++) {
            tmp[n / 2 + i][j] = v[i][j];
        }
    }

    for (int i = 0; i < n / 2; i++) {
        for (int j = m / 2; j < m; j++) {
            tmp[i][j - m / 2] = v[i][j];
        }
    }

    for (int i = n / 2; i  < n; i++) {
        for (int j = m / 2; j  < m; j++) {
            tmp[i - n / 2][j] = v[i][j];
        }
    }

    for (int i = n / 2; i  < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            tmp[i][j + m / 2] = v[i][j];
        }
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][j] = tmp[i][j];
        }
    }
}

int main(){
    FIO;
    int n, m, r;
    cin >> n >> m >> r;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    for (int i = 0; i < r; i++) {
        int type;
        cin >> type;
        if(type == 1) calc1(n, m, r, v);
        else if(type == 2) calc2(n, m, r, v);
        else if(type == 3) calc3(n, m, r, v);
        else if(type == 4) calc4(n, m, r, v);
        else if(type == 5) calc5(n, m, r, v);
        else if(type == 6) calc6(n, m, r, v);
    }
    for(auto &a : v){
        for(auto &b : a){
            cout << b << " ";
        }
        cout << "\n";
    }
//    cout << n << " " << m << "\n";
}