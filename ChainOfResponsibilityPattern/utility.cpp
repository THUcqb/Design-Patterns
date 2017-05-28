//
// Created by Qibin Chen on 28/05/2017.
//

#include "utility.h"

#include <cstring>

Mat::Mat(int row, int column) : row(row), column(column)
{
	_data = new double*[row];
	for (int i = 0; i < row; ++i)
	{
		_data[i] = new double[column];
		memset(_data[i], 0, column * sizeof(double));
	}
}

void Mat::SetValue(int row, int column, double value)
{
	_data[row][column] = value;
}

double Mat::GetValue(int row, int column)
{
	return _data[row][column];
}

Vec::Vec(int row) : row(row)
{
	_data = new double[row];
	memset(_data, 0, row * sizeof(double));
}

void Vec::SetValue(int row, double value)
{
	_data[row] = value;
}

double Vec::GetValue(int row)
{
	return _data[row];
}
