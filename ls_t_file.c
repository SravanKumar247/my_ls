#include"headersls.h"
struct filenames* ls_t(struct filenames *fptr)
{
	struct filenames *head=fptr,*cur=NULL,*prev=NULL;
	struct stat buf1,buf2;
	char temp[256];
	int cnt=0;
	while(fptr)
	{
		prev=fptr;
		cur=fptr->link;
		while(cur!=NULL)
		{
		if(stat(prev->f_name,&buf1)) perror("stat1");
		   if(stat(cur->f_name,&buf2)) perror("stat2");
		while(cur&&buf1.st_mtime>=buf2.st_mtime)
		{
			cur=cur->link;
			stat(cur->f_name,&buf2);
		}
		if(cur!=NULL)
		{
			strcpy(temp,cur->f_name);
			strcpy(cur->f_name,prev->f_name);
			strcpy(prev->f_name,temp);
		}
		}
		
		fptr=fptr->link;
	}
	if(i_flag==1||l_flag==1||s_flag==1)
		return head;
	else
	{
		while(head)
		{
		     if(a_flag==0&&head->f_name[0]=='.');
		     else
			printf("%s\n",head->f_name);
			head=head->link;
		}
		return NULL;
	}

}
	

