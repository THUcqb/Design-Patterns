//
// Created by Qibin Chen on 28/05/2017.
//

#include "methods.h"
#include <iostream>

bool JacobiSolveHandler::DoSolve(Mat A, Vec b)
{
	std::cout << "Jacobi Method: Solving" << std::endl;
//	Solving
//	if (JacobiSolved)
//	{
//		std::cout << "Jacobi Method: Solved" << std::endl;
//		return true;
//	}
//	else
	{
		std::cout << "Jacobi Method: Failed" << std::endl;
		return false;
	}
}

bool SORSolveHandler::DoSolve(Mat A, Vec b)
{
	std::cout << "SOR Method: Solving" << std::endl;
//	Solving
//	if (SORSolved)
//	{
//		std::cout << "SOR Method: Solved" << std::endl;
//		return true;
//	}
//	else
	{
		std::cout << "SOR Method: Failed" << std::endl;
		return false;
	}
}

bool GaussJordanEliminationSolveHandler::DoSolve(Mat A, Vec b)
{
	std::cout << "Gauss-Jordan Elimination Method: Solving" << std::endl;
//	Solving
//	if (GaussJordanEliminationSolved)
	{
		std::cout << "Gauss-Jordan Elimination Method: Solved" << std::endl;
		return true;
	}
//	else
//	{
//		std::cout << "Gauss-Jordan Elimination Method: Failed" << std::endl;
//		return false;
//	}
}

bool DefaultSolveHandler::DoSolve(Mat A, Vec b)
{
	std::cout << "Error: ALL Methods Failed" << std::endl;
	return true;
}
