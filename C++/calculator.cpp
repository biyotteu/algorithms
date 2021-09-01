#include "calculator.h"
#include "poly.h"
#include <iostream>
#include<string>
#include<cmath>
#include<stack>
#include<vector>
#include<stdlib.h>
#include<time.h>

int order = 0;
double PI = 3.141592;


// 연산자 우선순위 반환 함수
int Calculator::Priority(char ch) {
    if (ch == 's' || ch == 'S' || ch == 'c' || ch == 'C' || ch == 't' || ch == 'T' ||
        ch == 'l' || ch == 'L')
        return 4;
    if (ch == '*' || ch == '/')
        return 3;
    if (ch == '+' || ch == '-')
        return 2;
    return 1;
}

// 공식 재배열
void Calculator::Rearrange()
{
    string temp(formula); // 받은 공식 temp에 복사

    int i = 0, j = 0;
    char ch;

    while (temp[i] != '\0') {
        if (temp[i] == ' ') // 공백일 경우
            i++;
        else if (isdigit(temp[i]) || temp[i] == '.') { // 숫자나 소수점일 경우
            while (isdigit(temp[i]) || temp[i] == '.')
                reFormula[j++] = temp[i++];
            reFormula[j++] = ' '; // 공백으로 구분
        }
        else if (temp[i] == '(') { // 여는 괄호일 경우
            chSt.push(temp[i]);
            i++;
        }
        else if (temp[i] == ')') { // 닫는 괄호일 경우
            ch = chSt.pop();
            while (ch != '(') { // pop된 요소가 여는 괄호일 경우 루프 탈출
                reFormula[j++] = ch; // pop된 요소가 연산자이므로 저장
                reFormula[j++] = ' '; // 공백으로 구분
                ch = chSt.pop();
            }
            i++;
        }
        else { // 연산자일 경우
            if (chSt.getIndex() == -1) // 스택이 비었을 경우
                chSt.push(temp[i++]);
            else {
                // 스택이 비어있지 않고 스택에 있는 연산자의 우선순위가 현재보다 높거나 같을 때
                while (!(chSt.getIndex() == -1) && (Priority(chSt.getElement()) >= Priority(temp[i]))) {
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

    CalcFormula();
}

void Calculator::CalcFormula()
{
	int i = 0, k;
	float num, result, num1, num2;
	char ch;
	char token[20];

	while (reFormula[i] != '\0') {
		if (isdigit(reFormula[i]) || reFormula[i] == '.') { // // 숫자나 소수점일 경우
			k = 0;
			while (isdigit(reFormula[i]) || reFormula[i] == '.') // 숫자나 소수점일 동안
				token[k++] = reFormula[i++]; // token에 저장합니다.
			token[k] = '\0';
			num = atof(token); // atof으로 float형으로 변환
			inSt.push(num); // float형 스택에 저장합니다.
		}
		else if (reFormula[i] == ' ') // 공백일 경우
			i++;
		// 삼각함수
		else if (reFormula[i] == 's' || reFormula[i] == 'S' || reFormula[i] == 'c' || reFormula[i] == 'C' || reFormula[i] == 't' || reFormula[i] == 'T') {
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
	printf("결과 : %0.12f\n", inSt.pop());
}

float Calculator::CalcSqrt(float tmp) {
	return sqrt(tmp);
}

float Calculator::CalcLog(float tmp) {
	return log10(tmp);
}

float Calculator::CalcTri(char ch, float tmp) {
	switch (ch) {
	case 's': // sin함수
		return sin(PI*tmp / 180);
	case 'c': // cos함수
		return cos(PI*tmp / 180);
	case 't': // tan함수
		return tan(PI*tmp / 180);
	case 'S': // asin함수
		return asin(PI*tmp / 180);
	case 'C': // acos함수
		return acos(PI*tmp / 180);
	case 'T': // atan함수
		return atan(PI*tmp / 180);
	}
	return 1;
}

// 기본 연산 계산
void Calculator::Calculation() {
    int result;
    double result_;
    if (antilo == 1)
    {
        result = num + num2;
        cout << ">> " << result << endl;
    }
    else if (antilo == 2)
    {
        result = num - num2;
        cout << ">> " << result << endl;
    }
    else if (antilo == 3)
    {
        result = num * num2;
        cout << ">> " << result << endl;
    }
    else if (antilo == 4)
    {
        result_ = (double)num / (double)num2;
        cout << ">> " << result_ << endl;
    }
    else if (antilo == 5)
    {
        result = pow(num, num2);
        cout << ">> " << result << endl;
    }
}

// 진수 변환 계산
void Calculator::Antilogorithm() {
    int bin[16];
    int cnt = 0;
    switch (antilo) {
    case 2:
        while (num > 0) {
            if (num % 2 == 1) bin[cnt++] = 1;
            else bin[cnt++] = 0;
            num /= 2;
        }
        cout << "결과 : ";
        for (int i = cnt - 1; i >= 0; i--) {
            cout << bin[i];
        }
        cout << "(2)" << endl;
        break;
    case 8:
        cout << "결과 : " << oct << num << "(8)" << endl;
        break;
    case 16:
        cout << "결과 : " << hex << num << "(16)" << endl;
        break;
    default:
        cout << "변환이 불가능합니다." << endl;
        cout << "(10진수 -> 2진수, 8진수, 16진수 가능)" << endl;
    }
}

// degree&radian 변환 계산
void Calculator::Degree_Radian() {
    double rad, deg;
    if (antilo == 1)
    {
        rad = num * PI / 180;
        cout << "각도" << num << "의 라디안 = " << rad << endl;
    }
    else if (antilo == 2)
    {
        deg = num * 180 / PI;
        cout << "라디안" << num << "의 각도 = " << deg << endl;
    }
}

// 2차방정식 해 계산
void Calculator::Quadratic_Form() {
    double a = poly.sec_term;
    double b = poly.fir_term;
    double c = poly.con_term;
    double tmp1, tmp2;
    if (D() == 0) {
        tmp1 = (-b + pow((pow(b, 2) - 4 * a * c), 1.0 / 2.0)) / (2 * a);
        cout << "근이 1개 입니다" << endl;
        cout << "x = " << tmp1 << endl;
    }
    else if (D() > 0) {
        tmp1 = (-b + pow((pow(b, 2) - 4 * a * c), 1.0 / 2.0)) / (2 * a);
        tmp2 = (-b - pow((pow(b, 2) - 4 * a * c), 1.0 / 2.0)) / (2 * a);
        cout << "근이 2개 입니다" << endl;
        cout << "x = " << tmp1 << endl;
        cout << "x = " << tmp2 << endl;
    }
	else if (D() < 0) {
		cout << "D < 0 : 해가 존재하지 않습니다." << endl;
	}
}

// 판별식
double Calculator::D() {
    double D;
    D = pow(poly.fir_term, 2) - 4 * poly.sec_term * poly.con_term;
    return D;
}

// 삼각함수 계산
void Calculator::Trigonometric(int sel) {
    double num = deg;
    while (num > 90) {
        num = num - 90;
    }
    if (sel == 1)
        cout << "sin(" << deg << "°) = " << sin(num * PI / 180) << endl;
    else if (sel == 2)
        cout << "cos(" << deg << "°) = " << cos(num * PI / 180) << endl;
    else if (sel == 3)
        cout << "tan(" << deg << "°) = " << tan(num * PI / 180) << endl;
    else if (sel == 4)
        cout << "arcsin(" << deg << ") = " << asin(deg) << endl;
    else if (sel == 5)
        cout << "arccos(" << deg << ") = " << acos(deg) << endl;
    else if (sel == 6)
        cout << "arctan(" << deg << ") = " << atan(deg) << endl;
}

// 팩토리얼 계산
void Calculator::Factorial() {
    long long int sum = 1;
    for (int i = 1; i < num + 1; i++)
    {
        sum = sum * i;
    }
    cout << num << "!=" << sum << endl;
}

void Calculator::Differential() {
	for (int i = order; i > 0; i--) {
		coef_2[i - 1] = coef_1[i] * i;
	}
	for (int i = order - 1; i >= 0; i--) {
		if (i == 0) {
			if(coef_2[i] > 0) cout << "+ " << coef_2[i] << endl;
			else cout << coef_2[i] << endl;
		}
		else if (coef_2[i] > 0 && i != order - 1)
			cout << "+" << coef_2[i] << "x^" << i << " ";
		else
			cout << coef_2[i] << "x^" << i << " ";
	}
	cout << endl;
}

void Calculator::Integral() {
	for (int i = order; i >= 0; i--) {
		coef_2[i + 1] = coef_1[i] / (i + 1);
	}
	for (int i = order + 1; i > 0; i--) {
		if (coef_2[i] > 0 && i != order + 1)
			cout << "+" << coef_2[i] << "x^" << i << " ";
		else
			cout << coef_2[i] << "x^" << i << " ";
	}
	cout<< "+ C" << endl;
}

// 메인 인터페이스
void Interface::mainmenu() {
    cout << "=========<MENU>=========" << endl;
    cout << "| 1.기본 연산          |" << endl;
    cout << "| 2.진수 변환          |" << endl;
    cout << "| 3.degree&radian 변환 |" << endl;
    cout << "| 4.방정식 해 계산     |" << endl;
    cout << "| 5.삼각함수 계산      |" << endl;
    cout << "| 6.팩토리얼 계산      |" << endl;
	cout << "| 7.미적분 계산        |" << endl;
    cout << "| 8.종료               |" << endl;
    cout << "========================" << endl;
    select = 0;
    cout << ">> ";
    cin >> select;
    switch (select) {
    case 1:
        menu1();
        break;
    case 2:
        menu2();
        break;
    case 3:
        menu3();
        break;
    case 4:
        menu4();
        break;
    case 5:
        menu5();
        break;
    case 6:
        menu6();
        break;
    case 7:
        menu7();
        break;
	case 8:
		menu8();
		break;
    default:
        cout << "Error!! 1~7 중에 입력하세요" << endl;
    }
}



// 기본 연산 인터페이스
/*void Interface::menu1() {
    char op;
    cout << "=====<기본연산 입력 예시>=====" << endl;
    cout << "|        덧셈 : 2 + 3        |" << endl;
    cout << "|        뺄셈 : 2 - 3        |" << endl;
    cout << "|        곱셈 : 2 * 3        |" << endl;
    cout << "|       나눗셈 : 2 / 3       |" << endl;
    cout << "|        제곱 : 2 ^ 3        |" << endl;
    cout << "==============================" << endl;
    cout << "                              " << endl;
    cout << "두 정수와 연산자를 입력해주세요" << endl;
    cin >> tmp >> op >> tmp_;
    setNum(tmp);
    setNum2(tmp_);
    switch (op) {
    case '+':
        setAntilo(1);
        Calculation();
        break;
    case '-':
        setAntilo(2);
        Calculation();
        break;
    case '*':
        setAntilo(3);
        Calculation();
        break;
    case '/':
        setAntilo(4);
        Calculation();
        break;
    case '^':
        setAntilo(5);
        Calculation();
        break;
    }
}*/

//기본 연산 인터페이스
void Interface::menu1() {
	string str;

	cout << "===============<기본연산 입력 예>===============" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -수식 예 : (1+s45)*L4+2-5/7                 |" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -삼각함수                                   |" << endl;
	cout << "|    - sin : s (ex: s45)   - asin : S (ex :S45)|" << endl;
	cout << "|    - cos : c (ex: c45)   - acos : C (ex: C45)|" << endl;
	cout << "|    - tan : t (ex: t45)   - atan : T (ex: T45)|" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -log함수                                    |" << endl;
	cout << "|    - log : l (ex: l10)                       |" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -√ 연산                                    |" << endl;
	cout << "|    - √ : L (ex: L4)                         |" << endl;
	cout << "|                                              |" << endl;
	cout << " ----------------------------------------------- \n" << endl;

	cout << "수식 입력: ";
	cin >> str;
	setFormula(str);
}

// 진수 변환 인터페이스
void Interface::menu2() {
    cout << "진수변환할 숫자를 입력하세요 >> ";
    cin >> tmp;
    setNum(tmp);
    cout << "변환할 진수를 입력하세요 >> ";
    cin >> tmp;
    setAntilo(tmp);
    Antilogorithm();
}

// degree&radian 변환 인터페이스
void Interface::menu3() {
    int sel;
    cout << "degree->radian : 1 or radian->degree : 2 >> ";
    cin >> sel;
    switch (sel) {
    case 1:
        cout << "변환할 각도를 입력하세요 >> ";
        cin >> tmp;
        setNum(tmp);
        setAntilo(sel);
        Degree_Radian();
        break;
    case 2:
        cout << "변환할 라디안을 입력하세요 >> ";
        cin >> tmp;
        setNum(tmp);
        setAntilo(sel);
        Degree_Radian();
        break;
    default:
        cout << "Error!! 1과 2 중 하나를 입력하세요" << endl;
    }
}

// 다항식 해 계산
void Interface::menu4() {
    cout << "2차 방정식을 입력해 주세요. ax^2 + bx + c " << endl;
    cout << "a >> ";
    cin >> poly.sec_term;
    cout << "b >> ";
    cin >> poly.fir_term;
    cout << "c >> ";
    cin >> poly.con_term;
    cout << "* 입력된 2차 방정식" << endl;
    cout << poly.sec_term << "x^2";
    if (poly.fir_term < 0)
        cout << poly.fir_term << "x";
    else if (poly.fir_term > 0)
        cout << "+" << poly.fir_term << "x";
    else
        cout << "";

    if (poly.con_term < 0)
        cout << "" << poly.con_term;
    else if (poly.con_term > 0)
        cout << "+" << poly.con_term;
    else
        cout << "";
    cout << endl << endl;
    Quadratic_Form();
}

// 삼각함수 계산 인터페이스
void Interface::menu5() {
    cout << "==========<삼각함수>=========" << endl;
    cout << "|                           |" << endl;
    cout << "| 1. sin(각도)  4. arcsin(x)|" << endl;
    cout << "|                           |" << endl;
    cout << "| 2. cos(각도)  5. arccos(x)|" << endl;
    cout << "|                           |" << endl;
    cout << "| 3. tan(각도)  6. arctan(x)|" << endl;
    cout << "|                           |" << endl;
    cout << "| * -1 ≤ x ≤ 1            |" << endl;
    cout << "|                           |" << endl;
    cout << "=============================" << endl;
    while (1) {
        cout << ">> ";
        cin >> select;
        if (select == 1) {
            cout << "sin ";
            break;
        }
        else if (select == 2) {
            cout << "cos ";
            break;
        }
        else if (select == 3) {
            cout << "tan ";
            break;
        }
        else if (select == 4) {
            cout << "arcsin ";
            break;
        }
        else if (select == 5) {
            cout << "arccos ";
            break;
        }
        else if (select == 6) {
            cout << "arctan ";
            break;
        }
        else
            cout << "Error!! 1~6 중에 입력하세요" << endl;
    }
    cin >> deg;
    Trigonometric(select);
}

// 팩토리얼 계산 인터페이스
void Interface::menu6() {
    cout << "숫자를 입력하세요 >> ";
    cin >> tmp;
    setNum(tmp);
    Factorial();
}

// 미적분 인터페이스
void Interface::menu7() {
	cout << "방정식의 차수를 입력하세요" << endl;
	cout << ">> ";
	cin >> order;
	for (int i = order; i >= 0; i--) {
		cout << i << "차항의 계수 >> ";
		cin >> coef_1[i];
	}
	cout << "입력된 방정식" << endl;
	for (int i = order; i >= 0; i--) {
		if (i == 0) {
			if (coef_1[i] > 0) cout << "+ " << coef_1[i] << endl;
			else cout << coef_1[i] << endl;
		}
		else if (coef_1[i] > 0 && i != order)
			cout << "+" << coef_1[i] << "x^" << i << " ";
		else
			cout << coef_1[i] << "x^" << i << " ";
	}
	cout << endl;
	cout << "==========<미적분>==========" << endl;
	cout << "|                          |" << endl;
	cout << "|   1. 미분      2. 적분   |" << endl;
	cout << "|                          |" << endl;
	cout << "============================" << endl;
	while (1) {
		cout << ">> ";
		cin >> select;
		if (select == 1) {
			Differential();
			break;
		}
		else if (select == 2) {
			Integral();
			break;
		}
		else
			cout << "Error!! 1 / 2 중에 입력하세요" << endl;
	}
}

// 종료 인터페이스
void Interface::menu8() {
    cout << "계산기를 종료합니다." << endl;
}