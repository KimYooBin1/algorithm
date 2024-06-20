#include <iostream>
using namespace std;

//팬린드 행 : 시작 문자열, 열 : 끝나는 문자열
int dp[2502][2502];
string str;

bool isPalindrome(int l, int r) {
	while (l <= r) {
		//첫 구간과 끝 구간이 다르다면
		if (str[l] != str[r]) {
			return false;
		}
		l++; r--;
	}
	return true;
}

int calcDP(int r, int c) {
	if (r > c) return dp[r][c] = 0;
	if (r == c) return dp[r][c] = 1;
	if (dp[r][c] != 0) return dp[r][c];
	
	int& ret = dp[r][c];
	ret = 987654321;
	for (int i = r; i <= c; i++) {
		if (isPalindrome(r, i)) {
			int cnt = 1;
			cnt += calcDP(i + 1, c);
			ret = min(cnt, ret);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> str;

	calcDP(0, str.size() - 1);

	cout << dp[0][str.size() - 1] << "\n";
}