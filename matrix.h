#pragma once
#include "vector.h"

class matrix
{
private:
	vector* arr = nullptr;
	int n = 0; // colons
	int m = 0; // lines
public:
	matrix() {};

	matrix(int m,int n =0):m(m),n(n)
	{
		arr = new vector[m];
		for (int i = 0; i < m; i++)
		{
			arr[i] = vector(n);
		}
	}
	matrix(vector* mat, int n,int m):m(m),n(n)
	{
		arr = new vector[m];
		for (int i = 0; i < m; i++)
		{
			this->arr[i] = mat[i];
		}
	}
	matrix(const matrix & a):m(a.m)
	{
		arr = new vector[a.m];
		for (int i = 0; i < a.m; i++)
			this->arr[i] = a.arr[i];
	}
	matrix(double** arr_m, int m, int n) :m(m), n(n)
	{
		arr = new vector[m];
		for (int i = 0; i < m; i++)
		{
			arr[i] = vector(arr_m[i], n);
		}
	}
	void print() const;

	matrix& transp();

	matrix operator+(const matrix& mat) const;

	matrix operator-(const matrix& mat) const;

	matrix operator*(const double& x) const;

	matrix operator/(const double& x) const;

	matrix operator*(const matrix& mat) const;

	int pows(int i) const;

	matrix mk_mat(int i, const matrix& mat) const;//вычисление миноров

	double det() const;
	
	matrix& operator=(const matrix& a);
	
	~matrix()
	{
		delete[] arr;
	}
   
};