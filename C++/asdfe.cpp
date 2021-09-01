#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,cnt = 0;
    cin >> n;
    vector<int> a(n+1), b(n+1), c(n+1),visited(n+1,0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) c[b[i]] = i;
    for (int i = 1; i <= n; i++) a[i] = c[a[i]];
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        int v = i;
        do{
            visited[v] = 1;
            v = a[v];
        }while(v != i);
        cnt++;
    }
    cout << n-cnt << "\n";
}