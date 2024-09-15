#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void print_child_parent(int fork_num, int ret)
{
	printf("fork_%d: %*c\b%s\n", fork_num, fork_num * 4, ' ', (ret) ? "Parent" : "Child");
}

int main() 
{ 
	int f0_ret = fork();
	print_child_parent(0, f0_ret);

	int f1_ret = fork();
	print_child_parent(1, f1_ret);
 
	int f2_ret = fork();
	print_child_parent(2, f2_ret);
       
	return 0; 
}
