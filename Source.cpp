/*
������: �������� � �������� ���������, ����������� ������������
�������� �� ������� ������ ��������������� ����������� �� ������������ ������������ ������� ������.
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>

using namespace::std;
/*
S - ������� �������� ���������
l - ����� ������� ��������������
r - ������ ������� ��������������
prec - ��������� ������������� �������� ��������������
root[] - ������ ������ �������� �������� ������� 5
*/
double S, l, r, prec, a[5], root[5] = { -0.90617984593866399279762687829939,-0.53846931010568309103631442070021,0,0.53846931010568309103631442070021,0.90617984593866399279762687829939 };
string func;   //��������� ���������� ��� ������ ���� ������� � �������

// ������������� �������
/*
����� return ����� ������ ����� ������� ������ ��������������� �����������.
������� ������� ����� ������� � ������������.
*/
double f(double x) {
	//func = "x^7 + x^6";    return pow(x, 7) + pow(x, 6);
	func = "x";          return x;
	//func = "x^2";        return x*x;
	//func = "(sin(x))^2"; return sin(x)*sin(x);
	//func = "exp(x)";     return exp(x);
}

// ������������ ������������ ������� ������
double I(double a, double b) {
	return (b - a) / 2 * (f((a + b) / 2 - (b - a) / (2 * sqrt(3))) + f((a + b) / 2 + (b - a) / (2 * sqrt(3))));
}

// ����������� ������� �������� ���������
double sum(double l, double r, double prec) {
	double mid = (l + r) / 2;
	if (abs(I(l, mid) + I(mid, r) - I(l, r)) / (I(l, mid) + I(mid, r)) < prec) {
		S += I(l, r);
		cout << "I = " << I(l, r) << "\n";   //����� �������� ��������� �� ������������� ���������
		cout << "S = " << S << "\n";        //����� �������� �������� ��������� �� �������� ���������
		cout << "��������: " << abs(I(l, mid) + I(mid, r) - I(l, r)) / (I(l, mid) + I(mid, r)) << "\n";
		return S;
	}
	else {
		double ans = sum(l, mid, prec) + sum(mid, r, prec);
		return ans;
	}
}

int main() 
{
	setlocale(LC_ALL, "rus");
	cout << "������� ������� ��������������\n";
	cin >> l;      // ����� �������
	cin >> r;      // ������ �������
	cout << "������� ��������� ������������� �������� �������\n";
	cin >> prec;   // �������� ��������
	S = 0;         // �������� ��������� �� [l,r]
	if (l < r) {
		if (prec != 0) {
			sum(l, r, prec);
		}
		else {
			cout << "���������� ������� ������������� �������� ����������\n";
		}
	}
	else {
		cout << "��������� ������������ �������� �������� ������ ��������������\n";
	}
	// ����� �����������
	cout << "-----------------\n";
	cout << "������������� �������: " << func << "\n";
	cout << "������� ��������������: [" << l << "," << r << "]\n";
	cout << "��������� ��������: " << prec << '\n';
	cout << "S = " << S << "\n";

	return 0;
}
