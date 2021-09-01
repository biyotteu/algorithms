#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;
  cin >> n;
  long long res = 5;
  for(int i=1;i<=n;i++) res = (res+3*i+1)%45678;
  cout << res;
}
