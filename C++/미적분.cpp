//31031 김민섭 
#include <bits/stdc++.h>
#include <windows.h>
#include <cmath>
using namespace std;
using dd = double;

#pragma execution_character_set( "utf-8" )

int main(){
	SetConsoleOutputCP(65001);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(15);
	dd x,n;
	cout << "input your value: ";
	cin >> x;
	cout << x <<"\n";
	cout << "input limit constant: ";
	cin >> n;
	cout << n << "\n\n";
	dd exp,ln,sin,factorial = 1.0; // exp = e^x , ln = ln(x+1) , sin = sinθ 결과값을 저장

	//e^x
	for(dd i=0;i<=n;i++){
		exp += pow(x,i)/factorial;  // pow(x,i) = x의 i 제곱 
		if(i) factorial *= i;
	}
	//ln(x+1)
	ln = 0;
	for(dd i=1;i<=n;i++){
		ln += (-pow(-1,i)*pow(x,i)/i);
	}
	factorial = 1.0;
	//sinθ 
	sin = 0;
	for(dd i=0;i<=n;i++){
		if(i) factorial *= (2*i+1)*2*i;
		sin += pow(-1,i)*pow(x,2*i+1)/factorial;
	}    
    cout << "###############################################\n\n";
	cout << "e^x의 실제 값: " <<  std::exp(x) << "\n";
	cout << "테일러 급수를 이용한 e^x 근사값: " << exp << "\n";
	cout << "###############################################\n\n";
	cout << "ln(x+1) 실제 값: " << log(x+1) << "\n";
	cout << "테일러 급수를 이용한 ln(x+1) 근사값: " << ln << "\n\n";
	cout << "###############################################\n\n";
	cout << "sinθ의 실제 값: " <<  std::sin(x) << "\n";
	cout << "테일러 급수를 이용한 sinθ 근사값: " << sin << "\n";
	cout << "###############################################\n\n";
	
}