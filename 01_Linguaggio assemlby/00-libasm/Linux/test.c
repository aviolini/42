/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arrigo <arrigo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:30:23 by aviolini          #+#    #+#             */
/*   Updated: 2021/04/23 23:49:51 by arrigo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm.h" 
#define SPACE "------------"


int main()
{
	printf("\n\n");
    char    *arg_strlen;
    arg_strlen = "ciaociao";
    printf("|--FT_STRLEN: \n");
    printf("|ARG:\t\t%s\n",arg_strlen);
    printf("|original:\t%lu\n",strlen(arg_strlen));
    printf("|my:\t\t%lu\n",ft_strlen(arg_strlen));
    printf("|%s\n\n\n",SPACE);
//////////////////////////////////////////////////////////
    char    src[15] = "sorgente";
	char    dst[15] = "destinazione";
    char    src_temp[15];
    char    dst_temp[15];
	//char 	dst2_temp[15];
	strcpy(dst_temp,dst);
	strcpy(src_temp,src);
    printf("|--FT_STRCPY: \n");
    printf("|ARGS:\t\tdst: %s\tsrc: %s\n",dst,src);
    printf("|original:\t%s\n",strcpy(dst,src));
	printf("|my:\t\t%s\n",ft_strcpy(dst_temp,src_temp));
    printf("|%s\n\n\n",SPACE);
//////////////////////////////////////////
    char    str1[15] = "soagente";
    char    str2[15] = "soagente";
    printf("|--FT_STRCMP: \n");
    printf("|ARGS:\tstr1: %s\tstr2: %s\n",str1,str2);
    printf("|original:\t%d\n",strcmp(str1,str2));
	printf("|my:\t\t%d\n",ft_strcmp(str1,str2));
	printf("|ARGS:\tdst: %s\tsrc: %s\n",str1,str2);
    printf("|%s\n\n\n",SPACE);
///////////////////////////////////////////////////////////
	int		fd = 1;
	char	str[15] = "sorgenteee";
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
 ///////////////////////////////////////////////////////////
    printf("|--FT_READ: \n");
	int fd1;
	char *arg_open = "./test_read";
	fd1 = open (arg_open,O_RDONLY );
	char read_str[buffer_size];
	char read_str1[buffer_size];
	char buffer[1024];
	
	errno = 0;
	read(fd1, buffer, 20);
	close(fd1);
	errno = 0;
	fd1 = open (arg_open,O_RDONLY );
    printf("|ARGS %d,%s,%d\n",fd1,buffer,buffer_size);
    printf("|original:\t%zd\n",read(fd1,read_str,buffer_size));
	printf("|original:\terrno: %d\t error: %s\n",errno,strerror(errno));
	printf("|original:\tbuffer: %s\n", read_str);
	close(fd1);
	errno = 0;
	fd1 = open (arg_open,O_RDONLY );
	printf("|my:\t\t%zd\n",ft_read(fd1,read_str1,buffer_size));
	printf("|my:\t\terrno: %d\t error: %s\n",errno,strerror(errno));
	printf("|my:\t\tbuffer: %s\n", read_str1);
    printf("|%s\n\n\n",SPACE);
	close(fd1);

 ///////////////////////////////////////////////////////////
    const char		s[15] = "sorgente";
	char			*ret1;
	char			*ret2;
    printf("|--FT_STRDUP: \n");
    printf("|ARGS %s\n",s);
	errno = 0;
	ret1 = strdup(s);
	ret2 = ft_strdup(s);
    printf("|original:\t%s\n",ret1);
    printf("|my:\t\t%s\n",ret2);
	printf("|my:\t\terrno: %d\t error: %s\n",errno,strerror(errno));
    printf("|%s\n\n\n",SPACE);
	free(ret1);
	free(ret2);
//////////////////////////////////////////////////////////////
	




    return 0;
}



