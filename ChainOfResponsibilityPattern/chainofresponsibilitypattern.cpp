//
// Created by Qibin Chen on 28/05/2017.
//

#include "utility.h"
#include "methods.h"

int main()
{
	DefaultSolveHandler defaultHandler(nullptr);
	GaussJordanEliminationSolveHandler gaussHandler(&defaultHandler);
	SORSolveHandler sorHandler(&gaussHandler);
	JacobiSolveHandler jacobiHandler(&sorHandler);

	Mat A(3, 3);
	Vec b(3);
//	Input A, b

	jacobiHandler.Solve(A, b);
}