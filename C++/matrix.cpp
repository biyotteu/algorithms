#include "matrix.h"
#include <iostream>

Matrix::Matrix(int x,int y) {
	this->size = { x,y };
	this->data.resize(x);
	for (int i = 0;i < x;i++) this->data[i].resize(y);
}
void Matrix::resize(int x,int y){
	this->size = { x,y };
	this->data.resize(x);
	for (int i = 0;i < x;i++) this->data[i].resize(y);
}
void Matrix::set(int x, int y, double value) {
	this->data[x][y] = value;
}
double Matrix::get(int x, int y) {
	return this->data[x][y];
}
void Matrix::print() {
	for (auto i : this->data) {
		for (auto j : i) cout << j << ' ';
		cout << "\n";
	}
}
Matrix Matrix::operator*(Matrix matrix) {
	Matrix tmp(this->size.first,matrix.size.second);
	for (int i = 0;i < this->size.first;i++) {
		for (int j = 0;j < matrix.size.second;j++) {
			double sum = 0;
			for (int k = 0;k < this->size.second;k++) sum += (this->get(i,k)*matrix.get(k,j));
			tmp.set(i,j,sum);
		}
	}
	return tmp;
}
Matrix Matrix::operator*(double x) {
	for (auto &i : this->data)
		for (double &j : i)
			j *= x;
	return *this;
}
Matrix Matrix::operator+(Matrix matrix){
	Matrix tmp(this->size.first,this->size.second);
	for(int i=0;i<this->size.first;i++)
		for (int j = 0;i < this->size.second;j++) {
			tmp.set(i, j, this->data[i][j] + matrix.data[i][j]);
		}
	return tmp;
}
Matrix Matrix::operator+(double x) {
	for (auto& i : this->data)
		for (double& j : i)
			j += x;
	return *this;
}
Matrix Matrix::operator-(Matrix matrix) {
	Matrix tmp(this->size.first, this->size.second);
	for (int i = 0;i < this->size.first;i++)
		for (int j = 0;i < this->size.second;j++) {
			tmp.set(i, j, this->data[i][j] - matrix.data[i][j]);
		}
	return tmp;
}
Matrix Matrix::operator-(double x) {
	for (auto& i : this->data)
		for (double& j : i)
			j -= x;
	return *this;
}
Matrix Matrix::operator/(double x) {
	for (auto& i : this->data)
		for (double& j : i)
			j /= x;
	return *this;
}
Matrix::~Matrix() {
	this->data.clear();
}