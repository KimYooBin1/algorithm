#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<int> calc(string s){

}
int main(){
    FIO;
    int round;
    cin >> round;
    for (int i = 0; i < round; i++) {
        int n;
        cin >> n;
        vector<int> g1(5, 0);
        vector<int> g2(5, 0);
        for (int j = 0; j < n; j++) {
            int num;
            cin>>num;
            g1[num]++;
        }
        cin >> n;
        for (int j = 0; j < n; j++) {
            int num;
            cin>>num;
            g2[num]++;
        }
        int result = 0;
//        for(auto a : g1){
//            cout<<a<<" ";
//        }
//        cout<<"\n";
//        for(auto a : g2){
//            cout<<a<<" ";
//        }
//        cout<<"\n";

        for (int j = 4; j >= 1; j--) {
//            cout << j << " " << g1[j] << " " << g2[j] << "\n";
            if(g1[j] > g2[j]) {
                result = 1;
                break;
            }
            else if(g1[j] < g2[j]) {
                result = 2;
                break;
            }
        }
        cout << (result == 0 ? 'D' : (result == 1 ? 'A' : 'B')) << "\n";
    }
}