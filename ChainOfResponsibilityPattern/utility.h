//
// Created by Qibin Chen on 28/05/2017.
//

#ifndef DESIGN_PATTERNS_UTILITY_H
#define DESIGN_PATTERNS_UTILITY_H

class Mat
{
	int row, column;
	double **_data;

public:
	Mat(int row, int column);

	void SetValue(int row, int column, double value);

	double GetValue(int row, int column);

};

class Vec
{
	int row;
	double *_data;

public:
	Vec(int row);

	void SetValue(int row, double value);

	double GetValue(int row);
};


#endif //DESIGN_PATTERNS_UTILITY_H
