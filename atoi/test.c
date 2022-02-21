#define FT_INT_MAX 2147483647
#define FT_INT_MIN -2147483648

#include <criterion/criterion.h>
#include <stdlib.h>

extern int ft_atoi(const char *str);

Test(ft_atoi, testDumbCases) {
  cr_assert_eq(ft_atoi(""), 0);
  cr_assert_eq(ft_atoi("atoi with Bug(?): searching for the hidden pickle (the movie)"), 0);
}

Test(ft_atoi, testBasePickleOctal)
{
  int res = ft_atoi("\tPickle 0010 octal - x -33\n\n\r\r\t\t");
  int expected = 8;
  cr_assert_eq(res, expected, "expected [%d] but got [%d]", expected, res);
}

Test(ft_atoi, testBasePickleHex)
{
  int res2 = ft_atoi("\tPickle 0x04 hex - x -33\n\n\r\r\t\t");
  int expected2 = 4;
  cr_assert_eq(res2, expected2, "expected [%d] but got [%d]", expected2, res2);
  cr_assert_eq(ft_atoi("\xa6"), 0);
  cr_assert_eq(ft_atoi("0xa6"), 166);
}

Test(ft_atoi, testExtreme) {
  cr_assert_eq(ft_atoi("  \t\r  1 -42"), 1);
  cr_assert_eq(ft_atoi("  \t\r   -42"), -42);
  cr_assert_eq(ft_atoi("  \t\r \n ~ -42 ***][][```]"), -42);
  cr_assert_eq(ft_atoi("==+++++++42          "), 42);
  cr_assert_eq(ft_atoi(" ^ \r\t\t\t#$    121 \t\t\t\t\t\t     "), 121);
  cr_assert_eq(ft_atoi(" - - -     -42      "), -42);
}

Test(ft_atoi, testBasic) {
  cr_assert_eq(ft_atoi("     -42"), -42);
  cr_assert_eq(ft_atoi("     324142"), 324142);
  cr_assert_eq(ft_atoi(" \t2314124"), 2314124);
  cr_assert_eq(ft_atoi("  \n   42"), 42);
  cr_assert_eq(ft_atoi("  ++++++42"), 42);
  cr_assert_eq(ft_atoi("     -42"), -42);
}

Test(ft_atoi, testUpperLimit) {
  int res = ft_atoi("  Pickle text   2147483647");
  cr_assert_eq(res, FT_INT_MAX, "got [%d]", res);
}

Test(ft_atoi, testDownerLimit) {
  int res = ft_atoi(" Pickle Pickle  -2147483648    Pickle Pickle");
  cr_assert_eq(res, FT_INT_MIN, "got [%d]", res);
}

Test(ft_atoi, testOverflow) {
  int res = ft_atoi("     Pickle text 2147483650 text in Pickle");
  cr_assert_eq(res, FT_INT_MAX, "got [%d]", res);
}

Test(ft_atoi, testUnderflow) {
  int res = ft_atoi("     -2147483650 Pickle Pickle");
  cr_assert_eq(res, FT_INT_MIN, "Got [%d]", res);
}

Test(ft_atoi, testSpicyCases) {
  cr_assert_eq(ft_atoi((void *) 0), 0);
  // cr_assert_eq(malloc(sizeof(char *)), 0); // Very Spicy (Beware!)
}
