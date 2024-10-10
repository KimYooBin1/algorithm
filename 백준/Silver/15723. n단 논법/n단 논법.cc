#include <iostream>
#include <cstring>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 26
using namespace std;
int parent[26];

int find(int x){
    if(parent[x] == x) return x;
    return find(parent[x]);
}

bool findTarget(int x, int target){
//    cout << x << " " << parent[x] << "\n";
    if(x == target) return true;
    else if(parent[x] == x) return false;
    else return findTarget(parent[x], target);
}

bool check(int a, int b){
    return a == b;
}

void Union(int a, int b){
    if(check(a, b)) return;
    parent[a] = b;
}

void init(){
    for (int i = 0; i < MAX_SIZE; i++) {
        parent[i] = i;
    }
}

int main()
{
    FIO;
    init();
    int n;
    cin >> n;
    string str1, str2, str3;
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2 >> str3;
        Union(str1[0] - 'a', str3[0] - 'a');
    }
    cin >> n;
//    for (int i = 0; i < MAX_SIZE; i++) {
//        cout << i << " parent is : " << parent[i] << "\n";
//    }
    for (int i = 0; i < n; i++) {
        cin >> str1 >> str2 >> str3;
        if(findTarget(str1[0] - 'a', str3[0] - 'a')) cout << "T\n";
        else cout << "F\n";
    }
    return 0;
}