#include <bits/stdc++.h>

using namespace std;

vector<int> par;
int n;
int _find(int v){
    if(v == par[v]) return v;
    return par[v] = _find(par[v]);
}
int main(int argc, char** argv)
{
	int t;
	cin >> t;
	for(int j=1;j<=t;j++){
	    cin >> n;
	    par.resize(n+1);
	    for(int i=1;i<=n;i++) par[i] = i;
	    for(int i=1;i<=n;i++){
	        int x;
	        cin >> x;
	        if(x+i > n) continue;
	        par[_find(i+x)] = par[_find(i)];
	    }
	    set<int> st;
	    for(int i=1;i<=n;i++) st.insert(_find(par[i]));
	    cout << "Case #" << j << "\n";
	    cout << st.size() << "\n";
	}
}