#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin >> n;
    while (n--) {
        vector<int> v(10);
        int size = 0;
        for (int i = 1; i < 10; i++) {
            cin >> v[i];
            size += v[i];
        }
        v[9] += v[6];
        v[6] = 0;
        vector<int> r(size);
        bool check = true;
        int s = 0, e = size - 1;
        for (int i = 9; i > 0; i--) {
            while(true){
                if (!v[i]) break;
                if(check){
                    r[s++] = i;
                    v[i]--;
                    check = false;
                }
                if (!v[i]) break;
                if(!check){
                    r[e--] = i;
                    v[i]--;
                    check = true;
                }

//                if (!v[i]) break;
//                result.push_front(i);
//                v[i]--;
//                if (!v[i]) break;
//                result.push_back(i);
//                v[i]--;
            }
        }
        for(auto &a : r){
            cout << a << " ";
        }
        cout << "\n";
//        while(!result.empty()){
//            cout<<result.front()<<" ";
//            result.pop_front();
//        }
    }
}