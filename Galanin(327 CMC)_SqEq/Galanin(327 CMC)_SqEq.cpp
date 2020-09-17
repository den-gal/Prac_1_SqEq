//Galanin Denis (327 CMC) 
//	Task:		Searching for roots of quadratic equation 
//General form: a*X^2 + b*X + c = 0 
//	Result:		Number of roots, root1 and root2(if they exist) 

#include <stdio.h> 
#include <math.h>
bool IsZero(double a);
void Unitest();
int Test_Search_For_Roots(double* params);
void Test_Is_Zero(double value, bool test_result);
int Search_For_Roots(double a, double b, double c, double* x1, double* x2);


/// 
//! Compare double type variable with 0
//!
//! @param [in]	a - comparison variable
//! 
//! @note In case of None it prints warning to output 
/// 
bool IsZero(double a)
{
	double eps = 1e-10;
	if (fabs(a) < eps)
		return true;
	else
		return false;
}

/// 
//! Lounch tests for the function Search_For_Roots(...)
//!
//! @note This function prints masseges about correct or incorrect\n 
//!		  result of execution Search_For_Roots(...) 
/// 
void Unitest()
{
	double params[6][6] = { 1,2,1,1,-1,0,
							2,8,8,1,-2,0,
							1,-7,12,2,3,4,
							1,5,6,2,-3,-2,
							0,1,1,-1,0,0,
							1,0,1,0,0,0,
	};
	struct izparams
	{
		double value[3];
		bool result[3];
	};
	int tst = 0, i = 0; 
	struct izparams val = {0, -20, 20, true, false, false};
	printf("Start the Unitest programm\n\n");
	for (i = 0; i < 6; i++)
	{
		tst = Test_Search_For_Roots(params[i]);
		if (tst == 1)
			printf("[Passed] Your funtion returns correct number of roots and correct roots\n");
		else if (tst == 0)
			printf("[Not Passed] Your funtion returns correct number of roots and incorrect roots\n");
		else
			printf("[Not Passed] Your funtion returns incorrect number of roots\n");
	}
	for (i = 0; i < 3; i++)
		Test_Is_Zero(val.value[i], val.result);

}

/// 
//! Check roots and thier number with correct answer in params[...] 
//!
//! @param [out] params Pointer to the array with\n correct answers and parametrs
//! @return Int status of execution
//! @note 1  - Correct execution\n 
//!       0  - incorrect roots, but correct number of roots\n
//!       -1 - incorrect number of roots\n
/// 
int Test_Search_For_Roots(double* params)
{
	double numb = 0, x1 = 0, x2 = 0;
	numb = Search_For_Roots(params[0], params[1], params[2], &x1, &x2);
	if (numb == params[3])
	{
		if ((x1 == params[4]) && (x2 == params[5]))
			return 1;
		else
		{
			printf("Function Roots: x1 = %lf; x2 = %lf\n Test Roots x1 = %lf; x2 = %lf\n", x1, x2, params[4], params[5]);
			return 0;
		}
	}
	else
	{
		printf("Function Number: numb = %lf;\n Test Number: numb = %lf;\n", numb, params[3]);
		return -1;
	}
}

/// 
//! Check correct output for IsZero function 
//!
//! @param [in] value - test value
//! @param [in] test_result - correct output
//! @return Int status of execution
//! @note true  - Correct execution\n 
//!       false - incorrect number of roots\n
/// 
void Test_Is_Zero(double value, bool test_result)
{
	bool result = false;
	result= IsZero(value);
	if (result = test_result)
		printf("[Passed] Your IsZero test has correct otput\n");
	else
		printf("[Not Passed] Your IsZero test has incorrect otput\n");
}

/// 
//! Searching for roots of square equation
//!
//! @param [in] a X^2 coefficient
//! @param [in] b X coefficicent
//! @param [in] c X^0 coefficient
//! @param [out] x1 Pointer to the first root
//! @param [out] x2 Pointer to the second root
//!
//! @return Number of roots
//! @note 2  - Two different roots\n
//!		  1  - One common root\n
//!		  0  - No roots\n
//!		  -1 - Isn't square equation
/// 
int Search_For_Roots(double a, double b, double c, double* x1, double* x2)
{
	int numb = 0;
	double disc = 0;
	if (IsZero(a))
		return -1;
	else
		disc = b * b - 4 * a * c;
	if (isnan(b) || isnan(c))
		return -2;
	if (disc > 0)
	{
		numb = 2;
		*x1 = (-b - sqrt(disc)) / 2 / a;
		*x2 = (-b + sqrt(disc)) / 2 / a;
	}
	else if (IsZero(disc))
	{
		numb = 1;
		*x1 = -b / 2 / a;
	}
	else
		numb = 0;
	return numb;
}

int main()
{
	double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
	int numb = 0;
	printf("Enter parametrs for your quadratic equation \nGeneral form:	a*X^2 + b*X + c = 0\n");
	scanf_s("%lf%lf%lf", &a, &b, &c);
	printf("\nYour equation: %lf*X^2 + %lf*X + %lf = 0\n", a, b, c);
	numb = Search_For_Roots(a, b, c, &x1, &x2);
	if (numb == -1)
		printf("\nThis isn't quadratic equation\n\n");
	else if (numb == 0)
		printf("\nThis quadratic equation hasn't any roots\n\n");
	else if (numb == 1)
		printf("\nThis quadratic equation has one root: \nx1 = %lf\n\n", x1);
	else
		printf("\nThis quadratic equation has two roots: \nx1 = %lf\nx2=%lf\n\n", x1, x2);
	Unitest();
	return 0;
}