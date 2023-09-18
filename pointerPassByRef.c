//DATE: 2023.09.18
//PURPOSE: Passing data to functions using pointers, pass by reference

#include <stdio.h>

//function prototype declarations


void square(int *pNumber);
void swapNoPointerUsingLocalVar(int LocX, int LocY);
void swapNoPointerUsingGlobalVar(int GlobY, int GlobX);
void swapPointerUsed(int *pNum1, int *pNum2);

//global variables

int globNum1 = 8;
int globNum2 = 9;

int main(){

	//invoking the square function
	int numSquare = 5;
	printf("***************************\n");
	printf("PASS BY REFERENCE SQUARE\n");
	printf("The number to be squared:%d\n", numSquare);
	square(&numSquare); //function parameter takes a pointer, so we have to give the address as argument
	printf("After invoking square func.:%d\n", numSquare);
	printf("***************************\n");

	//invoking the not working swap value function
	int localNum1 = 4;
	int localNum2 = 5;
	printf("SWAP USING LOCAL VARIABLES (NOT WORKING)\n");
	printf("The numbers to be swapped:%d | %d\n", localNum1, localNum2);
	swapNoPointerUsingLocalVar(localNum1, localNum2); // won't change the numbers cause they are passed by value, local variables
	printf("The numbers after swapping:%d | %d\n", localNum1, localNum2);
	printf("***************************\n");

	//invoking the global variable swap function
	printf("SWAP USING GLOBAL VARIABLES\n");
	printf("The numbers to be swapped:%d | %d\n", globNum1, globNum2);
	swapNoPointerUsingGlobalVar(globNum1, globNum2);
	printf("The numbers after swapping:%d | %d\n", globNum1, globNum2);
	printf("***************************\n");

	//invoking the pointer swap function
	int anyNum1 = 30;
	int anyNum2 = 40;
	printf("SWAP USING POINTERS (RECOMMENDED)\n");
	printf("The numbers to be swapped:%d | %d\n", anyNum1, anyNum2);
	printf("The to be swapped number's addresses: %#x | %#x \n", &anyNum1, &anyNum2);
	swapPointerUsed(&anyNum1, &anyNum2); //pointers , addresses passed
	printf("The numbers after swapping:%d | %d\n", anyNum1, anyNum2);
	printf("Swapped number's addresses: %#x | %#x \n", &anyNum1, &anyNum2);
	printf("***************************\n");
	return 0;
}

//****FUNCTION DEFINITIONS****

//function for squaring a number using pass by reference with a pointer
void square(int *pNumber) {
	*pNumber = (*pNumber) * (*pNumber); //pNumber's dereffed value multiplied with pNumbers dereffed value
	return;	
}

//functions for swapping two ints with void return
//this does not do the job because of no pointers used, only local variables
void swapNoPointerUsingLocalVar(int LocX, int LocY) {
	int temp;
	temp = LocX;
	LocX = LocY;
	LocY = temp;
	return;
} 

//function for swapping two ints using global variables
//makes not sense, not using the arguments, because they are created locally, passed by reference, modifying the global vars.
//Not Recommended, not useful...
void swapNoPointerUsingGlobalVar(int GlobY, int GlobX){
	int temp;
	temp = globNum1;
	globNum1 = globNum2;
	globNum2 = temp;
	return;
}


//function for swapping to ints using pointers


void swapPointerUsed(int *pNum1, int *pNum2){
	int temp;
	temp = *pNum1; //temp will store pNum1-s value, dereffed
	*pNum1 = *pNum2;
	*pNum2 = temp;
	return;
}