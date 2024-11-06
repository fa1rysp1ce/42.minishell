#include "minishell.h"

void	*add_node(t_token **node)
{
	t_token	*new_node;
	t_token *curr;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		//exit handle
	new_node->next = NULL;
	new_node->args = NULL;
	new_node->input = NULL;
	new_node->is_append = 0;
	new_node->output = NULL;
	new_node->heredoc = 0;
	if (*node == NULL)
	{
	//	new_node->prev = NULL;
		*node = new_node;
		return (0);
	}
	curr = *node;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	//new_node->prev = curr;
	curr->next = new_node;
}
