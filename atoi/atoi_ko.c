// Obtive testando no criterion potências de 2 até chegar em (2^32 / 2 - 1)
#define FT_INT_MAX 2147483647
#define FT_INT_MIN -2147483648

int ft_isspace(char chr)
{
  if (chr == ' ')
    return (1);
  if (chr >= '\t' && chr <= '\r')
    return (1);
  return (0);
}

int ft_isdigit(char chr)
{
  if (chr >= '0' && chr <= '9')
    return (1);
  return (0);
}

int ft_isdigit_hex(char chr)
{
  if (ft_isdigit(chr) == 1)
    return (1);
  if (chr >= 'a' && chr <= 'f')
    return (1);
  if (chr >= 'A' && chr <= 'F')
    return (1);
  return (0);  
}

int ft_isnonprintable(char chr)
{
  if (chr == 127)
    return (1);
  if (chr < ' ')
    return (1);
  return (0);
}

int ft_isX(char chr)
{
  if (chr == 'x')
    return (1);
  if (chr == 'X')
    return (1);
  return (0);
}

int ft_issignal(char chr)
{
  if (chr == '-')
    return (-1);
  if (chr == '+')
    return (1);
  return (0);
}

int ft_preprocess(const char *str, int *index, int *factor)
{
  int base;
  char chr;
  char next_chr;
  int signal;
  
  base = 10;
  signal = 0;
  if (str == (void *) 0)
    return (0);
  if (*str == '\0')
    return (0);
  (*index)--;
  while (str[++(*index)] != '\0')
  {
    chr = str[*index];
    next_chr = str[*index + 1];
    
    if (ft_isspace(chr))
      continue;
    if (ft_isnonprintable(chr))
      return (0);
    signal = ft_issignal(chr);
    if (signal == -1)
    {
      if (ft_isdigit(next_chr))
        *factor = -1;
    }
    else if (signal == 1)
      continue;
    else if (ft_isdigit(chr))
    {
      if (ft_isX(next_chr))
        base = 16;
      else if (next_chr == '0')
        base = 8;
      break;
    }
    else
      continue;
  }
  return (base);
}

int ft_iterate(char *base, char chr, int len)
{
  int value;
  
  value = 0;
  while (value < len)
  {
    if (base[value] == chr)
      return (value);
    value++;
  }
  return (0);
}

int ft_search_correct_value(char chr, int base)
{
  char base10[] = "0123456789";
  char base16_D[] = "0123456789abcdef";
  char base16_U[] = "0123456789ABCDEF";
  char base8[] = "01234567";
  
  if (base == 10)
    return ft_iterate(base10, chr, sizeof(base10) / sizeof(char));
  else if (base == 16)
  {
    if (ft_isdigit(chr) || (chr >= 'a' && chr <= 'z'))
      return ft_iterate(base16_D, chr, sizeof(base16_D) / sizeof(char));
    else if (ft_isdigit(chr) || (chr >= 'A' && chr <= 'Z'))
      return ft_iterate(base16_U, chr, sizeof(base16_U) / sizeof(char));
  }
  else
    return ft_iterate(base8, chr, sizeof(base8) / sizeof(char));
  return (0);
}

int ft_atoi(const char *str)
{
  int base;
  int res;
  int index;
  int factor;
  
  res = 0;
  index = 0;
  factor = 1;

  base = ft_preprocess(str, &index, &factor);
  if (base == 0)
    return (0);
  while (str[index] != '\0' && ft_isspace(str[index]) == 0)
  {
    res = res * base + ft_search_correct_value(str[index], base);
    index++;
  }
  if (factor >= 0 && res < 0)
    return (FT_INT_MAX);
  else if (factor < 0 && res < 0)
    return (FT_INT_MIN);
  return (res * factor);
}