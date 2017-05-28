//
// Created by Qibin Chen on 28/05/2017.
//

#include "solvehandler.h"
#include <iostream>

void SolveHandler::Solve(Mat A, Vec b)
{
	if (!DoSolve(A, b) && successor != nullptr)
	{
		std::cout << "Pass On" << std::endl;
		successor->Solve(A, b);
	}
}

