#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>
#include<unistd.h>
#include<time.h>
#include<dirent.h>
#include<fcntl.h>
#include<error.h>
#include<sys/stat.h>
#include<wait.h>
#include<string.h>
#include<pwd.h>
#include<grp.h>
#pragma pack(1)
struct ls_l
{
	char modes[11];
	nlink_t nlinks;
	char grp_name[20];
	char usr_name[20];
	off_t size_bytes;
	char time_zone[50];
	char file_name[20];
	struct ls_l *link;
};
void lscmd(DIR *);
void lswith2args(DIR *,char **);
void ls_l(DIR *);
void print(struct ls_l *);
void assign_values(struct ls_l *,struct dirent *);
void calender(char *,time_t);
void user_understandable_modes(mode_t,char *);
