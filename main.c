#include"headersls.h"
int a_flag=0;
int l_flag=0;
int i_flag=0;
int s_flag=0;
int main(int argc,char **argv)
{
	struct filenames* fptr;
	fptr=file_name();
	if(argc==1&&!(strcmp(argv[0],"./lscmd")))
		lscmd(fptr);
	if(argc==2)
           lswith2args(fptr,argv);
}
struct filenames* file_name()
{
	DIR *dp;
	dp=opendir(".");
	struct filenames *fptr,*head=NULL,*temp=NULL;
	struct dirent *var;
	while(var=readdir(dp))
	{
	fptr=calloc(1,sizeof(struct filenames));	
	strcpy(fptr->f_name,var->d_name);
	if(fptr==NULL)
		printf("node not created\n");
        if(head==NULL)
	{
		head=fptr;
	}
	else
	{
		temp=head;
		while(temp->link)
			temp=temp->link;
		temp->link=fptr;
	}
	}
	return head;
}
