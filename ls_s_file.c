#include"headersls.h"
void ls_s(struct filenames *fptr)
{
	struct stat buf;
	while(fptr)
	{
		if(a_flag==0&&fptr->f_name[0]=='.');
		else
		{
		if(stat(fptr->f_name,&buf)==-1) perror("stat");
		printf("%lu ",buf.st_blocks/2);
		printf("%s\n",fptr->f_name);
		}
		fptr=fptr->link;
	}
}
