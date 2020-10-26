#include"headersls.h"
void ls_i(struct filenames *fptr)
{
	struct stat buf;
	while(fptr)
	{
			stat(fptr->f_name,&buf);
		if(a_flag==0&&fptr->f_name[0]=='.');
		else{
		printf("%lu ",buf.st_ino);
		printf("%s\n",fptr->f_name);
		}
		fptr=fptr->link;
	}
	printf("\n");
}
