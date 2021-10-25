/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviolini <aviolini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:30:23 by aviolini          #+#    #+#             */
/*   Updated: 2021/04/27 10:00:59 by aviolini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h" 
#define SPACE "------------"

void test_ft_strlen()
{
    char    *arg_strlen;

    arg_strlen = "ciaociao";
	printf("\n\n");
    printf("|--FT_STRLEN: \n");
    printf("|ARG:\t\t%s\n", arg_strlen);
    printf("|original:\t%lu\n", strlen(arg_strlen));
    printf("|my:\t\t%lu\n", ft_strlen(arg_strlen));
    printf("|%s\n\n\n", SPACE);
}

void test_ft_strcpy()
{
	char    src[15] = "sorgente";
	char    dst[15] = "destinazione";
    char    src_temp[15];
    char    dst_temp[15];
	
	strcpy(dst_temp, dst);
	strcpy(src_temp, src);
    printf("|--FT_STRCPY: \n");
    printf("|ARGS:\t\tdst: %s\tsrc: %s\n", dst,src);
    printf("|original:\t%s\n", strcpy(dst, src));
	printf("|my:\t\t%s\n", ft_strcpy(dst_temp, src_temp));
    printf("|%s\n\n\n", SPACE);
}

void test_ft_strcmp()
{
	 char    str1[15] = "sorgente";
    char    str2[15] = "sorgente";
    printf("|--FT_STRCMP: \n");
    printf("|ARGS:\tstr1: %s\tstr2: %s\n",str1,str2);
    printf("|original:\t%d\n",strcmp(str1,str2));
	printf("|my:\t\t%d\n",ft_strcmp(str1,str2));
	printf("|ARGS:\tdst: %s\tsrc: %s\n",str1,str2);
    printf("|%s\n\n\n",SPACE);
}

void	test_ft_write()
{
	int		fd = 1;
	char	str[15] = "sorgente";
    int		buffer_size = 6;
	int		errno;

	errno = 0;
    printf("|--FT_WRITE: \n");
    printf("|ARGS %d,%s,%d\n",fd,str,buffer_size);
    write(1, "|original: \t", 12);
	printf("\tret: %ld\n",write(fd,str,buffer_size));
	printf("|original:\terrno: %d\t error: %s\n",errno,strerror(errno));
	errno = 0;
	write(1, "|my: \t\t",7);
	printf("\tret: %ld\n",ft_write(fd,str,buffer_size));
	printf("|my:\t\terrno: %d\t error: %s\n",errno,strerror(errno));
    printf("|%s\n\n\n",SPACE);
}

void	test_ft_read()
{
	int		fd1;
	int		buffer_size = 6;
	char	*arg_open = "./test_read";;
	char 	read_str[buffer_size];
	char	read_str1[buffer_size];
	char	buffer[1024];
	int		errno;
	
	fd1 = open (arg_open, O_RDONLY );
	errno = 0;
	read(fd1, buffer, 20);
	close(fd1);
	errno = 0;
	fd1 = open (arg_open, O_RDONLY );
	printf("|--FT_READ: \n");
    printf("|ARGS %d,%s,%d\n",fd1, buffer, buffer_size);
    printf("|original:\t%zd\n",read(fd1, read_str, buffer_size));
	printf("|original:\terrno: %d\t error: %s\n", errno, strerror(errno));
	printf("|original:\tbuffer: %s\n", read_str);
	close(fd1);
	errno = 0;
	fd1 = open (arg_open, O_RDONLY );
	printf("|my:\t\t%zd\n",ft_read(fd1, read_str1, buffer_size));
	printf("|my:\t\terrno: %d\t error: %s\n", errno, strerror(errno));
	printf("|my:\t\tbuffer: %s\n", read_str1);
    printf("|%s\n\n\n", SPACE);
	close(fd1);
}

void	test_ft_strdup()
{
	const char	s[15] = "sorgente";
	char		*ret1;
	char		*ret2;
	int			errno;
	
    printf("|--FT_STRDUP: \n");
	printf("|ARGS %s\n", s);
	errno = 0;
	ret1 = strdup(s);
	ret2 = ft_strdup(s);
    printf("|original:\t%s\n", ret1);
    printf("|my:\t\t%s\n", ret2);
	printf("|my:\t\terrno: %d\t error: %s\n", errno, strerror(errno));
    printf("|%s\n\n\n", SPACE);
	free(ret1);
	free(ret2);
}

int main()
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();

    return 0;
}



