#ifndef S21_STRING
#define S21_STRING
#define BUFF_SIZE 255
#define S21_NULL (void *)0
#define MY_ULONG_MAX ((unsigned long)(-1))
typedef long unsigned s21_size_t;

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
struct s21_sprintfParams
{
    int spec_c;
    int spec_d;
    int spec_i;
    int spec_e;
    int spec_E;
    int spec_f;
    int spec_g;
    int spec_G;
    int spec_o;
    int spec_s;
    int spec_u;
    int spec_x;
    int spec_X;
    int spec_p;
    int spec_procent;
    //
    int flag_minus;
    int flag_plus;
    int flag_space;
    int flag_sharp;
    int flag_zero;
    //
    int widthSetted;
    s21_size_t width;
    int widthStar;
    //
    int precSetted;
    int prec;
    int precStar;
    //
    int lenSetted;
    int len_h;
    int len_l;
    int len_L;
};

typedef struct s21_sprintfParams PARAMS;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(char *haystack, char *needle);
s21_size_t is_delim(char c, const char *delim);
char *s21_strtok(char *srcString, const char *delim);
//
int s21_sprintf(char *buf, const char *format, ...);
int getNumberFromString(char *str, s21_size_t *position);
void resetParams(PARAMS *params);
int isDigit(char c);
int parseSprintf(PARAMS *params, char *format, s21_size_t *iFormat);
void output2strUnsInt(char *buf, s21_size_t *iBuf, unsigned long long number, PARAMS params);
void output2strInt(char *buf, s21_size_t *iBuf, long long number, PARAMS params);
char *itoa(char *str, long long num, int radix, int caps);
char *itoa_unsigned(char *str, unsigned long long num, int radix, int caps);
void outputChr(char *buf, s21_size_t *iBuf, int c, PARAMS params);
void outputPtr(char *buf, s21_size_t *iBuf, unsigned long ptr, PARAMS params);
void outputStr(char *buf, s21_size_t *iBuf, char *s, PARAMS params);
void output_str_float (char *buf, s21_size_t *iBuf,long double number, PARAMS params);
char *ftoa(char *str, long double num, int accuracy);
char *ftoa_after_point(char *str, int accuracy, long double db_num);
void output_str_e (char *buf, s21_size_t *iBuf,long double number, PARAMS params);
char *etoa(char *str, long double num, int accuracy, int caps);
long double normolaze(char *str, long double num, int caps);
long double s21_fabs(long double x);
long double s21_ceil(long double x);
long double s21_fmod(long double x, long double y);
void output_plus_minus (char *buf, s21_size_t **iBuf, s21_size_t startIBuf, PARAMS params, s21_size_t neg);
char *gtoa(char *str, long double num, int caps, int prec, int sharp);
void output_str_g (char *buf, s21_size_t *iBuf,long double number, PARAMS params);
void star_check(PARAMS *params, va_list valist);
void check_len_d(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist);
void check_len_u(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist);
void check_len_f(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist);
void check_len_e(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist);
void check_len_g(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist);

//
int s21_sscanf(const char *str, const char *format, ...);
//
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif
