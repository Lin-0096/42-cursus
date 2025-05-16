# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

static int	stash_len(t_node *stash)
{
	int	len;
	int	j;
	
	len = 0;
	while(stash)
	{
		j = 0;
		while(stash->content[j])
		{
			len++;
			if (stash->content[j] == '\n')
				break ;
			j++;
		}
		stash  = stash->next;
	}
	return (len);
}
static char	*copy_stash(t_node *stash, int len)
{
	char	*line;
	int		i;
	int		j;
	
	line = malloc(len+1);
	if(!line)
		return (NULL);
	i = 0;
	while(stash && i < len)
	{
		j = 0;
		while(stash->content[j] && i < len)
		{
			line[i++] = stash->content[j];
			if (stash->content[j] == '\n')
				break ;
			j++;
		}
		stash = stash->next;
	}
	line[i] = '\0';
	return (line);
}

int	main(void)
{
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
	printf("%i\n", len);
	char *line = copy_stash(stash1, len);
	printf("%s", line);

	free(line);
	free(stash1);
	free(stash2);
	free(stash3);

	return 0;
}