#include "salto.h"

char BNE(char *p)
{
	if(p[1]==1)
		return 1;
	else
		return 0;
}

char BCC(char *p)
{
	if(p[2]==0)
		return 1;
	else
		return 0;
}