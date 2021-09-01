#include <bits/stdc++.h>

using namespace std;

class Converter{
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) {this->ratio = ratio;}
	void run(){
		double src;
		cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다.";
		cout << getSourceString() << "을 입력하세요>> ";
		cin >> src;
		cout << "변환 결과 : " << convert(src) << getDestString() << endl;
	}
}
class WonToDollar : public Converter{
	
}
int main() {
  WonToDollar wd(1010); // 1 달러에 1010원
  wd.run();
  system("pause");
  return 0;
}