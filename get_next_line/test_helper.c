#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"




void	free_stash(t_node **stash)
{
	t_node *ptr;

	ptr = *stash;
	while(*stash)
	{
		ptr = (*stash)->next;
		free ((*stash)->content);
		free (*stash);
		*stash = ptr;
	}
}

static void	cut_stash(t_node **stash, int len)
{
	t_node	*last;
	int		content_len;
	char	*left;
	int		i;
	t_node	*new_node;

	last = *stash;
	while(last->next)
		last = last->next;
	content_len = ft_strlen(last->content);
	left = malloc(sizeof(char) * (content_len + 1));
	if (!left)
		return ;
	i = 0;
	while (i < content_len)
	{
		left[i] = last->content[i];
		i++;
	}
	left[i] = '\0';
	free_stash(stash);
	if(left)
	{
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return ;
		new_node->content = left;
		new_node->next = NULL;
		*stash = new_node;
	}
}


int	main(void)
{
	t_node *new;
	char *left;
	t_node *stash1 = malloc(sizeof(t_node));
	t_node *stash2 = malloc(sizeof(t_node));
	t_node *stash3 = malloc(sizeof(t_node));

	stash1->content = "hello";
	stash2->content = "world";
	stash3->content = "hive\n";

	stash1->next = stash2;
	stash2->next = stash3;
	stash3->next = NULL;

	int len = stash_len(stash1);
	printf("Total length: %d\n", len);

	char *line = copy_stash(stash1, len);
	printf("Copied line: %s", line);

	cut_stash(&stash1, len);

	if (stash1 && stash1->content)
		printf("After cut_stash: %s\n", stash1->content);
	else
		printf("After cut_stash: (stash is empty)\n");

	free(line);
	free_stash(&stash1); // This handles freeing all remaining nodes and content

	return 0;
}