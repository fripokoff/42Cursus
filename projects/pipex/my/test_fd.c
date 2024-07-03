#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>


# ifndef CHILD_EXIT_CODE
# define CHILD_EXIT_CODE 42
#endif

#define EXPECTED_CODE 42

void	routine_fils(pid_t pid)
{
	printf("Fils : je suis le fils pid de fork : %d\n", pid);
	printf("Fils : je sors avec le statut de fin : %d\n", CHILD_EXIT_CODE);
	exit (CHILD_EXIT_CODE);
}

void	routine_pere(pid_t pid)
{
	int status;
	printf("Je suis le pere pid recu de fork = %d\n",pid);
	printf("Pere : jattends mon fils qui a le pid %d \n", pid);
	waitpid(pid, &status, 0);
	printf("Pere :Mon fils est sortis avec le status %d \n", status);
	if (WIFEXITED(status))
	{
		printf("Pere :Le status de fin de mon fils est %d \n", WEXITSTATUS(status));
		if (WEXITSTATUS(status) == EXPECTED_CODE)
			printf("Pere :Cest le status que jattendais %d \n", WEXITSTATUS(status));
		else
			printf("Pere :Je ne mattendais pas a cela %d \n", WEXITSTATUS(status));
	}
}

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		routine_fils(pid);
	}
	else if (pid > 0)
		routine_pere(pid);
	return (EXIT_SUCCESS);
}