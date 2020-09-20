# Search for roots of quadratic equation
This program is searching for roots of quadratic equation,
returns them, their number and test status.
This program has it's own unittest function.

## Functions
### IsZero
This function returns bool value.
It compares double value with null as double.
#### Examples:
1) IsZero(0.00001) returns false 
2) IsZero(0.0) returns true
### Unitest
This function runs tests for IsZero function
and Search_For_Roots function.
It prints result to the stdout.
### Test_Search_For_Roots
This function returns int value.
It runs test for Search_For_Roots function 
with some values from double *params.
#### Examples:
1) Test_Search_For_Roots(*params) returns 1 for correct test
2) Test_Search_For_Roots(*params) returns 0 for incorrect test
and prints roots and expected roots 
### Test_Is_Zero
This function runs test for IsZero function.
It prints test status.
#### Examples:
1) Test_Is_Zero(0.00001, false) prints correct test value
2) Test_Is_Zero(0.0, false) prints incorrect test value
### Search_For_Roots 
This function returns number of roots and
changes value of roots variables.
#### Examples:
1) Search_For_Roots(1,4,4,&x1,&x2)  returns 1 
2) Search_For_Roots(1,5,-6,&x1,&x2) returns 2
3) Search_For_Roots(1,1,2,&x1,&x2)  returns 0
4) Search_For_Roots(0,1,1,&x1,&x2)  returns -1
 
Released by Denis Galanin (MSU CMC groop 327 2020/2021)
