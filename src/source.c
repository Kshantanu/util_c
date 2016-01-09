#include <stdio.h>
#include <stdlib.h>


/*
*	P XOR Q	=	(P | Q) & ~(P & Q)
*
*/
void Verify_XOR()
{
	int a = 0,b =0;
	printf("0 XOR 0: %d with Similar Tautology: %d\n",a^b,((a|b) & ~(a&b)));

	a = 0, b = 1;
	printf("0 XOR 1: %d with Similar Tautology: %d\n",a^b,((a|b) & ~(a&b)));

	a = 1, b = 0;
	printf("1 XOR 0: %d with Similar Tautology: %d\n",a^b,((a|b) & ~(a&b)));

	a = 1, b = 1;
	printf("1 XOR 1: %d with Similar Tautology: %d\n",a^b,((a|b) & ~(a&b)));

}


/*
*	Check if two numbers have opposite Signs
*	Signed bit is 1 for Negative and 0 for Positive
*	So x ^ y will be always a Negative number for 
*	x and y of different signs.
*/
int CheckSigns(int x, int y)
{
	return ((x^y) < 0);
}


/*
*	Check Set Bits: 
*	Brian Kernighan’s Algorithm:
*	Subtraction of 1 from a number toggles all the bits 
*	(from right to left) till the rightmost set bit(including
*	the righmost set bit). So if we subtract a number by 1 and
*	do bitwise & with itself (n & (n-1)), we unset the righmost
*	set bit. If we do n & (n-1) in a loop and count the no of 
*	times loop executes we get the set bit count.
*	Beauty of the this solution is number of times it loops is 
*	equal to the number of set bits in a given integer.
*/
int GetSetBitCount(int x)
{
	int retVal	=	0;

	while(x)
	{
		x &= (x-1);
		retVal++;
	}

	return retVal;
}

/*
*	Print Binary Representation
*/

void bin(int n)
{
	if(n > 0)
		bin(n/2);

	printf("%d",n%2);
}


/*
*	Swap two Numbers
*/
void SwapBitWise(int x, int y)
{
	printf("\nX: ");
	bin(x);
	printf("\nY:");
	bin(y);

	x	=	x ^ y;
	
	printf("\nX: ");
	bin(x);
	printf("\nY:");
	bin(y);	y	=	x ^ y;

	printf("\nX: ");
	bin(x);
	printf("\nY:");
	bin(y);	x	=	x ^ y;


	printf("\nX: ");
	bin(x);
	printf("\nY:");
	bin(y);
}

/*
Swap bits in a given number
Given a number x and two positions (from right side) in binary
representation of x, write a function that swaps n bits at 
given two positions and returns the result. It is also given
that the two sets of bits do not overlap.

Examples:

Let p1 and p2 be the two given positions.

Example 1
Input:
x = 47 (00101111)
p1 = 1 (Start from second bit from right side)
p2 = 5 (Start from 6th bit from right side)
n = 3 (No of bits to be swapped)
Output:
227 (11100011)
The 3 bits starting from the second bit (from right side) are 
swapped with 3 bits starting from 6th position (from right side) 


Example 2
Input:
x = 28 (11100)
p1 = 0 (Start from first bit from right side)
p2 = 3 (Start from 4th bit from right side)
n = 2 (No of bits to be swapped)
Output:
7 (00111)
The 2 bits starting from 0th postion (from right side) are
swapped with 2 bits starting from 4th position (from right side) 

Solution
We need to swap two sets of bits. XOR can be used in a similar
way as it is used to swap 2 numbers. Following is the algorithm.

1) Move all bits of first set to rightmost side
   set1 =  (x >> p1) & ((1U << n) - 1)
Here the expression (1U << n) - 1 gives a number that 
contains last n bits set and other bits as 0. We do & 
with this expression so that bits other than the last 
n bits become 0.
2) Move all bits of second set to rightmost side
   set2 =  (x >> p2) & ((1U << n) - 1)
3) XOR the two sets of bits
   xor = (set1 ^ set2) 
4) Put the xor bits back to their original positions. 
   xor = (xor << p1) | (xor << p2)
5) Finally, XOR the xor with original number so 
   that the two sets are swapped.
   result = x ^ xor

*/
void SwapBitsInPlace(int x, int p1, int p2, int n)
{
	int set1,set2, xor, result;

	printf("input is : ");
	bin(x);

	set1 = set2 = xor = result = 0;


	set1 = (x >> p1) & ((1U << n) - 1);
	set2 = (x >> p2) & ((1U << n) - 1);

	xor	=	set1 ^ set2;

	xor = (xor << p1) | (xor << p2);

	result = x ^ xor;

	printf("\nonput is : ");
	bin(result);
}

/*
*	Check EndianNess of Machine
*/
void IsLittleEndian()
{
	int i	=	1;
	char *c =	(char*)&i;

	if(*c)
		printf("Yes");
	else
		printf("No");
}

int GetBigEndianOf(int n)
{
	int b[4]	=	{0};
	int res	=	0;

	b[0]	=	(n & 0x000000ff) << 24u;
	b[1]	=	(n & 0x0000ff00) << 8u;
	b[2]	=	(n & 0x00ff0000) >> 8u;
	b[3]	=	(n & 0xff000000) >> 24u;

	res	=	b[0] | b[1] | b[2] | b[3];

	return res;
}

/*
*	Parity: If the no of set bits is even
*	then it is said as even-parity and if
*	it is odd then said as odd parity.
*/
void GetParity(int num)
{
	if(GetSetBitCount(num)%2 == 0)
		printf("Even");
	else
		printf("Odd");
}


void main1()
{

	int x = GetBigEndianOf(4);

	GetParity(4);
	x = GetBigEndianOf(x);
	printf("x : %d",x);
	IsLittleEndian();
	SwapBitsInPlace(47,1,5,3);
	
	SwapBitWise(15,8);
	bin(123134);
	printf("Bit Count in 3() is %d\n",GetSetBitCount(3));
	printf("Bit Count in 35() is %d\n",GetSetBitCount(35));
	printf("Bit Count in 30() is %d\n",GetSetBitCount(30));
	Verify_XOR();
	if(1 == CheckSigns(-1,50))
		printf("Both are of opposite signs.");
	else	
		printf("Both are of similar signs.");
}