#include <iostream>
#include "matrix.h"

int main()
{
	//конструктор через инициализацию массивом векторов
	double arr1[] = { 1,2,3,4 };
	vector a1(arr1, 4);
	vector* arr3 = new vector[4];
	for (int i = 0; i < 4; i++)
	{
		arr3[i] = a1;
	}
	matrix a(arr3, 4, 4);
	a.print();

	//транспонирование матрицы
	matrix b;
	b = a.transp();
	b.print();

	double arr2[] = { 3,5,7,9 };
	vector a2(arr2, 4);
	vector* arr_v = new vector[4];
	for (int i = 0; i < 4; i++)
	{
		arr_v[i] = a2;
	}
	matrix d(arr_v, 4, 4);
	
	//сложение матриц
	matrix c;
	c = a + d;
	c.print();

	//умножение матрицы на число
	c = a * 5;
	c.print();

	//mult of mat
	double arr1_m[] = { 1,2,3 };
	vector arr1_m_v(arr1_m, 3);
	vector* arr1_mat = new vector[2];
	for (int i = 0; i < 2; i++)
	{
		arr1_mat[i] = arr1_m_v;
	}
	matrix A(arr1_mat, 3, 2);
	A.print();

	double arr2_m[] = { 1,2 };
	vector arr2_m_v(arr2_m, 2);
	vector* arr2_mat = new vector[3];
	for (int i = 0; i < 3; i++)
	{
		arr2_mat[i] = arr2_m_v;
	}
	matrix B(arr2_mat, 2, 3);
	B.print();

	matrix C = A * B;
	C.print();

	C = B * A;
	C.print();

	double det = a.det();//нулевой с одинаковыми векторами
	std::cout << det << std::endl;

	
	double** arr_p = new double* [4];
	for (int i = 0; i < 4; i++)
	{
		arr_p[i] = new double[4];
	}
	for (int i = 0; i < 4; i++) {

		for (int j = 0; j < 4; j++) {
			std::cin >> arr_p[i][j];
		}
	}
	matrix H(arr_p, 4, 4);//конструктор через инициализацию двумерным дин.массивом
	H.print();
	double det_h = H.det();
	std::cout << det_h << std::endl;

	for (int i = 0; i < 4; i++)
	{
		delete[] arr_p[i];
	}
	delete[] arr_p;
	
}