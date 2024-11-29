#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    cin.ignore();
    vector<queue<string>> v(n);
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
//        cout << str << "\n";
        string tmp = "";
        for (int j = 0; j < str.length(); j++) {
            if(str[j] == ' '){
                v[i].push(tmp);
                tmp = "";
            }else{
                tmp += str[j];
            }
        }
        v[i].push(tmp);
    }
//    cin.ignore();
    string str;
    getline(cin, str);
    string tmp = "";
    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == ' ' || i == str.length()) {
            bool check = false;
            for (int j = 0; j < n; j++) {
                if (v[j].front() == tmp) {
                    check = true;
                    v[j].pop();
                    break;
                }
            }
            tmp = "";
            if (!check) {
                cout << "Impossible\n";
                return 0;
            }
        } else {
            tmp += str[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if(!v[i].empty()){
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    return 0;
}