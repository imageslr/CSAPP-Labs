/* 
 * CS:APP Data Lab 
 * 
 * Images.
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  1. 只允许使用 0~255 的整数
  2. 只允许使用一元操作符 ! ~ 
  3. 只允许使用二元操作符 & ^ | + << >> 
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

  1. 不允许使用任何控制流
  2. 不允许使用宏
  3. 不能声明、调用任何函数
  5. 不能使用其他操作符
  6. 不能使用类型转换
  7. 不能使用 int 以外的类型

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

允许使用循环、条件控制；int、无符号数。

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting. 不能使用类型转换
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions. 不能使用整型和无符号数以外的数据类型
  6. Use any floating point data types, operations, or constants. 不能使用浮点数


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
  return ~(~x | ~y);
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
  int res = 0xff;
  x = x >> (n << 3);
  return res & x;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n)
{
  int pos = 32 + (~n + 1);     // 1 向左移 32-n 位，再减 1，可以得到后 32-n 位全为 1 的二进制数
  int y = 1 << (pos + ~1 + 1); // y == 2^{pos-1}
  x = x >> n;
  return x & (y + ~1 + 1 + y);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{

  int _m1 = 0x55 | 0x55 << 8;
  int _m2 = 0x33 | 0x33 << 8;
  int _m3 = 0x0f | 0x0f << 8;
  int m1 = _m1 | (_m1 << 16);   // 01010101....0101
  int m2 = _m2 | (_m2 << 16);   // 00110011....0011
  int m3 = _m3 | (_m3 << 16);   // 00001111....00001111
  int m4 = 0xff | (0xff << 16); // 0000000011111111....0000000011111111
  int m5 = 0xff | (0xff << 8);  // 00000000000000001111111111111111
  int ans = (x & m1) + ((x >> 1) & m1);
  ans = (ans & m2) + ((ans >> 2) & m2);
  ans = (ans & m3) + ((ans >> 4) & m3);
  ans = (ans & m4) + ((ans >> 8) & m4);
  ans = (ans & m5) + ((ans >> 16) & m5);
  return ans;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x)
{
  return ~((x | (~x + 1)) >> 31) & 1;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
  // ~1 +1 == ~0
  // return !(((x >> (n + ~0)) + 1) >> 1);
  return !(x >> (n + ~0)) | !((x >> (n + ~0)) + 1);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n)
{
  int bias = (1 << n) + (~0);
  int mask = x >> 31;
  bias = bias & mask;
  return (x + bias) >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x)
{
  return !(x >> 31) & !!x;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  // y - x >= 0 直接做减法可能负溢出
  int diffSign = !!((x >> 31) ^ (y >> 31));
  int diff = y + ~x + 1;
  // 符号不同，x 必然小于 0；符号相同，差非负，直接做减法不会溢出
  return (diffSign & x >> 31) | (!diffSign & !(diff >> 31));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x)
{
  // 要找左侧第一个 1 的位置
  // 每次将区间大小缩小一半
  // ans 为区间右边界。最低位为 0，ans 从 0 增加
  int ans = 0;
  ans = (!!(x >> 16)) << 4;                // ans = ans + 16?
  ans = ans + ((!!(x >> (8 + ans))) << 3); // ans = ans + 8?
  ans = ans + ((!!(x >> (4 + ans))) << 2); // ans = ans + 4?
  ans = ans + ((!!(x >> (2 + ans))) << 1); // ans = ans + 2?
  ans = ans + (!!(x >> (1 + ans)));        // ans = ans + 2?
  return ans;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf)
{
  // 符号位取反
  unsigned neg = uf ^ 0x80000000;

  // 判断指数位 1~9 位是否全为 1，并且尾数位不为 0
  unsigned nan = uf & 0x7fffffff;

  if (nan > 0x7f800000) // 0x7f800000: 1~9位为 1
  {
    neg = uf;
  }

  return neg;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x)
{
  int pos = 31;                               // 左侧第一个 1 的位置，从左到右为 31~0
  int signx = x & 0x80000000;                 // 符号位
  int exp;                                    // 指数位
  int t, tt, shifted_bits, shifted_len, mask; // 临时变量

  // 特殊情况，直接返回
  if (x == 0)
  {
    return 0;
  }

  // 如果 x 为负数，将其取反
  // 注意这里一定要取反，并且 x 取反后位级表示会发生改变，
  // 第一个 1 的位置会改变，不仅仅只有符号位取反
  if (signx)
  {
    x = -x;
  }

  // 找左侧第一个 1 的位置
  // 能用 while，就不需要用 11 题的分治的方法了
  while (!((1 << pos) & x))
  {
    pos -= 1;
  }

  // 尾数部分：把左侧第一个 1 移动到倒数第 24 位，需要根据 pos 对 x 左移或右移
  if (pos < 23)
  {
    // 向左移位，不需要考虑舍入的问题
    x <<= (23 - pos);
  }
  else
  {
    /**
     * 向右移位，需要舍入
     * 共分为 3 种情况：进一、舍去、向偶数舍入
     * （这部分内容在书的第 86 页）
     * 
     * 假设最后几位为 XYYY...，要舍入到 X 这一位：
     * 
     * 1. 如果 YYY... == 100...，即等于中间值，需要向偶数舍入
     *   向偶数舍入分为两种情况：
     *   1.1 如果 X 是 1，说明舍入后是奇数，因此要进一
     *   1.2 如果 X 是 0，说明舍入后是偶数，直接舍去 YYY...
     * 
     * 其他情况就是向上或向下舍入：
     * 2. 如果 YYY... > 100...，即大于中间值，要进一
     * 3. 如果 YYY... < 100...，即小于中间值，要舍去
     * 
     * 进一的时候可能溢出，因此要按照这个顺序：
     * ① 先舍入
     * ② 再判断是否溢出，如果溢出，pos + 1
     * ③ 最后再移位 / 计算指数部分
     */

    // 比较 YYY... 与 100...，YYY...是要被舍掉的位
    shifted_len = pos - 23;
    tt = 1 << shifted_len; // 00..1000..0
    t = tt >> 1;           // 00...100..0
    mask = tt - 1;         // 00...111..1
    shifted_bits = x & mask;

    // 向偶数舍入，且需要进 1
    if (shifted_bits == t)
    {
      if (x & tt)
        x += t;
    }
    // 向上舍入
    if (shifted_bits > t)
    {
      x += t;
    }

    // 判断是否因为进一而溢出
    if (x & (1 << (pos + 1)))
    {
      pos++;
    }

    // 移位
    x = x >> shifted_len;
  }
  x &= 0x7fffff; // x 只保留尾数部分

  // 指数部分：e = E + 2^7-1
  exp = (pos + 127) << 23;

  return x | signx | exp;
}

/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf)
{
  int _exp = uf & 0x7f800000;
  int exp = _exp >> 23;
  int frac = uf & 0x7fffff;
  int sign = (uf >> 31) & 1;

  // 0
  if (uf == 0 || uf == 0x80000000)
  {
    return uf;
  }

  // 无穷大、NaN
  if (exp == 0xff)
  {
    return uf;
  }

  // 规格化的
  if (exp > 0)
  {
    exp += 1;
  }
  else
  {
    // 非规格化的，其实这种情况就相当于指数位和尾数位整体左移 1 位
    return ((uf & (1 << 31)) | (uf << 1));
  }

  return (sign << 31) | (exp << 23) | frac;
}
