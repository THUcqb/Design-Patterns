# Introduction

-   需求：对于一个（实际应用中应是一类）线性方程组，找到其最适合的求解算法。
-   思路：可使用责任链模式
    -   先使用 Jacobi 迭代法（假定进行了稀疏矩阵优化并可使用并行计算，认为速度最快）；
    -   若 Jacobi 迭代法不收敛，则传递给 SOR 迭代法（逐次超松弛迭代法）；
    -   以此类推，若不行再传递给 Gauss-Jordan 主元消去法；
    -   若还是失败，则说明求解矩阵有问题，传递给 DefaultHandler，提示错误信息。
    -   可以很灵活的加入新的算法、并且调整使用顺序。

---

# Class

## Mat, Vec

*   utility.h, utility.cpp

#### Abstract

*   为系数矩阵、向量而写，不赘述。

## SolveHandler

*   solvehandler.h, solvehandler.cpp

#### Abstract

-   责任链的基本单元：处理者。

#### private

*   DoSolve

    -   ```c++
        virtual bool DoSolve(Mat A, Vec b) = 0;
        ```

    - 派生类需实现的解方程方法。

## Interface

-   Constructor

    *   ```c++
        SolveHandler(SolveHandler *successor) : successor(successor)
        {}
        ```

- Solve

    -   ```c++
        void SolveHandler::Solve(Mat A, Vec b)
        {
        	if (!DoSolve(A, b) && successor != nullptr)
        	{
        		std::cout << "Pass On" << std::endl;
        		successor->Solve(A, b);
        	}
        }
        ```

    - 责任链传递机制，注意这是 Non-virtual 的。

## JacobiSolveHander

*   methods.h, methods.cpp

#### Abstract

-   Jacobi 迭代法解方程组。

#### private

*   DoSolve

    *   ```c++
        bool JacobiSolveHandler::DoSolve(Mat A, Vec b)
        {
        	std::cout << "Jacobi Method: Solving" << std::endl;
        //	Solving
        	if (JacobiSolved)
        	{
        		std::cout << "Jacobi Method: Solved" << std::endl;
        		return true;
        	}
        	else
        	{
        		std::cout << "Jacobi Method: Failed" << std::endl;
        		return false;
        	}
        }
        ```

    * 在此实现 Jacobi 迭代法，并返回是否成功。

#### Interface

-   Constructor

    -   ```c++
        JacobiSolveHandler(SolveHandler *successor) : SolveHandler(successor)
        {}
        ```



-   Solve

    -   ```c++
        void SolveHandler::Solve();
        ```



## SORSolveHandler, DefaultSolveHandler, GaussJordanEliminationSolveHandler

*   实现类似，不再赘述。

---

# Example

#### Test

```c++
DefaultSolveHandler defaultHandler(nullptr);
GaussJordanEliminationSolveHandler gaussHandler(&defaultHandler);
SORSolveHandler sorHandler(&gaussHandler);
JacobiSolveHandler jacobiHandler(&sorHandler);

Mat A(3, 3);
Vec b(3);
//	Input A, b

jacobiHandler.Solve(A, b);
```
#### Output

>   Jacobi Method: Solving
>   Jacobi Method: Failed
>   Pass On
>   SOR Method: Solving
>   SOR Method: Failed
>   Pass On
>   Gauss-Jordan Elimination Method: Solving
>   Gauss-Jordan Elimination Method: Solved

---

