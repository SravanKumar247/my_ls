lscmd:main.o lscmd_file.o ls_l_file.o lswith2args_file.o ls_a_file.o ls_i_file.o ls_s_file.o  ls_t_file1.o
	cc -o lscmd main.o lscmd_file.o ls_l_file.o lswith2args_file.o ls_a_file.o ls_i_file.o ls_s_file.o  ls_t_file1.o
main.o:main.c
	cc -c main.c
lscmd_file.o:lscmd_file.c
	cc -c lscmd_file.c	
lswith2args_file.o:lswith2args_file.c
	cc -c lswith2args_file.c	
ls_l_file.o:ls_l_file.c
	cc -c ls_l_file.c
ls_a_file.o:ls_a_file.c
	cc -c ls_a_file.c
ls_i_file.o:ls_i_file.c
	cc -c ls_i_file.c
ls_s_file.o:ls_s_file.c
	cc -c ls_s_file.c
ls_t1_file1.o:ls_t_file1.c
	cc -c ls_t1.file.c

