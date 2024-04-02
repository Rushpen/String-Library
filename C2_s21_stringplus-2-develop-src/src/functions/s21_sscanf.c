#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "../s21_string.h"

#define LLONG_MAX 0x7fffffffffffffff
#define LLONG_MIN (-LLONG_MAX - 1LL)
#define ULLONG_MAX 0xffffffffffffffff
#define INT_MAX 0x7fffffff

typedef enum {
  spec_c,
  spec_d,
  spec_i,
  spec_e,
  spec_E,
  spec_f,
  spec_g,
  spec_G,
  spec_o,
  spec_s,
  spec_u,
  spec_x,
  spec_X,
  spec_p,
  spec_n,
  spec_unknown,
} sspecs;

typedef enum lens { len_none, len_h, len_l, len_L, len_hh } lens;

typedef struct {
  sspecs spec;
  long long width;
  lens len;
  bool skip;
  bool formatSpace;
} specifier;

typedef struct {
  char type;
  int base;
  int sign;
} characs_of_number;

int s21_sscanf(const char *str, const char *format, ...);
bool scan_specifier(specifier *spec, const char **format, const char **str,
                    characs_of_number charact_numb);
bool scan(specifier spec, const char **str, va_list ap, int *res, char *start,
          characs_of_number charact_numb);
bool parse_based_int(specifier spec, const char **str, va_list ap,
                     characs_of_number charact_numb);
bool parse_float(specifier spec, const char **str, va_list ap,
                 characs_of_number charact_numb);
bool parse_based_uint(specifier spec, const char **str, va_list ap,
                      characs_of_number charact_numb);
bool parse_string(specifier spec, const char **str, va_list ap);
bool parse_ptr(specifier spec, const char **str, va_list ap,
               characs_of_number charact_numb);
bool parse_hex(const char **str, long long width, void *dest,
               characs_of_number charact_numb);
bool parse_oct(const char **str, long long width, void *dest,
               characs_of_number charact_numb);
bool scan_based_int(const char **str, long long width, void *dest,
                    characs_of_number charact_numb);
void parse_spec_n(specifier spec, const char **str, const char *start,
                  va_list ap);
bool scan_float(const char **str, long long width, long double *dest,
                characs_of_number charact_numb);
bool nan_inf(const char **str, long double *dest);
bool is_digit(char c, int base);
bool scientific(const char **str, long long *width, long double *dest,
                characs_of_number charact_numb);
long double s21_pow_int(double base, int exp);
int sign_width(long long *width, const char **str);
size_t to_digit(char c, int base);

int s21_sscanf(const char *str, const char *format, ...) {
  characs_of_number charact_numb;
  charact_numb.type = 's';
  charact_numb.base = 10;
  charact_numb.sign = 1;
  specifier spec = {0};
  spec.formatSpace = false;
  int result = *str ? 0 : -1;
  va_list ap;
  va_start(ap, format);
  char *start = (char *)str;
  bool stop = false;
  while (*format && result != -1 && !stop) {
    if (scan_specifier(&spec, &format, &str, charact_numb)) {
      if (scan(spec, &str, ap, &result, start, charact_numb)) {
        if (spec.spec != spec_n && !spec.skip) result++;
      } else
        stop = true;
    } else
      stop = true;
  }
  va_end(ap);
  return result;
}

bool scan_specifier(specifier *res, const char **format, const char **str,
                    characs_of_number charact_numb) {
  bool result = true;
  res->skip = false;
  if (isspace(**format)) {
    res->formatSpace = true;
    while (isspace(**format)) (*format)++;
  }

  if (**format != '%') {
    if (**str == **format) {
      (*str)++;
      (*format)++;
      while (isspace(**format)) (*format)++;
    } else
      result = false;
  } else {
    (*format)++;
    if (**format == '%') {
      if (**str == '%') {
        (*str)++;
        (*format)++;
      } else
        result = false;
    }
  }

  if (**format == '%') {
    (*format)++;
  }
  if (**format == '*') {
    res->skip = true;
    (*format)++;
  }

  if (is_digit(**format, 10)) {
    scan_based_int(format, INT_MAX, &res->width, charact_numb);
  }

  if (**format == 'l') {
    res->len = len_l;
    (*format)++;
    if (**format == 'l') {
      res->len = len_L;
      (*format)++;
    }
  } else if (**format == 'h') {
    (*format)++;
    if (**format == 'h') {
      res->len = len_hh;
      (*format)++;
    } else
      res->len = len_h;

  } else if (**format == 'L') {
    res->len = len_L;
    (*format)++;
  } else {
    res->len = len_none;
  }
  if (**format) {
    const char *spec_str = "cdieEfgGosuxXpn";
    char *pos = s21_strchr(spec_str, **format);
    if (pos) {
      res->spec = (sspecs)(pos - spec_str);
    } else {
      res->spec = spec_unknown;
    }
    (*format)++;
  } else
    result = false;
  return result;
}

bool scan(specifier spec, const char **str, va_list ap, int *res, char *start,
          characs_of_number charact_numb) {
  bool result = false;
  while (spec.formatSpace ? isspace(**str) : **str == ' ') (*str)++;
  if (spec.spec == spec_n) {
    parse_spec_n(spec, str, start, ap);
    result = true;
  }

  if (**str && !result) {
    switch (spec.spec) {
      case spec_d:
      case spec_i:
        charact_numb.type = 's';
        result = parse_based_int(spec, str, ap, charact_numb);
        break;
      case spec_G:
      case spec_g:
      case spec_E:
      case spec_e:
      case spec_f:
        charact_numb.type = 's';
        result = parse_float(spec, str, ap, charact_numb);
        break;
      case spec_p:
        charact_numb.type = 'u';
        result = parse_ptr(spec, str, ap, charact_numb);
        break;
      case spec_u:
      case spec_x:
      case spec_X:
      case spec_o:
        charact_numb.type = 'u';
        result = parse_based_uint(spec, str, ap, charact_numb);
        break;
      case spec_c:
      case spec_s:
        result = parse_string(spec, str, ap);
        break;

      case spec_unknown:
        result = false;
        // *res = -1;
        break;
      default:
        *res = -1;
        break;
    }
  } else if (!**str) {
    if (*res == 0) *res = -1;
  }

  return result;
}

void parse_spec_n(specifier spec, const char **str, const char *start,
                  va_list ap) {
  long long res = *str - start;

  switch (spec.len) {
    case len_none:
      *(va_arg(ap, int *)) = (int)res;
      break;
    case len_h:
      *(va_arg(ap, short *)) = (short)res;
      break;
    case len_hh:
      *(va_arg(ap, char *)) = (char)res;
      break;
    case len_l:
      *(va_arg(ap, long *)) = (long)res;
      break;
    case len_L:
      *(va_arg(ap, long long *)) = res;
      break;
    default:
      break;
  }
}

bool parse_based_int(specifier spec, const char **str, va_list ap,
                     characs_of_number charact_numb) {
  long long res = 0;
  bool result = false;
  charact_numb.sign = sign_width(&spec.width, str);
  if (spec.spec == spec_i) {
    if (**str == '0' && spec.width > 1) {
      result = true;
      spec.width--;
      (*str)++;
      if (**str == 'x' || **str == 'X') {
        spec.width--;
        (*str)++;
        charact_numb.base = 16;
        parse_hex(str, spec.width, &res, charact_numb);
      } else {
        charact_numb.base = 8;
        parse_oct(str, spec.width, &res, charact_numb);
      }
    } else {
      charact_numb.base = 10;
      result = scan_based_int(str, spec.width, &res, charact_numb);
    }
  }
  if (spec.spec == spec_d)
    result = scan_based_int(str, spec.width, &res, charact_numb);
  if (result) res = res * charact_numb.sign;

  if (result && !spec.skip) {
    switch (spec.len) {
      case len_none:
        *(va_arg(ap, int *)) = (int)res;
        break;
      case len_h:
        *(va_arg(ap, short *)) = (short)res;
        break;
      case len_hh:
        *(va_arg(ap, char *)) = (char)res;
        break;
      case len_l:
        *(va_arg(ap, long *)) = (long)res;
        break;
      case len_L:
        *(va_arg(ap, long long *)) = res;
        break;
      default:
        break;
    }
  }
  return result;
}

bool parse_based_uint(specifier spec, const char **str, va_list ap,
                      characs_of_number charact_numb) {
  unsigned long long res = 0;
  bool result = false;
  charact_numb.sign = sign_width(&spec.width, str);
  if (spec.width) {
    if (spec.spec == spec_u)
      result = scan_based_int(str, spec.width, &res, charact_numb);
    if (spec.spec == spec_o)
      result = parse_oct(str, spec.width, &res, charact_numb);
    if (spec.spec == spec_x || spec.spec == spec_X || spec.spec == spec_p)
      result = parse_hex(str, spec.width, &res, charact_numb);
  }
  if (result) res = res * charact_numb.sign;
  if (result && !spec.skip) {
    switch (spec.len) {
      case len_none:
        *(va_arg(ap, unsigned int *)) = (unsigned int)res;
        break;
      case len_h:
        *(va_arg(ap, unsigned short *)) = (unsigned short)res;
        break;
      case len_hh:
        *(va_arg(ap, unsigned char *)) = (unsigned char)res;
        break;
      case len_l:
        *(va_arg(ap, unsigned long *)) = (unsigned long)res;
        break;
      case len_L:
        *(va_arg(ap, unsigned long long *)) = (unsigned long long)res;
        break;
    }
  }
  return result;
}

bool parse_float(specifier spec, const char **str, va_list ap,
                 characs_of_number charact_numb) {
  long double res = 0;
  int neg = sign_width(&spec.width, str);
  bool result = scan_float(str, spec.width, &res, charact_numb);
  if (result) res = res * neg;
  if (result && !spec.skip) {
    switch (spec.len) {
      case len_none:
        *(va_arg(ap, float *)) = (float)res;
        break;
      case len_h:
        *(va_arg(ap, float *)) = (float)res;
        break;
      case len_l:
        *(va_arg(ap, double *)) = (double)res;
        break;
      case len_L:
        *(va_arg(ap, long double *)) = res;
        break;
      default:
        break;
    }
  }
  return result;
}

bool scan_based_int(const char **str, long long width, void *dest,
                    characs_of_number charact_numb) {
  bool found = false;
  unsigned long long idest = 0, max = 0;
  if (charact_numb.type == 's') max = LLONG_MAX;
  if (charact_numb.type == 'u') max = ULLONG_MAX;
  while (is_digit(**str, charact_numb.base) && width--) {
    found = true;
    if (idest > (max - (unsigned long long)to_digit(**str, charact_numb.base)) /
                    charact_numb.base) {
      idest = max;
      if (charact_numb.sign == -1) idest = -idest - 1;
      while (is_digit(**str, charact_numb.base)) (*str)++;
      continue;
    } else {
      idest = idest * charact_numb.base + to_digit(**str, charact_numb.base);
      (*str)++;
    }
  }
  if (found) {
    if (charact_numb.type == 's') *(long long *)dest = idest;
    if (charact_numb.type == 'u') *(unsigned long long *)dest = idest;
  }
  return found;
}

bool scan_float(const char **str, long long width, long double *dest,
                characs_of_number charact_numb) {
  bool found = false;
  if (nan_inf(str, dest) && width >= 3) {
    found = true;
    *str += 3;
  } else if (is_digit(**str, 10) ||
             (**str == '.' && is_digit(*(*str + 1), 10))) {
    found = true;
    while (is_digit(**str, 10) && width--) {
      *dest = *dest * 10 + (**str - '0');
      (*str)++;
    }
    if (**str == '.') {
      (*str)++;
      width--;
      long double frac_coef = 1;
      int frac_width = 0;
      while (is_digit(*(*str + frac_width), 10) && width--) frac_width++;
      while (frac_width--) {
        frac_coef /= 10;
        *dest += frac_coef * (**str - '0');
        (*str)++;
      }
    }
    if ((**str == 'e' || **str == 'E') && width > 0)
      scientific(str, &width, dest, charact_numb);
  }
  return found;
}

bool parse_hex(const char **str, long long width, void *dest,
               characs_of_number charact_numb) {
  bool found = false;
  charact_numb.base = 16;
  if (**str == '0' && ((*(*str + 1) == 'x') || *(*str + 1) == 'X')) {
    *str += 2;
    width -= 2;
    found = true;
  }

  found |= scan_based_int(str, width, dest, charact_numb);
  return found;
}

bool parse_oct(const char **str, long long width, void *dest,
               characs_of_number charact_numb) {
  bool found = false;
  charact_numb.base = 8;
  if (**str == '0') {
    (*str)++;
    width--;
    found = true;
  }
  found |= scan_based_int(str, width, dest, charact_numb);

  return found;
}

bool parse_string(specifier spec, const char **str, va_list ap) {
  bool result = false;
  char *dest = va_arg(ap, char *);
  if (spec.width == 0) {
    if (spec.spec == spec_c) {
      spec.width = 1;
    } else {
      spec.width = INT_MAX;
    }
  }

  while (**str && spec.width > 0 && **str != ' ') {
    result = true;
    *dest++ = **str;
    (*str)++;
    spec.width--;
  }
  if (spec.spec == spec_s) {
    *dest = '\0';
  }
  return result;
}

bool parse_ptr(specifier spec, const char **str, va_list ap,
               characs_of_number charact_numb) {
  spec.len = len_l;
  return parse_based_uint(spec, str, ap, charact_numb);
}

int sign_width(long long *width, const char **str) {
  int neg = 1;
  if (*width == 0) (*width) = INT_MAX;
  if (**str == '-' || **str == '+') {
    if (**str == '-') neg = -1;
    (*str)++;
    (*width)--;
  }
  return neg;
}

bool nan_inf(const char **str, long double *dest) {
  bool res = false;
  if (s21_strncmp(*str, "nan", 3) == 0 || s21_strncmp(*str, "NAN", 3) == 0) {
    res = true;
    *dest = NAN;
  } else if (s21_strncmp(*str, "inf", 3) == 0 ||
             s21_strncmp(*str, "INF", 3) == 0) {
    res = true;
    *dest = INFINITY;
  }
  return res;
}

bool scientific(const char **str, long long *width, long double *dest,
                characs_of_number charact_numb) {
  long long exp = 0;
  bool find = false;
  float pow_base = 10;
  (*str)++;
  (*width)--;
  if (sign_width(width, str) == -1) pow_base = 0.1;
  find = scan_based_int(str, *width, &exp, charact_numb);
  *dest *= s21_pow_int(pow_base, exp);
  return find;
}

bool is_digit(char c, int base) {
  bool res;
  if (base <= 10) {
    res = c >= '0' && c < '0' + base;
  } else {
    res = (c >= '0' && c <= '9') || (c >= 'A' && c < 'A' + base - 10) ||
          (c >= 'a' && c < 'a' + base - 10);
  }
  return res;
}

long double s21_pow_int(double base, int exp) {
  long double res = 1.0;
  if (exp != 0) {
    for (int i = 0; i < exp; i++) {
      res *= base;
    }
  }
  return res;
}
size_t to_digit(char c, int base) {
  size_t res = 0;
  if (base <= 10) {
    res = c - '0';
  } else {
    if (c <= '9') {
      res = c - '0';
    } else if (c <= 'A' + base - 10) {
      res = c - 'A' + 10;
    } else {
      res = c - 'a' + 10;
    }
  }
  return res;
}