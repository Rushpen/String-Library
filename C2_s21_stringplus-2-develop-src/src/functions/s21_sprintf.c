#include <math.h>

#include "../s21_string.h"

int parseSprintf(PARAMS *params, char *format, s21_size_t *iFormat) {
  int exit = 0;
  while (format[*iFormat] && !exit) {
    if (format[*iFormat] == '0' && !params->widthSetted &&
        !params->precSetted) {
      params->flag_zero = 1;
      (*iFormat)++;
      continue;
    }
    if (isDigit(format[*iFormat])) {
      if (params->precSetted == 0) {
        params->widthSetted = 1;
        params->width = getNumberFromString(format + *iFormat, iFormat);
      } else {
        params->precSetted = 1;
        params->prec = getNumberFromString(format + *iFormat, iFormat);
      }
    }
    switch (format[*iFormat]) {
      case '*':
        if (params->precSetted) {
          params->precStar = 1;
        } else {
          params->widthStar = 1;
        }
        break;
      case '-':
        params->flag_minus = 1;
        break;
      case '+':
        params->flag_plus = 1;
        break;
      case ' ':
        params->flag_space = 1;
        break;
      case '#':
        params->flag_sharp = 1;
        break;
      case '.':
        params->precSetted = 1;
        break;
      case 'h':
        if (!params->lenSetted) {
          params->lenSetted = 1;
          params->len_h = 1;
        }
        break;
      case 'l':
        if (!params->lenSetted) {
          params->lenSetted = 1;
          params->len_l = 1;
        } else if (params->lenSetted && params->len_l == 1) {
          params->len_l = 2;
        }
        break;
      case 'L':
        if (!params->lenSetted) {
          params->lenSetted = 1;
          params->len_L = 1;
        }
        break;
      case 'c':
        params->spec_c = 1;
        exit = 1;
        break;
      case 'd':
        params->spec_d = 1;
        exit = 1;
        break;
      case 'e':
        if (!params->precSetted) {
          params->precSetted = 1;
          params->prec = 6;
        }
        params->spec_e = 1;
        exit = 1;
        break;
      case 'E':
        if (!params->precSetted) {
          params->precSetted = 1;
          params->prec = 6;
        }
        params->spec_E = 1;
        exit = 1;
        break;
      case 'f':
        if (!params->precSetted) {
          params->precSetted = 1;
          params->prec = 6;
        }
        params->spec_f = 1;
        exit = 1;
        break;
      case 'g':
        if (!params->precSetted) {
          params->precSetted = 1;
          params->prec = 6;
        }
        params->spec_g = 1;
        exit = 1;
        break;
      case 'G':
        if (!params->precSetted) {
          params->precSetted = 1;
          params->prec = 6;
        }
        params->spec_G = 1;
        exit = 1;
        break;
      case 'o':
        params->spec_o = 1;
        exit = 1;
        break;
      case 's':
        params->spec_s = 1;
        exit = 1;
        break;
      case 'u':
        params->spec_u = 1;
        exit = 1;
        break;
      case 'x':
        params->spec_x = 1;
        exit = 1;
        break;
      case 'X':
        params->spec_X = 1;
        exit = 1;
        break;
      case 'p':
        params->spec_p = 1;
        exit = 1;
        break;
      case '%':
        params->spec_procent = 1;
        exit = 1;
        break;
      default:  // We need to decide what we will do with wrong key (we need
                // f#10)
        break;
    }
    if (!exit) (*iFormat)++;
  }

  return 1;  // errors later
}

int getNumberFromString(char *str, s21_size_t *position) {
  int res = 0;
  for (s21_size_t i = 0; str[i]; i++, (*position)++) {
    if (isDigit(str[i])) {
      if (i == 0) {
        res = str[i] - 48;
      } else {
        res *= 10;
        res += str[i] - 48;
      }
      continue;
    } else {
      break;
    }
  }

  return res;
}

int isDigit(char c) { return c >= 48 && c <= 57 ? 1 : 0; }

void resetParams(PARAMS *params) {
  char *ptr = (char *)params;
  for (s21_size_t i = 0; i < sizeof(PARAMS); i++) {
    ptr[i] = 0;
  }
}

int s21_sprintf(char *buf, const char *format, ...) {
  PARAMS params = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  va_list valist;
  va_start(valist, format);
  s21_size_t iBuf = 0, iFormat = 0;
  char *chrformat = (char *)format;

  *buf = 0;

  while (format[iFormat]) {
    if (format[iFormat] == '%') {
      iFormat++;
      parseSprintf(&params, chrformat, &iFormat);
      if (params.spec_procent) {
        buf[iBuf++] = '%';
      }

      if (params.spec_c) {
        int c = va_arg(valist, int);
        outputChr(buf, &iBuf, c, params);
        iFormat++;
      }

      if (params.spec_d) {
        star_check(&params, valist);
        check_len_d(buf, &iBuf, params, valist);
        iFormat++;
      }

      if (params.spec_o || params.spec_u || params.spec_x || params.spec_X) {
        check_len_u(buf, &iBuf, params, valist);

        iFormat++;
      }

      if (params.spec_p) {
        outputPtr(buf, &iBuf, va_arg(valist, unsigned long), params);
        iFormat++;
      }

      if (params.spec_s) {
        char *tempPtr = va_arg(valist, char *);
        outputStr(buf, &iBuf, tempPtr, params);
        iFormat++;
      }
      if (params.spec_f) {
        star_check(&params, valist);
        check_len_f(buf, &iBuf, params, valist);
        iFormat++;
      }
      if (params.spec_e || params.spec_E) {
        star_check(&params, valist);
        check_len_e(buf, &iBuf, params, valist);

        iFormat++;
      }
      if (params.spec_g || params.spec_G) {
        star_check(&params, valist);
        check_len_g(buf, &iBuf, params, valist);
        iFormat++;
      }
    } else {
      buf[iBuf++] = format[iFormat];
      iFormat++;
    }
    buf[iBuf] = 0;
    resetParams(&params);
  }
  buf[iBuf] = 0;
  va_end(valist);
  return 0;
}

void star_check(PARAMS *params, va_list valist) {
  if (params->widthStar) {
    params->width = va_arg(valist, int);
    params->widthSetted = 1;
  }
  if (params->precStar) {
    params->prec = va_arg(valist, int);
    params->precSetted = 1;
  }
}

void check_len_d(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist) {
  if (params.lenSetted) {
    if (params.len_l == 1) {
      output2strInt(buf, iBuf, va_arg(valist, long int), params);
    } else if (params.len_l == 2) {
      output2strInt(buf, iBuf, va_arg(valist, long long), params);
    } else if (params.len_h) {
      output2strInt(buf, iBuf, (short int)va_arg(valist, int), params);
    }
  } else {
    output2strInt(buf, iBuf, va_arg(valist, int), params);
  }
}

void check_len_u(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist) {
  if (params.lenSetted) {
    if (params.len_l == 1) {
      output2strUnsInt(buf, iBuf, va_arg(valist, long unsigned int), params);
    } else if (params.len_l == 2) {
      output2strUnsInt(buf, iBuf, va_arg(valist, long long unsigned int),
                       params);
    } else if (params.len_h) {
      output2strUnsInt(
          buf, iBuf, (short unsigned int)va_arg(valist, unsigned int), params);
    }
  } else {
    output2strUnsInt(buf, iBuf, va_arg(valist, unsigned int), params);
  }
}

void check_len_f(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist) {
  if (params.lenSetted) {
    if (params.len_L) {
      output_str_float(buf, iBuf, va_arg(valist, long double), params);
    }
  } else {
    output_str_float(buf, iBuf, va_arg(valist, double), params);
  }
}

void check_len_e(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist) {
  if (params.lenSetted) {
    if (params.len_L) {
      output_str_e(buf, iBuf, va_arg(valist, long double), params);
    }
  } else {
    output_str_e(buf, iBuf, va_arg(valist, double), params);
  }
}

void check_len_g(char *buf, s21_size_t *iBuf, PARAMS params, va_list valist) {
  if (params.lenSetted) {
    if (params.len_L) {
      output_str_g(buf, iBuf, va_arg(valist, long double), params);
    }
  } else {
    output_str_g(buf, iBuf, va_arg(valist, double), params);
  }
}

void output_str_g(char *buf, s21_size_t *iBuf, long double number,
                  PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  if (params.spec_g == 1) {
    gtoa(buf + *iBuf, number, 0, params.prec, params.flag_sharp);
  }
  if (params.spec_G == 1) {
    gtoa(buf + *iBuf, number, 1, params.prec, params.flag_sharp);
  }
  s21_size_t neg = 0;
  s21_size_t mem = s21_strlen(buf + *iBuf);
  if (params.flag_sharp && (params.prec == 0 || (s21_fabs(number) < 1000000 &&
                                                 s21_fabs(number) >= 100000))) {
    s21_memcpy(buf + *iBuf + mem, ".", 2);
    mem = s21_strlen(buf + *iBuf);
  }
  if (number < 0 && params.flag_zero && mem < (s21_size_t)params.width) {
    neg = 1;
    s21_memcpy(buf + *iBuf, buf + *iBuf + 1, mem);
  }
  *iBuf += s21_strlen(buf + *iBuf);

  output_plus_minus(buf, &iBuf, startIBuf, params, neg);

  *iBuf += s21_strlen(buf + *iBuf);
}

void output_str_e(char *buf, s21_size_t *iBuf, long double number,
                  PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  if (params.spec_e == 1) {
    etoa(buf + *iBuf, number, params.prec, 0);
  }
  if (params.spec_E == 1) {
    etoa(buf + *iBuf, number, params.prec, 1);
  }
  s21_size_t neg = 0;
  s21_size_t mem = s21_strlen(buf + *iBuf);
  if (number < 0 && params.flag_zero && mem < (s21_size_t)params.width) {
    neg = 1;
    s21_memcpy(buf + *iBuf, buf + *iBuf + 1, mem);
  }

  *iBuf += s21_strlen(buf + *iBuf);

  output_plus_minus(buf, &iBuf, startIBuf, params, neg);
}

void output_str_float(char *buf, s21_size_t *iBuf, long double number,
                      PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  if (params.spec_f == 1) {
    ftoa(buf + *iBuf, number, params.prec);
  }
  s21_size_t neg = 0;
  s21_size_t mem = s21_strlen(buf + *iBuf);
  if (params.flag_sharp && params.prec == 0) {
    s21_memcpy(buf + *iBuf + mem, ".", 2);
    mem = s21_strlen(buf + *iBuf);
  }

  if (number < 0 && params.flag_zero && mem < (s21_size_t)params.width) {
    neg = 1;
    s21_memcpy(buf + *iBuf, buf + *iBuf + 1, mem);
  }
  *iBuf += s21_strlen(buf + *iBuf);

  output_plus_minus(buf, &iBuf, startIBuf, params, neg);
}

void output_plus_minus(char *buf, s21_size_t **iBuf, s21_size_t startIBuf,
                       PARAMS params, s21_size_t neg) {
  s21_size_t n = **iBuf - startIBuf;
  if (params.flag_minus) {
    for (s21_size_t i = n; i < (s21_size_t)params.width; i++) {
      *(buf + **iBuf) = ' ';
      *(buf + **iBuf + 1) = 0;
      (**iBuf)++;
    }
  } else {
    if (n < (s21_size_t)params.width) {
      *(buf + startIBuf + params.width) = 0;
      for (s21_size_t i = (s21_size_t)params.width; i > 0; i--) {
        if (i >= params.width - n) {
          *(buf + startIBuf + i) = *(buf + startIBuf + i - params.width + n);
        } else {
          *(buf + startIBuf + i) = params.flag_zero ? '0' : ' ';
        }
      }
      if (neg && params.flag_zero) {
        *(buf + startIBuf) = '-';
      } else {
        *(buf + startIBuf) = params.flag_zero ? '0' : ' ';
      }

      (**iBuf) += params.width - n;
    }
  }
}

void outputChr(char *buf, s21_size_t *iBuf, int c, PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  if (c != -1) {
    buf[*iBuf] = (char)c;
    (*iBuf)++;
  }
  output_plus_minus(buf, &iBuf, startIBuf, params, 0);
}

void outputPtr(char *buf, s21_size_t *iBuf, unsigned long ptr, PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  if (ptr == 0) {
    s21_strncat(buf + *iBuf, "(nil)", 5);
    *iBuf += 5;
  } else {
    if (params.spec_p) {
      s21_strncat(buf, "0x", 2);
      *iBuf += 2;
      itoa(buf + *iBuf, (unsigned long)ptr, 16, 0);
      *iBuf += s21_strlen(buf + *iBuf);
    }
  }
  output_plus_minus(buf, &iBuf, startIBuf, params, 0);
}

void outputStr(char *buf, s21_size_t *iBuf, char *s, PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  if (s == NULL) {
    s21_strncat(buf + *iBuf, "(null)", 6);
    *iBuf += 6;
  } else {
    s21_size_t n = s21_strlen(s);
    if (params.precSetted) {
      n = params.prec;
    }
    s21_strncat(buf + *iBuf, s, n);
    *iBuf += s21_strlen(buf + *iBuf);
  }
  output_plus_minus(buf, &iBuf, startIBuf, params, 0);
}

void output2strUnsInt(char *buf, s21_size_t *iBuf, unsigned long long number,
                      PARAMS params) {
  s21_size_t startIBuf = *iBuf;

  if (params.spec_o == 1) {
    itoa_unsigned(buf + *iBuf, number, 8, 0);
  }
  if (params.spec_u == 1) {
    itoa_unsigned(buf + *iBuf, number, 10, 0);
  }
  if (params.spec_x == 1) {
    itoa(buf + *iBuf, number, 16, 0);
  }
  if (params.spec_X == 1) {
    itoa(buf + *iBuf, number, 16, 1);
  }
  *iBuf += s21_strlen(buf + *iBuf);
  s21_size_t n = *iBuf - startIBuf;
  if (params.precSetted && params.prec == 0 && number == 0) {
    *iBuf = startIBuf;
  } else {
    if (params.precSetted) {
      if (n < (s21_size_t)params.prec) {
        *(buf + startIBuf + params.prec) = 0;
        for (s21_size_t i = (s21_size_t)params.prec; i > 0; i--) {
          if (i >= params.prec - n) {
            *(buf + startIBuf + i) = *(buf + startIBuf + i - params.prec + n);
          } else {
            *(buf + startIBuf + i) = '0';
          }
        }
        *buf = '0';
        (*iBuf) += params.prec - n;
      }
    } else {
      s21_size_t neg = 0;
      output_plus_minus(buf, &iBuf, startIBuf, params, neg);
    }
  }
}

void output2strInt(char *buf, s21_size_t *iBuf, long long number,
                   PARAMS params) {
  s21_size_t startIBuf = *iBuf;
  s21_size_t deltaN = 0;

  if (number >= 0 && params.flag_plus) {  // check Zero
    *buf = '+';
    (*iBuf)++;
    deltaN++;
  }
  if (number >= 0 && params.flag_space) {
    *buf = ' ';
    (*iBuf)++;
    deltaN++;
  }
  itoa(buf + *iBuf, number, 10, 0);
  s21_size_t neg = 0;
  s21_size_t mem = s21_strlen(buf + *iBuf);
  if (number < 0 && params.flag_zero && mem < (s21_size_t)params.width) {
    neg = 1;
    s21_memcpy(buf + *iBuf, buf + *iBuf + 1, mem);
  }
  *iBuf += s21_strlen(buf + *iBuf);
  s21_size_t n = *iBuf - startIBuf + deltaN;
  if (params.precSetted && params.prec == 0 && number == 0) {
    *iBuf = startIBuf;
  } else {
    if (params.precSetted) {
      if (n < (s21_size_t)params.prec) {
        *(buf + startIBuf + params.prec) = 0;
        for (s21_size_t i = (s21_size_t)params.prec; i > 0; i--) {
          if (i >= params.prec - n) {
            *(buf + startIBuf + i) = *(buf + startIBuf + i - params.prec + n);
          } else {
            *(buf + startIBuf + i) = '0';
          }
        }
        *(buf + startIBuf) = '0';
        (*iBuf) += params.prec - n;
      }
    } else {
      output_plus_minus(buf, &iBuf, startIBuf, params, neg);
    }
  }
}

char *itoa(char *str, long long num, int radix, int caps) {
  char digits[] = "0123456789abcdef";
  s21_size_t i = 0;
  int isNegative = 0;

  if (caps) {
    s21_strncpy(digits + 10, "ABCDEF", 6);
  }

  if (num < 0 && radix == 10) {
    isNegative = 1;
    num = -num;
  }

  if (num == 0) {
    str[i++] = '0';
    str[i] = 0;
    return str;
  }

  do {
    int rem = num % radix;
    str[i++] = digits[rem];
    num = num / radix;
  } while (num != 0);

  if (isNegative) str[i++] = '-';

  str[i] = 0;

  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start++] = str[end];
    str[end--] = temp;
  }
  return str;
}

char *itoa_unsigned(char *str, unsigned long long num, int radix, int caps) {
  return itoa(str, num, radix, caps);
}

char *ftoa(char *str, long double num, int accuracy) {
  int j = 0;
  long double db_num = num;
  int isNegative = 0;
  int i = 0;
  if (num < 0) {
    db_num = -db_num;
    isNegative = 1;
  }
  str[i] = 0;
  if (isNegative) {
    str[i] = '-';
    str[++i] = 0;
  }
  if (accuracy == 0) {
    db_num = s21_ceil(db_num);
  }
  do {
    db_num = db_num / 10.0;
    j++;
  } while (db_num >= 1.);
  while (j > 0) {
    db_num = db_num * 10.0;
    int ceil = (int)(db_num + 5e-14);
    if (ceil == 0) {
      str[i] = '0';
      str[++i] = '\0';
    } else {
      char s[2] = {0};
      itoa(s, ceil, 10, 0);
      s21_strncat(str, s, 2);
      i++;
      str[i] = '\0';
    }
    db_num = db_num - (double)ceil;
    j--;
  }
  ftoa_after_point(str, accuracy, db_num);
  return str;
}

char *ftoa_after_point(char *str, int accuracy, long double db_num) {
  long long integel = (long long)db_num;
  int i = s21_strlen(str);
  if (accuracy != 0) {
    str[i++] = '.';
    str[i++] = '\0';
  }
  long double db_integel = 0;
  if (accuracy > 14) {
    db_integel = db_num - (long double)integel;
  } else {
    db_integel = db_num - (long double)integel + 2e-15;
  }
  while (accuracy-- > 0) {
    db_integel = db_integel * 10;
    int int_after_point = 0;
    if (accuracy == 0) {
      db_integel = s21_ceil(db_integel);
      int_after_point = (int)db_integel;
    } else {
      int_after_point = (int)db_integel;
    }
    if (int_after_point == 0) {
      i = s21_strlen(str);
      str[i++] = '0';
      str[i++] = '\0';
    } else {
      char s[3] = {0};
      itoa(s, int_after_point, 10, 0);
      s21_strncat(str, s, 2);
      str[i++] = '\0';
    }
    db_integel = db_integel - (long double)int_after_point;
  }
  return str;
}

// делает число в формате (пример 1.1.......) строкой и объединить с мантиссой
char *etoa(char *str, long double num, int accuracy, int caps) {
  char s[100];
  long double db_num = num;
  int j = 0;
  int i = 0;
  db_num = normolaze(s, db_num, caps);
  str = ftoa(str, db_num, accuracy);
  j = s21_strlen(s);
  i = s21_strlen(str);
  s21_strncat(str, s, j);
  str[j + i] = '\0';
  return str;
}

// делает дробь в форме (пример 1.1.......) и строку с мантиссой
long double normolaze(char *str, long double num, int caps) {
  long int couter = 0;
  char *db_str = str;
  if (caps)
    *db_str = 'E';
  else
    *db_str = 'e';
  if (s21_fabs(num) < 0.9999999999999999 && s21_fabs(num) > 0.1e-300) {
    *++db_str = '-';
    while (s21_fabs(num) < 1) {
      num = num * 10.0;
      couter++;
    }
  } else {
    *++db_str = '+';
    while (s21_fabs(num) > 9.99999) {
      num = num / 10.0;
      couter++;
    }
  }
  if (couter < 10) {
    *++db_str = '0';
  }
  if (num == 0) {
    *++db_str = '0';
    *++db_str = 0;
  } else {
    *++db_str = 0;
    db_str = itoa(db_str, couter, 10, 0);
    int j = s21_strlen(str);
    str[j] = '\0';
  }

  return num;
}

char *gtoa(char *str, long double num, int caps, int prec, int sharp) {
  int flag = 0;
  char check_str[310];
  ftoa(check_str, num, prec);
  while (check_str[flag] != '.') {
    flag++;
  }
  flag--;
  if (s21_fabs(num) > 9.999999e+05 || flag > prec) {
    if (flag == prec) {
      etoa(str, num, 0, caps);
    } else {
      etoa(str, num, prec - 1, caps);
    }
  } else if (s21_fabs(num) < 1) {
    ftoa(str, num, prec);
  } else if (s21_fabs(num) < 10) {
    ftoa(str, num, (prec - 1));
  } else if (s21_fabs(num) < 100) {
    ftoa(str, num, (prec - 2));
  } else if (s21_fabs(num) < 1000) {
    ftoa(str, num, (prec - 3));
  } else if (s21_fabs(num) < 10000) {
    ftoa(str, num, (prec - 4));
  } else if (s21_fabs(num) < 100000) {
    ftoa(str, num, (prec - 5));
  } else if (s21_fabs(num) < 1000000) {
    ftoa(str, num, (prec - 6));
  }
  if (!sharp) {
    s21_size_t mem = s21_strlen(str) - 1;
    flag++;
    if (flag == prec) {
      mem++;
    }
    while (str[mem] == '0') {
      str[mem] = 0;
      mem--;
    }
    if (str[mem] == '.') {
      str[mem] = 0;
    }
  }

  return str;
}

long double s21_fabs(long double x) { return x < 0 ? -x : x; }

long double s21_ceil(long double x) {
  long double res;
  long double remainder = s21_fmod(x, 1.0);
  if (s21_fabs(remainder) > 0.49999999999999999999) {
    if (x < 0) {
      res = x - remainder - 1;
    } else {
      res = x - remainder + 1;
    }
  } else {
    res = x - remainder;
  }
  return res;
}

long double s21_fmod(long double x, long double y) {
  return x - y * ((long long)(x / y));
}
