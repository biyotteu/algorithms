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


// ������ �켱���� ��ȯ �Լ�
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

// ���� ��迭
void Calculator::Rearrange()
{
    string temp(formula); // ���� ���� temp�� ����

    int i = 0, j = 0;
    char ch;

    while (temp[i] != '\0') {
        if (temp[i] == ' ') // ������ ���
            i++;
        else if (isdigit(temp[i]) || temp[i] == '.') { // ���ڳ� �Ҽ����� ���
            while (isdigit(temp[i]) || temp[i] == '.')
                reFormula[j++] = temp[i++];
            reFormula[j++] = ' '; // �������� ����
        }
        else if (temp[i] == '(') { // ���� ��ȣ�� ���
            chSt.push(temp[i]);
            i++;
        }
        else if (temp[i] == ')') { // �ݴ� ��ȣ�� ���
            ch = chSt.pop();
            while (ch != '(') { // pop�� ��Ұ� ���� ��ȣ�� ��� ���� Ż��
                reFormula[j++] = ch; // pop�� ��Ұ� �������̹Ƿ� ����
                reFormula[j++] = ' '; // �������� ����
                ch = chSt.pop();
            }
            i++;
        }
        else { // �������� ���
            if (chSt.getIndex() == -1) // ������ ����� ���
                chSt.push(temp[i++]);
            else {
                // ������ ������� �ʰ� ���ÿ� �ִ� �������� �켱������ ���纸�� ���ų� ���� ��
                while (!(chSt.getIndex() == -1) && (Priority(chSt.getElement()) >= Priority(temp[i]))) {
                    ch = chSt.pop();
                    reFormula[j++] = ch;
                    reFormula[j++] = ' ';
                }
                chSt.push(temp[i]); // ���� ������ ����
                i++;
            }
        }
    }           // while�� ��

    while (!(chSt.getIndex() == -1)) { // ��迭 �� ������ ������� ���� ��� ���� ������ ����
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
		if (isdigit(reFormula[i]) || reFormula[i] == '.') { // // ���ڳ� �Ҽ����� ���
			k = 0;
			while (isdigit(reFormula[i]) || reFormula[i] == '.') // ���ڳ� �Ҽ����� ����
				token[k++] = reFormula[i++]; // token�� �����մϴ�.
			token[k] = '\0';
			num = atof(token); // atof���� float������ ��ȯ
			inSt.push(num); // float�� ���ÿ� �����մϴ�.
		}
		else if (reFormula[i] == ' ') // ������ ���
			i++;
		// �ﰢ�Լ�
		else if (reFormula[i] == 's' || reFormula[i] == 'S' || reFormula[i] == 'c' || reFormula[i] == 'C' || reFormula[i] == 't' || reFormula[i] == 'T') {
			result = CalcTri(reFormula[i], inSt.pop());
			inSt.push(result);
			i++;
		}
		else if (reFormula[i] == 'l') { // �α� �Լ�
			result = CalcLog(inSt.pop());
			inSt.push(result);
			i++;
		}
		else if (reFormula[i] == 'L') { // ��Ʈ �Լ�
			result = CalcSqrt(inSt.pop());
			inSt.push(result);
			i++;
		}
		else { // �������� ���
			ch = reFormula[i++];
			num1 = inSt.pop(); // ������ ���� 2���� ����
			num2 = inSt.pop();
			if (ch == '+')
				result = num2 + num1;
			else if (ch == '-')
				result = num2 - num1;
			else if (ch == '*')
				result = num2 * num1;
			else if (ch == '/')
				result = num2 / num1;
			inSt.push(result); // ���� ���� �ٽ� ���ÿ� ����
		}
		i++;
	}           // while�� ��
	printf("��� : %0.12f\n", inSt.pop());
}

float Calculator::CalcSqrt(float tmp) {
	return sqrt(tmp);
}

float Calculator::CalcLog(float tmp) {
	return log10(tmp);
}

float Calculator::CalcTri(char ch, float tmp) {
	switch (ch) {
	case 's': // sin�Լ�
		return sin(PI*tmp / 180);
	case 'c': // cos�Լ�
		return cos(PI*tmp / 180);
	case 't': // tan�Լ�
		return tan(PI*tmp / 180);
	case 'S': // asin�Լ�
		return asin(PI*tmp / 180);
	case 'C': // acos�Լ�
		return acos(PI*tmp / 180);
	case 'T': // atan�Լ�
		return atan(PI*tmp / 180);
	}
	return 1;
}

// �⺻ ���� ���
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

// ���� ��ȯ ���
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
        cout << "��� : ";
        for (int i = cnt - 1; i >= 0; i--) {
            cout << bin[i];
        }
        cout << "(2)" << endl;
        break;
    case 8:
        cout << "��� : " << oct << num << "(8)" << endl;
        break;
    case 16:
        cout << "��� : " << hex << num << "(16)" << endl;
        break;
    default:
        cout << "��ȯ�� �Ұ����մϴ�." << endl;
        cout << "(10���� -> 2����, 8����, 16���� ����)" << endl;
    }
}

// degree&radian ��ȯ ���
void Calculator::Degree_Radian() {
    double rad, deg;
    if (antilo == 1)
    {
        rad = num * PI / 180;
        cout << "����" << num << "�� ���� = " << rad << endl;
    }
    else if (antilo == 2)
    {
        deg = num * 180 / PI;
        cout << "����" << num << "�� ���� = " << deg << endl;
    }
}

// 2�������� �� ���
void Calculator::Quadratic_Form() {
    double a = poly.sec_term;
    double b = poly.fir_term;
    double c = poly.con_term;
    double tmp1, tmp2;
    if (D() == 0) {
        tmp1 = (-b + pow((pow(b, 2) - 4 * a * c), 1.0 / 2.0)) / (2 * a);
        cout << "���� 1�� �Դϴ�" << endl;
        cout << "x = " << tmp1 << endl;
    }
    else if (D() > 0) {
        tmp1 = (-b + pow((pow(b, 2) - 4 * a * c), 1.0 / 2.0)) / (2 * a);
        tmp2 = (-b - pow((pow(b, 2) - 4 * a * c), 1.0 / 2.0)) / (2 * a);
        cout << "���� 2�� �Դϴ�" << endl;
        cout << "x = " << tmp1 << endl;
        cout << "x = " << tmp2 << endl;
    }
	else if (D() < 0) {
		cout << "D < 0 : �ذ� �������� �ʽ��ϴ�." << endl;
	}
}

// �Ǻ���
double Calculator::D() {
    double D;
    D = pow(poly.fir_term, 2) - 4 * poly.sec_term * poly.con_term;
    return D;
}

// �ﰢ�Լ� ���
void Calculator::Trigonometric(int sel) {
    double num = deg;
    while (num > 90) {
        num = num - 90;
    }
    if (sel == 1)
        cout << "sin(" << deg << "��) = " << sin(num * PI / 180) << endl;
    else if (sel == 2)
        cout << "cos(" << deg << "��) = " << cos(num * PI / 180) << endl;
    else if (sel == 3)
        cout << "tan(" << deg << "��) = " << tan(num * PI / 180) << endl;
    else if (sel == 4)
        cout << "arcsin(" << deg << ") = " << asin(deg) << endl;
    else if (sel == 5)
        cout << "arccos(" << deg << ") = " << acos(deg) << endl;
    else if (sel == 6)
        cout << "arctan(" << deg << ") = " << atan(deg) << endl;
}

// ���丮�� ���
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

// ���� �������̽�
void Interface::mainmenu() {
    cout << "=========<MENU>=========" << endl;
    cout << "| 1.�⺻ ����          |" << endl;
    cout << "| 2.���� ��ȯ          |" << endl;
    cout << "| 3.degree&radian ��ȯ |" << endl;
    cout << "| 4.������ �� ���     |" << endl;
    cout << "| 5.�ﰢ�Լ� ���      |" << endl;
    cout << "| 6.���丮�� ���      |" << endl;
	cout << "| 7.������ ���        |" << endl;
    cout << "| 8.����               |" << endl;
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
        cout << "Error!! 1~7 �߿� �Է��ϼ���" << endl;
    }
}



// �⺻ ���� �������̽�
/*void Interface::menu1() {
    char op;
    cout << "=====<�⺻���� �Է� ����>=====" << endl;
    cout << "|        ���� : 2 + 3        |" << endl;
    cout << "|        ���� : 2 - 3        |" << endl;
    cout << "|        ���� : 2 * 3        |" << endl;
    cout << "|       ������ : 2 / 3       |" << endl;
    cout << "|        ���� : 2 ^ 3        |" << endl;
    cout << "==============================" << endl;
    cout << "                              " << endl;
    cout << "�� ������ �����ڸ� �Է����ּ���" << endl;
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

//�⺻ ���� �������̽�
void Interface::menu1() {
	string str;

	cout << "===============<�⺻���� �Է� ��>===============" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -���� �� : (1+s45)*L4+2-5/7                 |" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -�ﰢ�Լ�                                   |" << endl;
	cout << "|    - sin : s (ex: s45)   - asin : S (ex :S45)|" << endl;
	cout << "|    - cos : c (ex: c45)   - acos : C (ex: C45)|" << endl;
	cout << "|    - tan : t (ex: t45)   - atan : T (ex: T45)|" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -log�Լ�                                    |" << endl;
	cout << "|    - log : l (ex: l10)                       |" << endl;
	cout << "|                                              |" << endl;
	cout << "|  -�� ����                                    |" << endl;
	cout << "|    - �� : L (ex: L4)                         |" << endl;
	cout << "|                                              |" << endl;
	cout << " ----------------------------------------------- \n" << endl;

	cout << "���� �Է�: ";
	cin >> str;
	setFormula(str);
}

// ���� ��ȯ �������̽�
void Interface::menu2() {
    cout << "������ȯ�� ���ڸ� �Է��ϼ��� >> ";
    cin >> tmp;
    setNum(tmp);
    cout << "��ȯ�� ������ �Է��ϼ��� >> ";
    cin >> tmp;
    setAntilo(tmp);
    Antilogorithm();
}

// degree&radian ��ȯ �������̽�
void Interface::menu3() {
    int sel;
    cout << "degree->radian : 1 or radian->degree : 2 >> ";
    cin >> sel;
    switch (sel) {
    case 1:
        cout << "��ȯ�� ������ �Է��ϼ��� >> ";
        cin >> tmp;
        setNum(tmp);
        setAntilo(sel);
        Degree_Radian();
        break;
    case 2:
        cout << "��ȯ�� ������ �Է��ϼ��� >> ";
        cin >> tmp;
        setNum(tmp);
        setAntilo(sel);
        Degree_Radian();
        break;
    default:
        cout << "Error!! 1�� 2 �� �ϳ��� �Է��ϼ���" << endl;
    }
}

// ���׽� �� ���
void Interface::menu4() {
    cout << "2�� �������� �Է��� �ּ���. ax^2 + bx + c " << endl;
    cout << "a >> ";
    cin >> poly.sec_term;
    cout << "b >> ";
    cin >> poly.fir_term;
    cout << "c >> ";
    cin >> poly.con_term;
    cout << "* �Էµ� 2�� ������" << endl;
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

// �ﰢ�Լ� ��� �������̽�
void Interface::menu5() {
    cout << "==========<�ﰢ�Լ�>=========" << endl;
    cout << "|                           |" << endl;
    cout << "| 1. sin(����)  4. arcsin(x)|" << endl;
    cout << "|                           |" << endl;
    cout << "| 2. cos(����)  5. arccos(x)|" << endl;
    cout << "|                           |" << endl;
    cout << "| 3. tan(����)  6. arctan(x)|" << endl;
    cout << "|                           |" << endl;
    cout << "| * -1 �� x �� 1            |" << endl;
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
            cout << "Error!! 1~6 �߿� �Է��ϼ���" << endl;
    }
    cin >> deg;
    Trigonometric(select);
}

// ���丮�� ��� �������̽�
void Interface::menu6() {
    cout << "���ڸ� �Է��ϼ��� >> ";
    cin >> tmp;
    setNum(tmp);
    Factorial();
}

// ������ �������̽�
void Interface::menu7() {
	cout << "�������� ������ �Է��ϼ���" << endl;
	cout << ">> ";
	cin >> order;
	for (int i = order; i >= 0; i--) {
		cout << i << "������ ��� >> ";
		cin >> coef_1[i];
	}
	cout << "�Էµ� ������" << endl;
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
	cout << "==========<������>==========" << endl;
	cout << "|                          |" << endl;
	cout << "|   1. �̺�      2. ����   |" << endl;
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
			cout << "Error!! 1 / 2 �߿� �Է��ϼ���" << endl;
	}
}

// ���� �������̽�
void Interface::menu8() {
    cout << "���⸦ �����մϴ�." << endl;
}