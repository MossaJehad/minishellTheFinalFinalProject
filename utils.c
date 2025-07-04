#include "minishell.h"
#include <string.h> // Ensure ft_strcmp is defined or replace with strcmp if appropriate

int	is_shell_builtin(const char *cmd)
{
	if (ft_strcmp(cmd, "type") == 0 || ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "exit") == 0 || ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "unset") == 0)
	{
		printf("%s is a shell builtin\n", cmd);
		return (1);
	}
	return (0);
}

int	should_run_in_parent(const char *cmd)
{
    return (!ft_strcmp(cmd, "cd")
         || !ft_strcmp(cmd, "export")
         || !ft_strcmp(cmd, "unset")
         || !ft_strcmp(cmd, "exit"));
}

void	print_welcome_banner(void)
{
	printf("┏┓┳┏┓┳┳┓┏┓\n");
	printf("┗┓┃┃┓┃┃┃┣┫\n");
	printf("┗┛┻┗┛┛ ┗┛┗ .\n");
	printf("			\n");
}

void	init_shell(char **envp)
{
	(void)envp;
	print_welcome_banner();
}

void    free_env(char **envp)
{
    int i = 0;
    if (!envp)
        return;
    while (envp[i])
        free(envp[i++]);
    free(envp);
}
