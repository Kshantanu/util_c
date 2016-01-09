#include <stdio.h>
#include <stdlib.h>


/*
*	Copy String of length len.	
*/
void STRNCPY(char* dest, const char* src, int len)
{
	while(len-- > 0)
	{
		*dest++ = *src++;
	}
}

/*
*	Get the String length of a pattern
*	Without the Null Character in count
*/
int STRLEN(const char* pattern)
{
	int iCount	=	0;

	while(*pattern++ != '\0')
		iCount++;

	return iCount;
}
/*
*	Pattern Search (KMP) O(n) Runnning Time
*/
int NaivePatternSearch(const char* buffer, const char* pattern,int* pos)
{
	char* text;
	char* pat;

	int iLenBuffer,ibuf	;
	int iLenPattern,ipat	;
	int i	=	0, j	=	0;
	int hit	=	0;

	if(buffer == NULL || pattern == NULL)
		return 0;

	text	=	buffer;
	pat		=	pattern;

	iLenBuffer	=	STRLEN(text);
	iLenPattern	=	STRLEN(pattern);
	ibuf		=	iLenBuffer;
	ipat		=	iLenPattern;


	while(iLenBuffer)
	{
		if(*text == *pat)
		{
			ipat--;
			if(ipat	==	0)
			{
				hit	=	1;
				*pos	=	ibuf - iLenPattern - iLenBuffer +2;
				break;
			}
			else
			{
				text++;
				pat++;
				iLenBuffer--;
				continue;
			}
		}
		else
		{
			*text++;
			ipat	=	iLenPattern;
			pat		=	pattern;
		}
		iLenBuffer--;
	}
	
	return hit;
}

/*
*	Pattern Search: Search all possible postions where
*	pattern is located.
*/
void SearchAllOccurence(const char* text, const char* pattern)
{
	char* input	=	text;
	char* patrn	=	pattern;
	char* pcText	=	NULL;
	int pos	=	0;
	int shifter =	0;
	int iLenPattern = STRLEN(pattern);

	printf("Text is :[%s] with Pattern is: [%s]",text,pattern);
	pcText	=	input;
	do
	{
		pos	=	0;
		input	=	pcText;
		if(1 == NaivePatternSearch(pcText,patrn,&pos))
			printf("Found at pos %d\n",pos + shifter);
		else
			printf("Flop");
		if(pos > 0)
		{
			shifter	=	pos + iLenPattern - 1;
			pcText	=	input;
			pcText	=	pcText + shifter;
		}

	}while(pos > 0);
}
#if 0
void main()
{
	char buf[100]	=	{0};
	int pos = 0;
	SearchAllOccurence("forallistheallaaqettjhfralkall","all");
	if(1 == NaivePatternSearch("foralkwhoallissendwithwrath","all",&pos))
		printf("Bingo at pos %d",pos);
	else
		printf("Flop");
	STRNCPY(buf,"DevilDens",9);
	printf("hello : %s",buf);
}
#endif