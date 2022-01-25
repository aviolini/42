#include "utils.hpp"

int ret_error(std::string s, int err)
{
	perror(s.c_str());
	std::cout << "error: " << err << "\n";
	return err;
}

void print_sockaddr_in (struct sockaddr_in *my_addr)
{
	std::cout << "------PRINT SOCKADDR_IN--------" << std::endl; 
	std::cout << "SOCKET FAMILY:\t" << my_addr->sin_family << std::endl;
	std::cout << "SOCKET ADDRESS:\t" << inet_ntoa(my_addr->sin_addr) << std::endl;
	std::cout << "SOCKET PORT:\t" << ntohs( my_addr->sin_port) << std::endl;
}

void print_addrinfo (struct addrinfo *hints)
{
	std::cout << "------PRINT ADDRINFO--------" << std::endl; 
               std::cout << "AI_FLAGS:\t" << hints->ai_flags << std::endl;
               std::cout << "AI_FAMILY:\t" << hints->ai_family << std::endl;
               std::cout << "AI_SOCKTYPE:\t" << hints->ai_socktype << std::endl;
               std::cout << "AI_PROTOCOL:\t" << hints->ai_protocol << std::endl;
               std::cout << "AI_ADDRLEN:\t" << hints->ai_addrlen << std::endl;
               print_sockaddr_in (((struct sockaddr_in *)(hints->ai_addr)));
            //    std::cout << "AI_CANONNAME:\t" << hints.ai_canonname << std::endl;
            //    print_sockaddr_in (*((struct sockaddr_in *)(&hints.ai_next)));
}

void print_fd (struct stat buf)
{
	std::cout << "------PRINT FSTAT--------" << std::endl; 
    std::cout << "ID OF DEVICE:\t" << buf.st_dev << std::endl;     /* ID of device containing file */
    std::cout << "INODE:\t\t" << buf.st_ino << std::endl;     /* inode number */
    std::cout << "PROTECION:\t" << buf.st_mode << std::endl;    /* protection */
    std::cout << "N HARD LINKS:\t" << buf.st_nlink << std::endl;   /* number of hard links */
    std::cout << "U OWNER:\t" << buf.st_uid << std::endl;     /* user ID of owner */
    std::cout << "G OWNER:\t" << buf.st_gid << std::endl;     /* group ID of owner */
    std::cout << "ID SPEC FILE:\t" << buf.st_rdev << std::endl;    /* device ID (if special file) */
    std::cout << "TOT SIZE:\t" << buf.st_size << std::endl;    /* total size, in bytes */
    std::cout << "BL SIZE:\t" << buf.st_blksize << std::endl; /* blocksize for file system I/O */
    std::cout << "BL ALL:\t\t" << buf.st_blocks << std::endl;  /* number of 512B blocks allocated */
    std::cout << "LAST ACCESS:\t" << buf.st_atime << std::endl;   /* time of last access */
    std::cout << "LAST MOD:\t" << buf.st_mtime << std::endl;   /* time of last modification */
    std::cout << "LAST CHANGE:\t" << buf.st_ctime << std::endl;   /* time of last status change */
}