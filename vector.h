#pragma once
#include <iostream>

class vector {
private:

	double* data = nullptr;
	int n = 0;
public:
	vector()
	{

	}
	vector(int n) :n(n)
	{
		if (n <= 0)
		{
			return;
		}

		data = new double[n];
		for (int i = 0; i < n; i++)
		{
			this->data[i] = 0;
		}
	}
	vector(const vector& v) :n(v.n)
	{
		data = new double[v.n];
		for (int i = 0; i < v.n; i++)
		{
			this->data[i] = v.data[i];
		}
	}

	vector(double* arr, int n) :n(n)
	{
		data = new double[n];
		for (int i = 0; i < this->n; i++)
		{
			this->data[i] = *(arr + i);
		}
	}

	double get_element(const int& index) const
	{
		if (index < this->n)
			return *(data + index);
		else
			throw "Wrong index!";

	}
	double& operator[](const int& index)
	{
		return *(data + index);
	}
	void set_element(const int& index,const double& value)
	{
		if (index < this->n)
			*(data + index) = value;
		else
			throw "Wrong index!";
	}

	vector sub(const vector& v) const
	{
		if (v.n != this->n) throw 0;

		vector c(this->n);
		for (int i = 0; i < n; i++)
		{
			c.data[i] = this->data[i] - v.data[i];
		}
		return c;
	}
	vector operator-(const vector& b) const {

		return this->sub(b);
	}

	double scalar_mul(const vector& v) const
	{

		double s_mul = 0;
		for (int i = 0; i < this->n; i++)
		{
			s_mul += v.data[i] * this->data[i];
		}
		return s_mul;
	}
	double distant(const vector& v) const
	{
		vector c(this->n);
		
		c = *this - v;
		double dist = c.norma();
		return dist;
	}
	double norma()const
	{
		double scalar_q = scalar_mul(*this);
		return scalar_q;
	}
	void print() const {
		for (int i = 0; i < n; i++)
		{
			std::cout << this->data[i] << " ";
		}
		std::cout << std::endl;
	}
	vector operator+(const vector& v) const
	{
		if (v.n != this->n)
			throw 0;
		vector c(v.n);
		for (int i = 0; i < n; i++)
		{
			c.data[i] = (v.data[i] + this->data[i]);
		}
		return c;
	}

	vector operator*(const double& x) const
	{
		vector c(this->n);
		for (int i = 0; i < n; i++)
		{
			c.data[i] = this->data[i] * x;
		}
		return c;
	}
	vector operator/(const double& x) const
	{
		if (x == 0) throw 0;
		vector c(this->n);
		for (int i = 0; i < n; i++)
		{
			c.data[i] = this->data[i] / x;
		}
		return c;
	}
	
	vector reverse_v() const
	{
		vector c(this->n);
		for (int i = 0; i < n; i++)
		{
			c.data[i] = (-1) * this->data[i];
		}
		return c;
	}

	vector& operator=(const vector& v)
	{
		if (&v == this)
		{
			return *this;
		}
		this->n = v.n;
		delete[] data;
		data = new double[n];
		for (int i = 0; i < this->n; i++)
		{
			this->data[i] = v.data[i];
		}
		return *this;

	}
	vector& operator+=(const vector& v)
	{
		if (this->n != v.n) throw 0;
		for (int i = 0; i < this->n; i++)
		{
			this->data[i] += v.data[i];
		}
		return *this;
	}
	vector& operator-=(const vector& v)
	{
		if (this->n != v.n) throw 0;
		for (int i = 0; i < this->n; i++)
		{
			this->data[i] -= v.data[i];
		}
		return *this;
	}
	vector& operator*=(const double& x)
	{
		for (int i = 0; i < this->n; i++)
		{
			this->data[i] *= x;
		}
		return *this;
	}
	vector& operator/=(const double& x)
	{
		if (x == 0) throw "Division error (incorrect value)";

		for (int i = 0; i < this->n; i++)
		{
			this->data[i] /= x;
		}
		return *this;
	}
	~vector()
	{
		delete[] data;
	}
}; 
