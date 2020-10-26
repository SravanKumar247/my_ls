#include"headersls.h"
void lscmd(struct filenames *fptr)
{
	while(fptr)
	{
		printf("%s ",fptr->f_name);
		fptr=fptr->link;
	}
	printf("\n");
	exit(0);
}
	
