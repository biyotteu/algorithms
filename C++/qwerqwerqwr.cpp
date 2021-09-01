#include <iostream>
#include <string>

using namespace std;

class Account{
private:
	int money,code;
	string owner;
public:
	Account(int a,int b,string c);//생성자
	string getOwner();//주인 이름을 반환하는 함수
	int inquiry();//잔액을 반환
	void deposit(int a);//예금
	int withdraw(int a);//출금
};
Account::Account(int a,int b,string c):money(a),code(b),owner(c){};
// Account::Account(int a,int b,string c){
// 	money = a;
// 	code = b;
// 	owner = c;
// };
string Account::getOwner(){
	return owner;
}
int Account::inquiry(){
	return money;
}
void Account::deposit(int a){
	money += a;
}
int Account::withdraw(int a){
	if(money < a) return 0;
	else{
		money -= a;
		return a;
	}
}
int main(){
	Account a(5000,1,"kitae"); a.deposit(50000);
	cout << a.getOwner() << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner()  << a.inquiry() << endl;
	return 0;
}