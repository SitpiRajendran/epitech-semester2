/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my main minishell2
*/

#include "my.h"

int main(int ac, char **av, char **env)
{
    mini_t mini_s;

    (void) av;
    if (ac > 1) {
        my_putstr("Too much arguments\n", 2);
        return (84);
    }
    if (initialise_my_struct(&mini_s, env) == 84)
        return (84);
    return (0);
}

int initialise_my_struct(mini_t *mini_s, char **env)
{
    mini_s->command = NULL;
    mini_s->home_path = NULL;
    mini_s->path = NULL;
    mini_s->arg = NULL;
    mini_s->env = NULL;
    mini_s->history = NULL;
    mini_s->v_return = 0;
    mini_s->exit_status = 0;
    mini_s->exit_value = 0;
    mini_s->fork_val = 0;
    mini_s->arg_nbr = 0;
    mini_s->error = 0;
    mini_s->set_error = 0;
    mini_s->compt = 0;
    if (create_my_terminal(mini_s, env) == 84)
        return (84);
    free_structure(mini_s);
    if (mini_s->exit_status == 1)
        exit(mini_s->exit_value);
    return (0);
}

void free_structure(mini_t *mini_s)
{
    free_buffer(mini_s->command);
    free_buffer(mini_s->home_path);
    free_buffer(mini_s->path);
    free_tab_buffer(mini_s->arg);
    free_tab_buffer(mini_s->env);
    free_history(mini_s);
}

void free_buffer(char *buffer)
{
    if (buffer != NULL)
        free(buffer);
}

void free_tab_buffer(char **tab)
{
    if (tab != NULL) {
        for (int i = 0; tab[i] != NULL; i++)
            free(tab[i]);
        free(tab);
    }
}