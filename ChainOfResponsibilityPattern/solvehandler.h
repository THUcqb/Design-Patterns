//
// Created by Qibin Chen on 28/05/2017.
//

#ifndef DESIGN_PATTERNS_HANDLER_H
#define DESIGN_PATTERNS_HANDLER_H

#include "utility.h"

class SolveHandler
{
	SolveHandler *successor;

	virtual bool DoSolve(Mat A, Vec b) = 0;

public:
	SolveHandler(SolveHandler *successor) : successor(successor)
	{}

	void Solve(Mat A, Vec b);

};


#endif //DESIGN_PATTERNS_HANDLER_H
