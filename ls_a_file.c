#include"headersls.h"
void ls_a(struct filenames *fptr)
{
	while(fptr)
	{
		printf("%s\n",fptr->f_name);
		fptr=fptr->link;
	}
	printf("\n");
}
