#include"headersls.h"
void lscmd(struct filenames *fptr)
{
	while(fptr)
	{
	  if(a_flag==0&&fptr->f_name[0]=='.');
	  else
              printf("%s\n",fptr->f_name);
		fptr=fptr->link;
	}
	exit(0);
}
	
