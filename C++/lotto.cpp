#include <bits/stdc++.h>

using namespace std;

int n, num[20],visit[20];
void f(int v, int cnt) {
	if (v == n && cnt == 6) {
		for (int i = 0; i < n; i++) { if (visit[i] == 1) { cout << num[i] << " "; } }
		cout << '\n';
	}
	if (v == n) return;
	visit[v] = 1;
	f(v + 1, cnt + 1);
	visit[v] = 0;
	f(v + 1, cnt);
}

int main() {
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) cin >> num[i];
		visit[20] = { 0, };
		f(0, 0);
		cout << '\n';
	}
	return 0;
}
