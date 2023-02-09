#include "pipex.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char buf[10000];
	ft_bzero(buf, 10000);
	int fd = open(argv[1], O_RDONLY);
	read(fd, buf, 10000);
	char		**split;
	split =	single_mlc_split_quotes(buf, '\n');
	ft_printf("%s\n", split[13]);
	/*while (*split)
	{
		ft_printf("%s\n", split);
		split++;
	}*/
	return (0);
}
