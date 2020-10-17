#include"headersls.h"
struct passwd *usrname;
struct group *grpname;
void ls_l(DIR *dp)
{
      struct ls_l *ptr=NULL,*head=NULL,*prev=NULL,*cur=NULL;	
      struct dirent *var;
      struct stat buf;
      while(var=readdir(dp))
      { 
	  if(!strcmp(var->d_name,".")||!strcmp(var->d_name,".."))
	      continue;	  
          ptr=(struct ls_l *)calloc(1,sizeof(struct ls_l));
	  if(ptr==NULL)
	  {
		  printf("node not created\n");
		  exit(EXIT_FAILURE);
	  }
	  assign_values(ptr,var);
	  if(head==NULL||strcmp(head->file_name,ptr->file_name)>0)
	  {
		  ptr->link=head;
		  head=ptr;

	  }
	  else
	  {
		  prev=head;
		  cur=head->link;
		  while(cur&&strcmp(cur->file_name,ptr->file_name)<=0)
		  {
			  prev=cur;
			  cur=cur->link;
		  }
		  ptr->link=prev->link;
		  prev->link=ptr;
	  }
      }
      while(head!=NULL)
      {
	      print(head);
	      head=head->link;
      }
}
void print(struct ls_l *ptr)
{
	printf("%-11s",ptr->modes);
	printf(" %-3lu",ptr->nlinks);
	printf("%-10s",ptr->grp_name);
	printf("%-10s",ptr->usr_name);
	printf(" %-7ld",ptr->size_bytes);
	printf(" %-15s",ptr->time_zone);
	printf(" %-20s\n",ptr->file_name);
}
void assign_values(struct ls_l *ptr,struct dirent *var)
{
	struct stat buf;
      if(stat(var->d_name,&buf)==-1) perror("stat");
      user_understandable_modes(buf.st_mode,ptr->modes);
      ptr->nlinks=buf.st_nlink;
      ptr->size_bytes=buf.st_size;
      strcpy(ptr->file_name,var->d_name);
      calender(ptr->time_zone,buf.st_mtime);
      usrname=getpwuid(buf.st_uid);
      strcpy(ptr->usr_name,usrname->pw_name);
      grpname=getgrgid(buf.st_gid);
      strcpy(ptr->grp_name,grpname->gr_name);

}
void calender(char *arr,time_t t)
{
	struct tm *temp;
        temp=localtime(&t);
	if(temp==NULL)
	{
		perror("localtime");
		exit(EXIT_FAILURE);
	}
	if(strftime(arr,50,"%b %_d %R",temp)==0)
	{
		fprintf(stderr,"strftime returned 0");
		exit(EXIT_FAILURE);
	}
}
void user_understandable_modes(mode_t mode,char *arr)
{
	int i=0;
	switch(mode&S_IFMT)
	{
          case S_IFREG:arr[i++]='-'; break;
          case S_IFBLK:arr[i++]='b'; break;
          case S_IFCHR:arr[i++]='c'; break;
          case S_IFDIR:arr[i++]='d'; break;
          case S_IFIFO:arr[i++]='p'; break;
          case S_IFLNK:arr[i++]='l'; break;
          case S_IFSOCK:arr[i++]='s'; break;
	}
	if((mode>>8&1))
		arr[i++]='r';
	else
		arr[i++]='-';
	if((mode>>7&1))
		arr[i++]='w';
	else
		arr[i++]='-';
	if((mode>>6&1))
		arr[i++]='x';
	else
		arr[i++]='-';
	if((mode>>5&1))
		arr[i++]='r';
	else
		arr[i++]='-';
	if((mode>>4&1))
		arr[i++]='w';
	else
		arr[i++]='-';
	if((mode>>3&1))
		arr[i++]='x';
	else
		arr[i++]='-';
	if((mode>>2&1))
		arr[i++]='r';
	else
		arr[i++]='-';
	if((mode>>1&1))
		arr[i++]='w';
	else
		arr[i++]='-';
	if((mode>>0&1))
		arr[i++]='x';
	else
		arr[i++]='-';
	arr[i]=0;
}
    

