//
// Created by Qibin Chen on 28/05/2017.
//

#ifndef DESIGN_PATTERNS_JACOBISOLVEHANDLER_H
#define DESIGN_PATTERNS_JACOBISOLVEHANDLER_H

#include "solvehandler.h"

class JacobiSolveHandler : public SolveHandler
{
	bool DoSolve(Mat A, Vec b) override;

public:
	JacobiSolveHandler(SolveHandler *successor) : SolveHandler(successor)
	{}

};

class SORSolveHandler : public SolveHandler
{
	double omega;
	bool DoSolve(Mat A, Vec b) override;

public:
	SORSolveHandler(SolveHandler *successor, double omega = 1) : SolveHandler(successor), omega(omega)
	{}

};

class GaussJordanEliminationSolveHandler : public SolveHandler
{
	bool DoSolve(Mat A, Vec b) override;

public:
	GaussJordanEliminationSolveHandler(SolveHandler *successor) : SolveHandler(successor)
	{}

};

class DefaultSolveHandler : public SolveHandler
{
	bool DoSolve(Mat A, Vec b) override;

public:
	DefaultSolveHandler(SolveHandler *successor) : SolveHandler(successor)
	{}

};
#endif //DESIGN_PATTERNS_JACOBISOLVEHANDLER_H
