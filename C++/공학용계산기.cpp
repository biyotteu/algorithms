# include <iostream>
# include <string>
# include "math.h"
using namespace std;
const int stackSize = 10; // 스택크기 설정
const float PI = 3.1415925; // PI값 설정
//=============================
// 인터페이스를 위한 클래스
//=============================
class CInterface {
 private:
  unsigned int select;
 public:
  CInterface() {};
  ~CInterface() {};
  void Manual();
  int getSelect() { return select; } // 선택한 기능을 알려 주는 함수  void setSelect(int tmp) { select = tmp; }
};
//-----------------------------
// Manual을 보여주는 함수
//-----------------------------
void CInterface::Manual() {
 cout << " ---------------- 계산기 매뉴얼 ----------------" << endl;
 cout << "|                                               |" << endl;
 cout << "| ◎ 수식 예 : (1+s45)*L4+2-5/7                 |" << endl;
 cout << "|                                               |" << endl;
 cout << "| ◎ 삼각함수           |                       |" << endl;
 cout << "|    - sin : s (ex: s45)   - asin : S (ex :S45) |" << endl;
 cout << "|    - cos : c (ex: c45)   - acos : C (ex: C45) |" << endl;
 cout << "|    - tan : t (ex: t45)   - atan : T (ex: T45) |" << endl;
 cout << "|                                               |" << endl;
 cout << "| ◎ log함수                                    |" << endl;
 cout << "|    - log : l (ex: l10)                        |" << endl;
 cout << "|                                               |" << endl;
 cout << "| ◎ √ 연산                                    |" << endl;
 cout << "|    - √ : L (ex: L4)                          |" << endl;
 cout << "|                                               |" << endl;
 cout << " ----------------------------------------------- \n" << endl;
 do {
  select = 0;
  cout << "기능을 선택해 주세요(1:수식계산 | 2:진수변환 | 다른문자:종료)   ";
  cin >> select;
 } while( select != 1 && select != 2 && select != 0 );
}
//=============================
// 연산자를 저장하기 위한 스택 클래스
//=============================
class CCharStack {
 private:
  char stack[stackSize];
  int index;
  
 public:
  CCharStack() { index = -1; }
  ~CCharStack() {}
  void push(char ch) { stack[++index] = ch; }  char pop() { return stack[index--]; }
  char getElement() { return stack[index]; }
  int getIndex() { return index; }
};
//=============================
// 숫자를 저장하기 위한 스택 클래스
//=============================
class CIntStack {
 private:
  float stack[stackSize];
  int index;
  
 public:
  CIntStack() { index = -1; }
  ~CIntStack() {}
  void push(float num) { stack[++index] = num; }
  float pop() { return stack[index--]; }
};
//=============================
// 계산을 위한 클래스
//=============================
class CCalc {
 private:
  int result;
  int num, antilo;
  char reFormula[100];
  string formula;
  CCharStack chSt;
  CIntStack inSt;
  int Priority(char);   
  void Rearrange();
  float CalcSqrt(float);
  float CalcLog(float);
  float CalcTri(char, float);
  void CalcFormula();
  void CalcAntilogarithm();
 public:
  CCalc() {};
  ~CCalc() {};
  void setFormula(string str) { formula = str; Rearrange(); } // 수식을 받는 함수
  void setNum(int tmp) { num = tmp; } // 진수변환할 숫자를 받는 함수  void setAntilo(int tmp) { antilo = tmp; CalcAntilogarithm();} // 변환할 진수를 받는 함수
};
//-----------------------------
// 연산자 우선순위 반환 함수
//-----------------------------
int CCalc::Priority(char ch) {
 if (ch == 's' || ch =='S' || ch == 'c' || ch =='C' || ch == 't' || ch =='T' ||
  ch == 'l' || ch =='L')
  return 4;
 if (ch == '*' || ch == '/')
  return 3;
 if (ch == '+' || ch == '-')
  return 2;
 return 1;
}
//-----------------------------
// 계산할 공식 재배열 함수
//-----------------------------
void CCalc::Rearrange() 
{
 string temp(formula); // 받은 공식 temp에 복사
 int i = 0, j = 0;
 char ch;
 while (temp[i] != '\0') {
  if (temp[i] == ' ') // 공백일 경우
   i++;
  else if (isdigit(temp[i]) || temp[i]=='.') { // 숫자나 소수점일 경우
   while (isdigit(temp[i]) || temp[i]=='.')
    reFormula[j++] = temp[i++];
   reFormula[j++] = ' '; // 공백으로 구분
  }
  else if (temp[i] == '(') { // 여는 괄호일 경우
   chSt.push(temp[i]);
   i++;
  }
  else if (temp[i] == ')') { // 닫는 괄호일 경우
   ch = chSt.pop();
   while(ch != '(' ) { // pop된 요소가 여는 괄호일 경우 루프 탈출
    reFormula[j++] = ch; // pop된 요소가 연산자이므로 저장
    reFormula[j++] = ' '; // 공백으로 구분
    ch = chSt.pop();    
   }
   i++;  }
  else { // 연산자일 경우
   if (chSt.getIndex() == -1) // 스택이 비었을 경우
    chSt.push(temp[i++]);
   else {
    // 스택이 비어있지 않고 스택에 있는 연산자의 우선순위가 현재보다 높거나 같을 때
    while (!(chSt.getIndex() == -1) && ( Priority(chSt.getElement()) >= Priority(temp[i]) )) {
     ch = chSt.pop();
     reFormula[j++] = ch;
     reFormula[j++] = ' ';
    }
    chSt.push(temp[i]); // 현재 연산자 저장
    i++;
   }
  }
 }           // while문 끝
 while (!(chSt.getIndex() == -1)) { // 재배열 후 스택이 비어있지 않을 경우 남은 연산자 저장
  ch = chSt.pop();
  reFormula[j++] = ch;
  reFormula[j++] = ' ';
 }
 reFormula[j] = '\0';
 cout << "reFormula : " << reFormula << endl;
 CalcFormula();
}
//-----------------------------
// 수식 계산 함수
//-----------------------------
void CCalc::CalcFormula()
{
 int i = 0, k;
 float num, result, num1, num2;
 char ch;
 char token[20];
 while (reFormula[i] != '\0') {
  if (isdigit(reFormula[i]) || reFormula[i]=='.') { // // 숫자나 소수점일 경우
   k = 0;
   while (isdigit(reFormula[i]) || reFormula[i]=='.') // 숫자나 소수점일 동안
    token[k++] = reFormula[i++]; // token에 저장합니다.
   token[k] = '\0';
   num = atof(token); // atof으로 float형으로 변환
   inSt.push(num); // float형 스택에 저장합니다.  }
  else if (reFormula[i] == ' ') // 공백일 경우
   i++;
  // 삼각함수
  else if (reFormula[i] == 's' || reFormula[i] =='S' || reFormula[i] == 'c' || reFormula[i] =='C'
|| reFormula[i] == 't' || reFormula[i] =='T' ) {   
   result = CalcTri(reFormula[i], inSt.pop());
   inSt.push(result);
   i++;
  }
  else if (reFormula[i] == 'l') { // 로그 함수
   result = CalcLog(inSt.pop());
   inSt.push(result);
   i++;
  }
  else if (reFormula[i] == 'L') { // 루트 함수
   result = CalcSqrt(inSt.pop());
   inSt.push(result);
   i++;
  }
  else { // 연산자일 경우
   ch = reFormula[i++];
   num1 = inSt.pop(); // 스택이 숫자 2개를 꺼냄
   num2 = inSt.pop();
   if (ch == '+')
    result = num2 + num1;
   else if (ch == '-')
    result = num2 - num1;
   else if (ch == '*')
    result = num2 * num1;
   else if (ch == '/')
    result = num2 / num1;
   inSt.push(result); // 계산된 값을 다시 스택에 저장
  }
  i++;
 }           // while문 끝
 printf("Answer : %0.12f\n", inSt.pop());
}
//-----------------------------
// 루트 계산 함수
//    - 현재 2√값만 가능
//-----------------------------
float CCalc::CalcSqrt(float tmp) { return sqrt(tmp);
}
//-----------------------------
// 로그 계산 함수 
//    - 현재 log10값만 가능
//-----------------------------
float CCalc::CalcLog(float tmp) {
 return log10(tmp);
}
//-----------------------------
// 삼각함수 계산 함수
//-----------------------------
float CCalc::CalcTri(char ch, float tmp) {
 switch (ch) {
  case 's': // sin함수
   return sin(PI*tmp/180);
  case 'c': // cos함수
   return cos(PI*tmp/180);
  case 't': // tan함수
   return tan(PI*tmp/180);
  case 'S': // asin함수
   return asin(PI*tmp/180);
  case 'C': // acos함수
   return acos(PI*tmp/180);
  case 'T': // atan함수
   return atan(PI*tmp/180);
 }
 return 1;
}
//-----------------------------
// 진수 변환 함수
//-----------------------------
void CCalc::CalcAntilogarithm() {
 int bin[16];
 int i, count = 0;
 switch (antilo) {
  case 2: // 2진수
   while (num>0) {
     bin[count++] = num % 2;
     num /= 2;
   }
   bin[count] = '\0';
   cout << "answer: ";   for(i=0; i<count ; i++) {
    cout << bin[i];
   }
   cout << endl;
   break;
  case 8: // 3진수
   printf("answer: %o\n", num);
   break;
  case 16: // 16진수
   printf("answer: %x\n", num);
   break;
  default:
   cout << "Error!!!!!!!!!!" << endl;
   exit(0);
 }
}
//-----------------------------
// main 함수
//-----------------------------
void main()
{
 string str;
 int num=0;
 CInterface cInterface;
 CCalc cCalc;
 cInterface.Manual();
 switch (cInterface.getSelect()) {
  case 1:
   cout << "  수식 입력: ";
   cin >> str;      
   cCalc.setFormula(str);
   break;
  case 2:
   cout << "  숫자 입력: ";
   cin >> num;
   cCalc.setNum(num);
   cout << "  진수 입력(10진수 -> 2,8,16진수): ";
   cin >> num;
   cCalc.setAntilo(num);
   break;
  case 0:
   cout << "\n -- 종료됩니다 --" << endl;   exit(0);
 }
}