#include <cstring>
#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int c[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int num[6];
int n;
bool check(int arr[6]){
    return arr[0] * 10 + arr[1] + arr[2] * 10 + arr[3] == arr[4] * 10 + arr[5]; 
}
void printResult(int arr[6]){
    string result = "";
    for(int i=0;i<6;i++){
        char temp = '0' + arr[i];
        result += temp;
        if(i == 1) result += '+';
        if(i == 3) result += '=';
    }
    cout << result << "\n";
}
bool calc(int index){
    if(index == 6){
        if(!check(num)) return false;
        int sum = 0;
        for (int & i : num) {
            sum += c[i];
        }
        if(sum == n){
            printResult(num);
            return true;
        }
        else{
            return false;
        }
    }
    for (int i = 0; i < 10; i++) {
        num[index] = i;
        if(calc(index + 1)) return true;
        num[index] = 0;
    }
    return false;
}
int main(){
    FIO;
    cin >> n;
    n -= 4;
    if(!calc(0)){
        cout << "impossible\n";
    }
    return 0;
}