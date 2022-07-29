#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
size_t      ft_strlen(const char *str);
int         ft_strcmp(const char *str1, const char *str2);
ssize_t     ft_read(int fildes, void *buf, size_t nbyte);
ssize_t     ft_write(int fildes, const void *buf, size_t nbyte);
char        *ft_strcpy(char *dst, const char *src);
char        *ft_strdup(const char *s1);
#define     INVALID_FD -1
#define     SIMPLE_STRING "Hello world"
#define     NBYTE 10
#define     EMPTY_STRING ""
#define     LONG_STRING "Why do they not teach you that time is a finger snap and an eye blink, and that you should not allow a moment to pass you by without taking joyous, ecstatic note of it, not wasting a single moment of its swift, breakneck circuit?"
void ft_strlen_tests()
{
    printf("--------------FT_STRLEN----------------\n");
    printf("------------EMPTY STRING---------------\n");
    printf("strlen:%zu\n", strlen(EMPTY_STRING));
    printf("ft_strlen:%zu\n", ft_strlen(EMPTY_STRING));
    printf("--------------LONG STRING---------------\n");
    printf("strlen:%zu\n", strlen(LONG_STRING));
    printf("ft_strlen:%zu\n", ft_strlen(LONG_STRING));
}
void ft_strcmp_tests()
{
    char *str1 = "1239";
    char *str2 = "1234";
    printf("-------------------------FT_STRCMP------------------------\n");
    printf("------------------------SAME_STRING-----------------------\n");
    printf("strcmp:%d\n", strcmp(SIMPLE_STRING, SIMPLE_STRING));
    printf("ft_strcmp:%d\n", ft_strcmp(SIMPLE_STRING, SIMPLE_STRING));
    printf("------------------------SIMPLE_CASE-----------------------\n");
    printf("strcmp:%d\n", strcmp(str1, str2));
    printf("ft_strcmp:%d\n", ft_strcmp(str1, str2));
    printf("------------str1=EMPTY_STRING|str2=SIMPLE_STRING----------\n");
    printf("strcmp:%d\n", strcmp(EMPTY_STRING, SIMPLE_STRING));
    printf("ft_strcmp:%d\n", ft_strcmp(EMPTY_STRING, SIMPLE_STRING));
    printf("------------str1=SIMPLE_STRING|str2=EMPTY_STRING----------\n");
    printf("strcmp:%d\n", strcmp(SIMPLE_STRING, EMPTY_STRING));
    printf("ft_strcmp:%d\n", ft_strcmp(SIMPLE_STRING, EMPTY_STRING));
}
void ft_read_tests()
{
    int fd1 = open("test.c", O_RDONLY);
    int fd2 = open("test.c", O_RDONLY);
    char *str = malloc(sizeof(char) * 20);
    printf("--------------FT_READ-------------------\n");
    printf("-------------NORMAL FD-----------------\n");
    printf("ft_read===>buffer:%s|return:%zd|errno:%d\n", str, ft_read(fd1, str, NBYTE), errno);
    printf("read======>buffer:%s|return:%zd|errno:%d\n", str, read(fd2, str, NBYTE), errno);
    printf("-------------INVALID FD-----------------\n");
    printf("ft_read===>buffer:%s|return:%zd|errno:%d\n", str, ft_read(INVALID_FD, str, NBYTE), errno);
    printf("read======>buffer:%s|return:%zd|errno:%d\n", str, read(INVALID_FD, str, NBYTE), errno);
    printf("----------------------------------------\n");
}
void ft_write_tests()
{
    int fd1 = open("file1.txt", O_WRONLY);
    int fd2 = open("file2.txt", O_WRONLY);
    printf("--------------FT_WRITE-------------------\n");
    printf("-------------NORMAL FD-----------------\n");
    printf("ft_write===>return:%zd|errno:%d\n",  ft_write(fd1, LONG_STRING, NBYTE), errno);
    printf("write======>return:%zd|errno:%d\n",  write(fd2, LONG_STRING, NBYTE), errno);
    printf("-------------INVALID FD-----------------\n");
    printf("ft_write===>return:%zd|errno:%d\n", ft_write(INVALID_FD, LONG_STRING, NBYTE), errno);
    printf("write======>return:%zd|errno:%d\n", write(INVALID_FD, LONG_STRING, NBYTE), errno);
}
void ft_strcpy_tests()
{
    char *dst1 = malloc(sizeof(char) * 3);
    char *dst2 = malloc(sizeof(char) * 3);
    printf("-------------FT_STRCPY-------------------\n");
    printf("strcpy=====>return: %s| dest: %s\n", strcpy(dst1, EMPTY_STRING), dst1);
    printf("ft_strcpy==>return: %s| dest: %s\n", ft_strcpy(dst2, EMPTY_STRING), dst2);
    printf("----------------------------------------\n");
}
void ft_strdup_tests()
{
    printf("-------------FT_STRDUP-------------\n");
    printf("strdup=====>%s\n", strdup(LONG_STRING));
    printf("ft_strdup==>%s\n", ft_strdup(LONG_STRING));
    printf("----------------------------------------\n");
    printf("strdup=====>%s\n", strdup(EMPTY_STRING));
    printf("ft_strdup==>%s\n", ft_strdup(EMPTY_STRING));
    printf("----------------------------------------\n");
}
int main()
{
    ft_strlen_tests();
    ft_read_tests();
    ft_write_tests();
    ft_strcpy_tests();
    ft_strdup_tests();
   ft_strcmp_tests();
    return (0);
}