#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>


#define S21_NULL (void *)0
#define S21_SIZE_T unsigned long

#define EPERM 1
#define ENOENT 2
#define ESRCH 3
#define EINTR 4
#define EIO 5
#define ENXIO 6
#define E2BIG 7
#define ENOEXEC 8
#define EBADF 9
#define ECHILD 10
#define EDEADLK 11
#define ENOMEM 12
#define EACCES 13
#define EFAULT 14
#define ENOTBLK 15
#define EBUSY 16
#define EEXIST 17
#define EXDEV 18
#define ENODEV 19
#define ENOTDIR 20
#define EISDIR 21
#define EINVAL 22
#define ENFILE 23
#define EMFILE 24
#define ENOTTY 25
#define ETXTBSY 26
#define EFBIG 27
#define ENOSPC 28
#define ESPIPE 29
#define EROFS 30
#define EMLINK 31
#define EPIPE 32

/* math software */
    #define EDOM 33
    #define ERANGE 34

    /* non-blocking and interrupt i/o */
    #define EAGAIN 35
    #define EINPROGRESS 36
    #define EALREADY 37

    /* ipc/network software -- argument errors */
    #define ENOTSOCK 38
    #define EDESTADDRREQ 39
    #define EMSGSIZE 40
    #define EPROTOTYPE 41
    #define ENOPROTOOPT 42
    #define EPROTONOSUPPORT 43
    #define ESOCKTNOSUPPORT 44
    #define EOPNOTSUPP 45
    #define EPFNOSUPPORT 46
    #define EAFNOSUPPORT 47
    #define EADDRINUSE 48
    #define EADDRNOTAVAIL 49

    /* ipc/network software -- operational errors */
    #define ENETDOWN 50
    #define ENETUNREACH 51
    #define ENETRESET 52
    #define ECONNABORTED 53
    #define ECONNRESET 54
    #define ENOBUFS 55
    #define EISCONN 56
    #define ENOTCONN 57
    #define ESHUTDOWN 58
    #define ETOOMANYREFS 59
    #define ETIMEDOUT 60
    #define ECONNREFUSED 61

    #define ELOOP 62
    #define ENAMETOOLONG 63

    /* should be rearranged */
    #define EHOSTDOWN 64
    #define EHOSTUNREACH 65
    #define ENOTEMPTY 66

    /* quotas & mush */
    #define EPROCLIM 67
    #define EUSERS 68
    #define EDQUOT 69

    /* Network File System */
    #define ESTALE 70
    #define EREMOTE 71
    #define EBADRPC 72
    #define ERPCMISMATCH 73
    #define EPROGUNAVAIL 74
    #define EPROGMISMATCH 75
    #define EPROCUNAVAIL 76

    #define ENOLCK 77
    #define ENOSYS 78
    #define EFTYPE 79

    #define EAUTH 80

    #define ENEEDAUTH 81

    #define EIDRM 82
    #define ENOMSG 83

    #define EOVERFLOW 84

    #define ECANCELED 85
    #define EILSEQ 86

    #define ENOATTR 87

    /* General */

    #define EDOOFUS 88
    #define EBADMSG 89
    #define EMULTIHOP 90
    #define ENOLINK 91
    #define EPROTO 92

void *s21_memchr(const void *str, int c, S21_SIZE_T n);
int s21_memcmp(const void *str1, const void *str2, S21_SIZE_T n);
void *s21_memcpy(void *dest, const void *src, S21_SIZE_T n);
void *s21_memmove(void *dest, const void *src, S21_SIZE_T n);
void *s21_memset(void *str, int c, S21_SIZE_T n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, S21_SIZE_T n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, S21_SIZE_T n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, S21_SIZE_T n);
S21_SIZE_T s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
S21_SIZE_T s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
S21_SIZE_T s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, S21_SIZE_T start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_
