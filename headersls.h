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
#define LS_L  1
#define LS_A  2
#define LS_I  4
#define LS_T  8
#define LS_S  16
#define LS_AL 3
#define LS_AI 6
#define LS_AT 10
#define LS_AS 18
#define LS_TI 12
#define LS_TL 9
#define LS_TS 24
#define LS_LI 5
#define LS_LS 17
#define LS_IS 20
extern int a_flag;
extern int l_flag;
extern int t_flag;
extern int s_flag;
extern int i_flag;
union flags
{
	char value;
	char l:1;
	char a:2;
	char i:3;
	char t:4;
	char s:5;
};
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
	ino_t ino_nbr;
	unsigned int size_in_k;
};
struct filenames
{
	char f_name[256];
	struct filenames *link;
};
struct t
{
	char name[256];
	time_t  time;
	struct t *link;
};
void lscmd(struct filenames*);
void lswith2args(struct filenames *fptr,char **);
void ls_l(struct filenames *);
void calender(char *,time_t);
void print_t(struct t *);
void assign_values_t(struct t *,struct dirent *);
void user_understandable_modes(mode_t,char *);
void ls_a(struct filenames *);
void ls_i(struct filenames *);
void ls_s(struct filenames *);
struct filenames* ls_t(struct filenames *);
void print_l(struct ls_l*);
void assign_values_l(struct ls_l *,struct filenames *);
struct filenames* file_name();
