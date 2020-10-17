#include"headersls.h"
int main(int argc,char **argv)
{
	DIR *dp;
	struct dirent var;
	dp=opendir(".");
	if(argc==1&&!(strcmp(argv[0],"./a.out")))
		lscmd(dp);
	if(argc==2)
           lswith2args(dp,argv);
}
