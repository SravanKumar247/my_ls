#include"headersls.h"
void lswith2args(DIR *dp,char **argv)
{
     if(strcmp(argv[1],"-l")==0)
	     ls_l(dp);
}
