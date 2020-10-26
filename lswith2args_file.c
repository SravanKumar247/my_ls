#include"headersls.h"
union flags ch;
void switch_case(struct filenames* fptr);
void lswith2args(struct filenames* fptr,char **argv)
{
	int i=0;
	char arr[26]={0};
	for(i=1;argv[1][i];i++)
		arr[argv[1][i]-97]=1;
	for(i=0;i<26;i++)
	{
		if(arr[i]==1)
		{
			if(i==11)
			{
				l_flag=1;
				ch.l=1;
			}
			else if(i==0)
			{
				a_flag=1;
				ch.a=2;
			}
			else if(i==8)
			{
				i_flag=1;
				ch.i|=4;
			}
			else if(i==19)
			{
				ch.t|=8;
			}
			else if(i==18)
			{
				s_flag=1;
				ch.s|=16;
			}
		}
	}
	printf("%d\n",ch.value);
	switch_case(fptr);
}
void switch_case(struct filenames *fptr)
{
	switch(ch.value)
	{
		case LS_L:ls_l(fptr);
			  break;
		case LS_A:ls_a(fptr);
			  break;
		case LS_I:ls_i(fptr);
			  break;
		case LS_T:ls_t(fptr);
			  break;
		case LS_S:ls_s(fptr);
			  break;
		case LS_AL:ls_l(fptr);
			  break;
		case LS_AI:ls_i(fptr);
			  break;
		case LS_AT:ls_t(fptr);
			   break;
		case LS_AS:ls_s(fptr);
			  break;
		case LS_TL:fptr=ls_t(fptr);
			   ls_l(fptr);
			  break;
		case LS_TI:fptr=ls_t(fptr);
			   ls_i(fptr);
			   break;
		case LS_TS:fptr=ls_t(fptr);
			   ls_s(fptr);
			  break;
		case LS_LI:ls_l(fptr);
			   break;
		case LS_LS:ls_l(fptr);
			  break;
		case LS_IS:ls_l(fptr);
			  break;
	}
}
