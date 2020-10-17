#include"headersls.h"
void lscmd(DIR *dp)
{
	struct dirent *var;
	while((var=readdir(dp)))
	{
		printf("%s ",var->d_name);
	}
	printf("\n");
	exit(0);
}
	
