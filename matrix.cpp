#include "matrix.h"
#include <iostream>

void matrix::print() const
{
	for (int i = 0; i < this->m; i++)
		this->arr[i].print();
}

matrix& matrix::transp()
{
	matrix b(*this);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
		{
			this->arr[i][j] = b.arr[j][i];
		}
	}
	return *this;

}
matrix matrix::operator+(const matrix& mat) const
{
	matrix c(this->m);
	for (int i = 0; i < m; i++)
	{
		c.arr[i] = this->arr[i] + mat.arr[i];

	}
	return c;
}
matrix matrix::operator-(const matrix& mat) const
{
	matrix c(this->m);
	for (int i = 0; i < m; i++)
	{
		c.arr[i] = this->arr[i] - mat.arr[i];

	}
	return c;
}
matrix matrix::operator*(const double& x) const
{
	matrix c(this->m);
	for (int i = 0; i < m; i++)
	{
		c.arr[i] = this->arr[i] * x;

	}
	return c;
}
matrix matrix::operator/(const double& x) const
{
	if (x == 0) throw 0;
	matrix c(this->m);
	for (int i = 0; i < m; i++)
	{
		c.arr[i] = this->arr[i] / x;
	}
	return c;
}

matrix matrix::operator*(const matrix& mat) const
{
	if (this->n != mat.m) throw 0;

	matrix c(this->m, mat.n);
	for (int i = 0; i < c.m; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			for (int k = 0; k < mat.m; k++)
				c.arr[i][j] += this->arr[i][k] * mat.arr[k][j];
		}
	}
	return c;
}

int matrix::pows(int i) const
{
	int res = -1;//переменна€ дл€ учета степени -1
	for (int k = 0; k < i; k++)
	{
		res *= -1;
	}

	return res;

}
matrix matrix::mk_mat(int i, const matrix& mat) const//вычисление миноров
{
	matrix New(mat.m - 1, mat.n - 1);

	for (int j = 0; j < i; j++)
	{
		for (int h = 0; h < New.n; h++)
		{
			New.arr[j][h] = this->arr[j][h + 1];
		}
	}
	for (int j = i + 1; j < m; j++)
	{
		for (int h = 0; h < New.n; h++)
		{
			New.arr[j - 1][h] = this->arr[j][h + 1];
		}
	}
	return New;
}
double matrix::det() const
{
	//разложение по первому столбцу
	if (this->n != this->m || m <= 0) throw 0;

	double det = 0;
	if (m > 2)
	{
		for (int i = 0; i < m; i++)
		{
			int min = pows(i);
			matrix a = mk_mat(i, *this);
			det += this->arr[i][0] * min * a.det();
		}
	}
	if (m == 2)
	{
		det = (this->arr[0][0] * this->arr[1][1]) - (this->arr[0][1] * this->arr[1][0]);//подсчет детерминанта 2*2
	}
	if (m == 1) det = arr[0][0];
	return det;

}
matrix& matrix::operator=(const matrix& a)
{
	if (&a == this)
	{
		return *this;
	}
	this->m = a.m;
	delete[] arr;
	arr = new vector[m];
	for (int i = 0; i < this->m; i++)
	{
		this->arr[i] = a.arr[i];
	}
	return *this;
}