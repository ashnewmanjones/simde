/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Copyright:
 *   2020      Evan Nemerson <evan@nemerson.com>
 */

#define SIMDE_TEST_X86_AVX512_INSN dpbusd

#include <test/x86/avx512/test-avx512.h>
#include <simde/x86/avx512/dpbusd.h>

static int
test_simde_mm512_dpbusd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
  const struct {
    int32_t src[16];
    uint8_t a[64];
    int8_t  b[64];
    int32_t r[16];
  } test_vec[] = {
    { {  INT32_C(   617351123),  INT32_C(   193871301), -INT32_C(  2105353151),  INT32_C(  1704372451), -INT32_C(  1718167257), -INT32_C(  1315935453),  INT32_C(  1068571841), -INT32_C(   546205684),
         INT32_C(  1560493463), -INT32_C(  1150774918),  INT32_C(  1363012205), -INT32_C(  1179200622), -INT32_C(   799847252),  INT32_C(  2038555575),  INT32_C(   196621055),  INT32_C(  1525295554) },
      { UINT8_C(103), UINT8_C(237), UINT8_C(183), UINT8_C(225), UINT8_C(127), UINT8_C( 31), UINT8_C(157), UINT8_C(236),
        UINT8_C(  9), UINT8_C(218), UINT8_C( 61), UINT8_C(155), UINT8_C(174), UINT8_C(244), UINT8_C( 84), UINT8_C( 90),
        UINT8_C( 64), UINT8_C(167), UINT8_C( 42), UINT8_C(248), UINT8_C(138), UINT8_C(172), UINT8_C(113), UINT8_C(137),
        UINT8_C(222), UINT8_C( 41), UINT8_C(148), UINT8_C(161), UINT8_C( 82), UINT8_C(126), UINT8_C(251), UINT8_C(185),
        UINT8_C(108), UINT8_C(178), UINT8_C(155), UINT8_C(235), UINT8_C(209), UINT8_C( 56), UINT8_C(215), UINT8_C(218),
        UINT8_C( 18), UINT8_C( 21), UINT8_C(117), UINT8_C(192), UINT8_C(  9), UINT8_C(201), UINT8_C( 27), UINT8_C( 73),
        UINT8_C(113), UINT8_C( 69), UINT8_C( 65), UINT8_C(251), UINT8_C(241), UINT8_C(178), UINT8_C(133), UINT8_C(208),
        UINT8_C(219), UINT8_C( 25), UINT8_C(113), UINT8_C( 46), UINT8_C(152), UINT8_C(108), UINT8_C(231), UINT8_C(  4) },
      {  INT8_C(  30), -INT8_C( 126), -INT8_C(  17), -INT8_C(  17), -INT8_C(  70), -INT8_C(  58), -INT8_C(  55), -INT8_C(  51),
        -INT8_C(  37),  INT8_C(  62), -INT8_C( 115), -INT8_C(  28),  INT8_C(   7), -INT8_C(  88),  INT8_C(  46),  INT8_C( 120),
        -INT8_C(  18),  INT8_C( 111),  INT8_C( 116), -INT8_C(  33),  INT8_C(  34), -INT8_C(   7), -INT8_C(  81), -INT8_C(   3),
         INT8_C(  18),  INT8_C(  32),  INT8_C(  43), -INT8_C(  86), -INT8_C( 116),  INT8_C(  19), -INT8_C(  82), -INT8_C(  86),
        -INT8_C( 107), -INT8_C(  99), -INT8_C( 103),  INT8_C(  80),  INT8_C( 100),  INT8_C(  98),  INT8_C(  29),  INT8_C(  63),
        -INT8_C(  96), -INT8_C(  86),  INT8_C(  36), -INT8_C(  88),  INT8_C(  83),  INT8_C(  82),  INT8_C(  32),  INT8_C(  65),
        -INT8_C(  63), -INT8_C( 108),  INT8_C(  32), -INT8_C(  29), -INT8_C( 115), -INT8_C(  48), -INT8_C(  31), -INT8_C(  96),
        -INT8_C(  16),  INT8_C(  12),  INT8_C(  74),  INT8_C( 125),  INT8_C(  31), -INT8_C(   7),  INT8_C(  39), -INT8_C(  75) },
      {  INT32_C(   617317415),  INT32_C(   193839942), -INT32_C(  2105351323),  INT32_C(  1704366861), -INT32_C(  1718153184), -INT32_C(  1315941529),  INT32_C(  1068569667), -INT32_C(   546249294),
         INT32_C(  1560467120), -INT32_C(  1150728561),  INT32_C(  1362995987), -INT32_C(  1179177784), -INT32_C(   799867022),  INT32_C(  2038495225),  INT32_C(   196631963),  INT32_C(  1525308219) } },
    { { -INT32_C(   100286058), -INT32_C(  1002823133),  INT32_C(   527195852),  INT32_C(  1902152880), -INT32_C(  1370128095),  INT32_C(  1095644753),  INT32_C(  1656658242),  INT32_C(   672654994),
        -INT32_C(   903668569),  INT32_C(   177102142),  INT32_C(  1797978811), -INT32_C(  1461941625),  INT32_C(  1549152523), -INT32_C(  1432443545), -INT32_C(   804496322), -INT32_C(   369614014) },
      { UINT8_C( 63), UINT8_C( 27), UINT8_C(180), UINT8_C(125), UINT8_C(120), UINT8_C( 66), UINT8_C(135), UINT8_C( 51),
        UINT8_C( 61), UINT8_C(177), UINT8_C(158), UINT8_C(196), UINT8_C( 60), UINT8_C(123), UINT8_C(108), UINT8_C( 71),
        UINT8_C(172), UINT8_C(194), UINT8_C(164), UINT8_C( 20), UINT8_C(103), UINT8_C( 66), UINT8_C(190), UINT8_C(165),
        UINT8_C(158), UINT8_C(202), UINT8_C(117), UINT8_C(225), UINT8_C(237), UINT8_C(110), UINT8_C(202), UINT8_C( 44),
        UINT8_C(137), UINT8_C(126), UINT8_C(169), UINT8_C(  2), UINT8_C(193), UINT8_C( 48), UINT8_C( 53), UINT8_C(254),
        UINT8_C(226), UINT8_C(212), UINT8_C(194), UINT8_C( 30), UINT8_C( 79), UINT8_C( 46), UINT8_C(101), UINT8_C(251),
        UINT8_C(240), UINT8_C(  9), UINT8_C( 15), UINT8_C( 88), UINT8_C( 75), UINT8_C(205), UINT8_C(253), UINT8_C(234),
        UINT8_C(151), UINT8_C(115), UINT8_C(203), UINT8_C(132), UINT8_C(225), UINT8_C(149), UINT8_C(176), UINT8_C(106) },
      {  INT8_C(  20),  INT8_C(  89),  INT8_C( 108), -INT8_C(  43), -INT8_C( 118), -INT8_C(  94), -INT8_C(  45),  INT8_C( 108),
         INT8_C( 118), -INT8_C( 107), -INT8_C( 118), -INT8_C(  59), -INT8_C(  61), -INT8_C(  17), -INT8_C(  64), -INT8_C(  77),
        -INT8_C(   7), -INT8_C(  48),  INT8_C(  11),  INT8_C(  68), -INT8_C(  99),  INT8_C(   9),  INT8_C(  46),  INT8_C(  53),
         INT8_C( 124), -INT8_C(   7), -INT8_C(  71),  INT8_C(  93), -INT8_C( 113),  INT8_C( 106), -INT8_C(  57), -INT8_C(  93),
        -INT8_C(  61),  INT8_C(  52),  INT8_C( 120),  INT8_C(  77), -INT8_C(  42),  INT8_C(  75), -INT8_C(  71),  INT8_C(  76),
        -INT8_C(  32),  INT8_C(  67),  INT8_C(  17), -INT8_C(  93),  INT8_C(  51), -INT8_C(  47),  INT8_C(  86),  INT8_C(  44),
        -INT8_C(  95),  INT8_C(  98),  INT8_C( 112),  INT8_C(  63),  INT8_C( 107), -INT8_C(  97),  INT8_C( 116), -INT8_C(  25),
        -INT8_C( 104),  INT8_C(  45),  INT8_C(  68),  INT8_C(  39), -INT8_C( 105),  INT8_C(  11), -INT8_C(  54),  INT8_C(  91) },
      { -INT32_C(   100268330), -INT32_C(  1002844064),  INT32_C(   527153903),  INT32_C(  1902134750), -INT32_C(  1370135447),  INT32_C(  1095652635),  INT32_C(  1656689038),  INT32_C(   672624267),
        -INT32_C(   903649940),  INT32_C(   177113177),  INT32_C(  1797986291), -INT32_C(  1461920028),  INT32_C(  1549137829), -INT32_C(  1432431907), -INT32_C(   804487899), -INT32_C(   369635858) } },
    { {  INT32_C(   363348543),  INT32_C(  1835098765), -INT32_C(   670010715), -INT32_C(   452696252),  INT32_C(   874804681), -INT32_C(  1407477740),  INT32_C(  1574199238), -INT32_C(  1430741398),
         INT32_C(  1858036193),  INT32_C(  1759257027), -INT32_C(   683545453),  INT32_C(   482166099), -INT32_C(   833560134),  INT32_C(  1081830266),  INT32_C(   899502026), -INT32_C(   824224019) },
      { UINT8_C(183), UINT8_C(158), UINT8_C( 61), UINT8_C(122), UINT8_C(191), UINT8_C( 25), UINT8_C(226), UINT8_C( 83),
        UINT8_C(  5), UINT8_C( 35), UINT8_C( 42), UINT8_C( 89), UINT8_C(105), UINT8_C(231), UINT8_C(117), UINT8_C( 35),
        UINT8_C(201), UINT8_C(198), UINT8_C(242), UINT8_C( 67), UINT8_C( 49), UINT8_C(109), UINT8_C(131), UINT8_C(252),
        UINT8_C(188), UINT8_C( 32), UINT8_C( 49), UINT8_C(169), UINT8_C(118), UINT8_C( 16), UINT8_C(120), UINT8_C( 45),
        UINT8_C(174), UINT8_C(181), UINT8_C(167), UINT8_C(110), UINT8_C(206), UINT8_C(138), UINT8_C(193), UINT8_C(211),
        UINT8_C(173), UINT8_C(235), UINT8_C( 44), UINT8_C( 22), UINT8_C(211), UINT8_C(162), UINT8_C( 58), UINT8_C(156),
        UINT8_C(104), UINT8_C( 44), UINT8_C(223), UINT8_C(153), UINT8_C(153), UINT8_C( 98), UINT8_C(149), UINT8_C( 85),
        UINT8_C(130), UINT8_C(198), UINT8_C(254), UINT8_C(249), UINT8_C(214), UINT8_C(118), UINT8_C( 38), UINT8_C(133) },
      {  INT8_C(  43), -INT8_C(  50), -INT8_C(  13), -INT8_C(   7),  INT8_C(  88), -INT8_C(  76), -INT8_C(  51),  INT8_C(   5),
        -INT8_C(  97), -INT8_C(   7),  INT8_C(  28),  INT8_C( 114), -INT8_C( 101),  INT8_C(  86),  INT8_C(  14),  INT8_C(   3),
        -INT8_C( 126), -INT8_C(  19), -INT8_C(  99),  INT8_C(  27),  INT8_C(  79),  INT8_C(  50),  INT8_C( 112), -INT8_C(  46),
        -INT8_C(   7),  INT8_C( 110), -INT8_C(  53), -INT8_C(  49), -INT8_C(  27), -INT8_C(  15),  INT8_C(  84),  INT8_C(  16),
        -INT8_C(  65),  INT8_C(  71),  INT8_C(  10),  INT8_C(  23), -INT8_C(   5), -INT8_C(  41),  INT8_C(  29), -INT8_C( 101),
        -INT8_C(  48),  INT8_C(  57),  INT8_C(  13),  INT8_C( 108), -INT8_C( 113),  INT8_C(  28),  INT8_C( 111),  INT8_C(  17),
         INT8_C(   9),  INT8_C(  12),  INT8_C(  44),  INT8_C(  89),  INT8_C(  63), -INT8_C( 100),  INT8_C(  43),  INT8_C(  56),
         INT8_C(  10), -INT8_C(  10),  INT8_C(   7), -INT8_C(  17), -INT8_C(  25),  INT8_C(  92),  INT8_C(   0), -INT8_C(  89) },
      {  INT32_C(   363346865),  INT32_C(  1835102562), -INT32_C(   670000123), -INT32_C(   452685248),  INT32_C(   874753444), -INT32_C(  1407465339),  INT32_C(  1574190564), -INT32_C(  1430734024),
         INT32_C(  1858041934),  INT32_C(  1759234625), -INT32_C(   683537414),  INT32_C(   482155882), -INT32_C(   833535241),  INT32_C(  1081841272),  INT32_C(   899498891), -INT32_C(   824230350) } },
    { { -INT32_C(  1614935389), -INT32_C(  1321542687), -INT32_C(  1558362348),  INT32_C(  1840549219), -INT32_C(   658055015), -INT32_C(  2028932740), -INT32_C(   831121177),  INT32_C(   393574004),
         INT32_C(  1639330944),  INT32_C(   605286415), -INT32_C(  1681444808),  INT32_C(  1460174013), -INT32_C(   651178404), -INT32_C(  1503641409), -INT32_C(   864692648), -INT32_C(   840701363) },
      { UINT8_C( 30), UINT8_C(154), UINT8_C( 47), UINT8_C( 46), UINT8_C(138), UINT8_C( 66), UINT8_C( 82), UINT8_C(194),
        UINT8_C(114), UINT8_C( 25), UINT8_C( 94), UINT8_C( 48), UINT8_C(149), UINT8_C(102), UINT8_C(135), UINT8_C(242),
        UINT8_C( 53), UINT8_C(182), UINT8_C(203), UINT8_C(244), UINT8_C(246), UINT8_C( 43), UINT8_C(155), UINT8_C( 78),
        UINT8_C(  1), UINT8_C( 16), UINT8_C( 26), UINT8_C( 78), UINT8_C(250), UINT8_C(254), UINT8_C( 28), UINT8_C( 25),
        UINT8_C(152), UINT8_C( 75), UINT8_C( 71), UINT8_C( 34), UINT8_C(141), UINT8_C(153), UINT8_C(229),    UINT8_MAX,
        UINT8_C(178), UINT8_C( 67), UINT8_C( 47), UINT8_C( 72), UINT8_C(169), UINT8_C(182), UINT8_C( 58), UINT8_C(222),
        UINT8_C(109), UINT8_C(  5), UINT8_C(211), UINT8_C( 99), UINT8_C( 48), UINT8_C(110), UINT8_C(178), UINT8_C( 49),
        UINT8_C(126), UINT8_C(204), UINT8_C(128), UINT8_C(120), UINT8_C(202), UINT8_C(156), UINT8_C(145), UINT8_C( 98) },
      { -INT8_C(  25), -INT8_C(  40), -INT8_C( 123),  INT8_C( 116),  INT8_C( 113),  INT8_C( 106),  INT8_C( 115),  INT8_C(  36),
        -INT8_C(  83), -INT8_C(  93),  INT8_C( 108),  INT8_C(  86),  INT8_C(  89), -INT8_C(  90),  INT8_C(  53), -INT8_C(  58),
        -INT8_C(  85),  INT8_C(   8),  INT8_C(  42), -INT8_C(  37),  INT8_C( 118), -INT8_C(  36),  INT8_C(  12), -INT8_C(  12),
        -INT8_C(  88), -INT8_C( 116),  INT8_C( 108),  INT8_C( 115),  INT8_C(  40), -INT8_C(   2), -INT8_C(  43),  INT8_C(  15),
        -INT8_C(  42),  INT8_C(  90), -INT8_C( 125),  INT8_C(  72), -INT8_C(  60), -INT8_C(   9),  INT8_C( 108),  INT8_C( 113),
        -INT8_C( 102), -INT8_C(  40), -INT8_C(  56), -INT8_C(  13),  INT8_C( 126), -INT8_C(   3), -INT8_C(  70),  INT8_C(  41),
         INT8_C(   5), -INT8_C(  28),  INT8_C(   4),  INT8_C( 123), -INT8_C(  64),  INT8_C(  16),  INT8_C( 111),  INT8_C( 104),
        -INT8_C(  99), -INT8_C(  37), -INT8_C(  37), -INT8_C(  59), -INT8_C(  39), -INT8_C(  79), -INT8_C(  43), -INT8_C(  80) },
      { -INT32_C(  1614942744), -INT32_C(  1321503683), -INT32_C(  1558359855),  INT32_C(  1840546419), -INT32_C(   658058566), -INT32_C(  2028904336), -INT32_C(   831111343),  INT32_C(   393582667),
         INT32_C(  1639324883),  INT32_C(   605330125), -INT32_C(  1681469212),  INT32_C(  1460199803), -INT32_C(   651164978), -INT32_C(  1503617867), -INT32_C(   864724486), -INT32_C(   840735640) } },
    { { -INT32_C(   789030901), -INT32_C(   381590449), -INT32_C(  1159919300),  INT32_C(   199464710),  INT32_C(   998696827), -INT32_C(  1801193993), -INT32_C(  1436909615),  INT32_C(   995766064),
        -INT32_C(   687123833), -INT32_C(   222278218),  INT32_C(  1571593558), -INT32_C(  1352102092),  INT32_C(  1860890486), -INT32_C(  1258123548),  INT32_C(  1029725197),  INT32_C(   326679179) },
      { UINT8_C( 13), UINT8_C(132), UINT8_C(234), UINT8_C(195), UINT8_C(209), UINT8_C(170), UINT8_C(182), UINT8_C( 39),
        UINT8_C( 72), UINT8_C( 98), UINT8_C(132), UINT8_C(124), UINT8_C(242), UINT8_C(237), UINT8_C( 44), UINT8_C(104),
        UINT8_C(220), UINT8_C( 22), UINT8_C(214), UINT8_C(192), UINT8_C(164), UINT8_C(217), UINT8_C(118), UINT8_C(177),
        UINT8_C( 53), UINT8_C(214), UINT8_C(238), UINT8_C(193), UINT8_C(144), UINT8_C(103), UINT8_C(212), UINT8_C(157),
        UINT8_C(235), UINT8_C(190), UINT8_C( 97), UINT8_C(188), UINT8_C(104), UINT8_C( 23), UINT8_C(227), UINT8_C(176),
        UINT8_C(121), UINT8_C(104), UINT8_C( 45), UINT8_C(107), UINT8_C( 85), UINT8_C( 89), UINT8_C(212), UINT8_C( 49),
        UINT8_C(111), UINT8_C(170), UINT8_C(241), UINT8_C( 20), UINT8_C(131), UINT8_C(103), UINT8_C(197), UINT8_C(185),
        UINT8_C( 61), UINT8_C(180), UINT8_C(122), UINT8_C(206), UINT8_C( 27), UINT8_C( 78), UINT8_C(107), UINT8_C(  6) },
      {  INT8_C(  12), -INT8_C(  52), -INT8_C(  62),  INT8_C( 116), -INT8_C(  29), -INT8_C(  91),  INT8_C(  37),  INT8_C(  93),
         INT8_C(  13),  INT8_C(  82), -INT8_C(  56),  INT8_C(  98), -INT8_C(  85), -INT8_C( 100), -INT8_C( 109),  INT8_C(  26),
         INT8_C(  71), -INT8_C( 123),  INT8_C(  46), -INT8_C(  54), -INT8_C(  20), -INT8_C(  12), -INT8_C( 125),  INT8_C(  42),
        -INT8_C(  88), -INT8_C(   3), -INT8_C(   8), -INT8_C(  61),  INT8_C(  75),  INT8_C(  99), -INT8_C(  55),  INT8_C(  87),
         INT8_C(  48), -INT8_C( 117), -INT8_C(  52),  INT8_C(  19),  INT8_C(  48), -INT8_C(  15),  INT8_C( 112),  INT8_C(  62),
         INT8_C(  67),  INT8_C(  57), -INT8_C(  96), -INT8_C(  18), -INT8_C(  43),  INT8_C(  52),  INT8_C(   8),  INT8_C(  28),
        -INT8_C(  71),  INT8_C(  55), -INT8_C(  25), -INT8_C(  91),  INT8_C(  43),  INT8_C( 106), -INT8_C(  49), -INT8_C(  45),
         INT8_C( 104), -INT8_C(  57), -INT8_C( 106), -INT8_C(  77),  INT8_C(  43),  INT8_C(  95),  INT8_C(  11),  INT8_C(  91) },
      { -INT32_C(   789029497), -INT32_C(   381601619), -INT32_C(  1159905568),  INT32_C(   199418348),  INT32_C(   998709217), -INT32_C(  1801207193), -INT32_C(  1436928598),  INT32_C(   995789060),
        -INT32_C(   687136255), -INT32_C(   222237235),  INT32_C(  1571601347), -INT32_C(  1352098051),  INT32_C(  1860884110), -INT32_C(  1258124975),  INT32_C(  1029692487),  INT32_C(   326689473) } },
    { {  INT32_C(   443471850),  INT32_C(   190373832), -INT32_C(   302384872), -INT32_C(   435551955),  INT32_C(  1670115640), -INT32_C(  1019847845),  INT32_C(  1299696674),  INT32_C(   363364907),
         INT32_C(   556799833),  INT32_C(   237799670), -INT32_C(  1359272575),  INT32_C(  1603536166),  INT32_C(  1388454134), -INT32_C(  1659504261), -INT32_C(   236221243),  INT32_C(  1728484110) },
      { UINT8_C(170), UINT8_C( 54), UINT8_C(136), UINT8_C(160), UINT8_C(191), UINT8_C(180), UINT8_C(174), UINT8_C( 64),
        UINT8_C(217), UINT8_C(170), UINT8_C(239), UINT8_C(  0), UINT8_C(175), UINT8_C(131), UINT8_C( 95), UINT8_C(166),
        UINT8_C(163), UINT8_C( 33), UINT8_C(248), UINT8_C( 30), UINT8_C( 26), UINT8_C( 13), UINT8_C(188), UINT8_C(224),
        UINT8_C(154), UINT8_C(167), UINT8_C(209), UINT8_C(168), UINT8_C( 58), UINT8_C(215), UINT8_C( 16), UINT8_C(229),
        UINT8_C( 14), UINT8_C(152), UINT8_C(133), UINT8_C(205), UINT8_C( 77), UINT8_C( 52), UINT8_C( 13), UINT8_C( 38),
        UINT8_C(222), UINT8_C(252), UINT8_C( 38), UINT8_C(141), UINT8_C(128), UINT8_C(133), UINT8_C( 51), UINT8_C( 35),
        UINT8_C(167), UINT8_C( 43), UINT8_C( 66), UINT8_C(193), UINT8_C( 57), UINT8_C(254), UINT8_C(161), UINT8_C(211),
        UINT8_C(165), UINT8_C(114), UINT8_C(123), UINT8_C(223), UINT8_C( 74), UINT8_C(139), UINT8_C(196), UINT8_C( 88) },
      {  INT8_C(  36),  INT8_C(  74),  INT8_C(  37),  INT8_C( 113),  INT8_C( 126),  INT8_C(  50), -INT8_C( 105),  INT8_C(  92),
         INT8_C(  47), -INT8_C(  66), -INT8_C(  23), -INT8_C(  81),  INT8_C(  67),  INT8_C(  29), -INT8_C(  46), -INT8_C(  22),
         INT8_C(  72),  INT8_C(  20), -INT8_C(  84), -INT8_C( 127),  INT8_C(  18),  INT8_C(  77),  INT8_C(  84), -INT8_C(  73),
        -INT8_C(  64), -INT8_C(  48), -INT8_C( 105),  INT8_C(  10),  INT8_C(  91),  INT8_C(  91),  INT8_C(  98),      INT8_MAX,
        -INT8_C(  91), -INT8_C( 121), -INT8_C(  16),  INT8_C(  35), -INT8_C(  71), -INT8_C( 120),      INT8_MAX, -INT8_C(  24),
         INT8_C(  70),  INT8_C( 105), -INT8_C( 105), -INT8_C( 119), -INT8_C( 122),  INT8_C( 106),  INT8_C( 116), -INT8_C(  50),
         INT8_C( 126),  INT8_C(  32),  INT8_C(  80), -INT8_C( 111),  INT8_C( 109), -INT8_C(  92),  INT8_C(  72),  INT8_C(  45),
         INT8_C( 116), -INT8_C(  33),  INT8_C(  55), -INT8_C(  48),  INT8_C(  59), -INT8_C( 103),  INT8_C(  79), -INT8_C(  32) },
      {  INT32_C(   443505078),  INT32_C(   190394516), -INT32_C(   302391390), -INT32_C(   435544453),  INT32_C(  1670103394), -INT32_C(  1019846936),  INT32_C(  1299658537),  INT32_C(   363420401),
         INT32_C(   556785214),  INT32_C(   237788702), -INT32_C(  1359251344),  INT32_C(  1603538814),  INT32_C(  1388460409), -INT32_C(  1659500329), -INT32_C(   236209804),  INT32_C(  1728486827) } },
    { { -INT32_C(   637255648),  INT32_C(   247628744),  INT32_C(  1922521836),  INT32_C(  1111559108), -INT32_C(  1714187989), -INT32_C(  1429857227),  INT32_C(   914030331), -INT32_C(  1206400617),
        -INT32_C(   778953975), -INT32_C(  1948298082),  INT32_C(  1929213870), -INT32_C(  1363853694),  INT32_C(    88574159), -INT32_C(  1599140444), -INT32_C(  1546245877), -INT32_C(    61084174) },
      { UINT8_C(  8), UINT8_C(237), UINT8_C(205), UINT8_C(167), UINT8_C( 65), UINT8_C(173), UINT8_C( 50), UINT8_C(240),
        UINT8_C( 36), UINT8_C( 47), UINT8_C( 98), UINT8_C(166), UINT8_C(110), UINT8_C( 23), UINT8_C( 84), UINT8_C( 61),
        UINT8_C(160), UINT8_C(155), UINT8_C( 66), UINT8_C( 68), UINT8_C(169), UINT8_C(241), UINT8_C(228), UINT8_C(180),
        UINT8_C( 26), UINT8_C(187), UINT8_C( 87), UINT8_C( 13), UINT8_C(168), UINT8_C(178), UINT8_C(  9), UINT8_C(177),
        UINT8_C(159), UINT8_C(214), UINT8_C( 88), UINT8_C(225), UINT8_C(131), UINT8_C(138), UINT8_C(209), UINT8_C(167),
        UINT8_C(185), UINT8_C( 51), UINT8_C( 78), UINT8_C( 39), UINT8_C( 75), UINT8_C(162), UINT8_C(101), UINT8_C(235),
        UINT8_C( 62), UINT8_C(167), UINT8_C( 47), UINT8_C(231), UINT8_C(153), UINT8_C( 20), UINT8_C(155), UINT8_C(179),
        UINT8_C(207), UINT8_C(243), UINT8_C(192), UINT8_C(119), UINT8_C(165), UINT8_C(201), UINT8_C( 40), UINT8_C( 69) },
      { -INT8_C(  96),      INT8_MIN,  INT8_C(  38),  INT8_C(  35),  INT8_C(  10), -INT8_C(   9), -INT8_C(  53), -INT8_C(  60),
         INT8_C(  42),  INT8_C(  25), -INT8_C(  21),  INT8_C( 117), -INT8_C(  69),  INT8_C(  80),  INT8_C(  96), -INT8_C(   7),
        -INT8_C(   8), -INT8_C( 112), -INT8_C(  32), -INT8_C( 111), -INT8_C(  92),  INT8_C( 124),  INT8_C(  68),  INT8_C( 115),
         INT8_C( 111),  INT8_C(   5), -INT8_C(  22),  INT8_C(  20), -INT8_C(  50),  INT8_C(  19),  INT8_C(  89),  INT8_C( 110),
        -INT8_C( 109),      INT8_MAX, -INT8_C( 110), -INT8_C(  98),  INT8_C( 118),  INT8_C(  93),  INT8_C(  98), -INT8_C(  95),
         INT8_C( 118),  INT8_C(  77),  INT8_C(  22),  INT8_C(  49), -INT8_C(  98),  INT8_C( 119),  INT8_C(  43), -INT8_C( 106),
         INT8_C(   7),  INT8_C(  11),  INT8_C(  39), -INT8_C(  85), -INT8_C( 121),  INT8_C( 107),  INT8_C(  30), -INT8_C(  10),
         INT8_C( 112),  INT8_C(   8),  INT8_C(  11),  INT8_C(  63),  INT8_C(  27),  INT8_C( 100), -INT8_C(  83), -INT8_C(  81) },
      { -INT32_C(   637273117),  INT32_C(   247610787),  INT32_C(  1922541887),  INT32_C(  1111560995), -INT32_C(  1714216289), -INT32_C(  1429806687),  INT32_C(   914032498), -INT32_C(  1206385364),
        -INT32_C(   778975858), -INT32_C(  1948265173),  INT32_C(  1929243254), -INT32_C(  1363862333),  INT32_C(    88558628), -INT32_C(  1599153957), -INT32_C(  1546211140), -INT32_C(    61068528) } },
    { {  INT32_C(  1515012068),  INT32_C(   318484380), -INT32_C(  1706814724), -INT32_C(  1875873911),  INT32_C(    37443450),  INT32_C(   871913923),  INT32_C(  2104623969),  INT32_C(  1277960296),
        -INT32_C(    56198817),  INT32_C(   604938792),  INT32_C(  1035948724),  INT32_C(  1020129217),  INT32_C(   171837511), -INT32_C(  1036175775), -INT32_C(  1572884422),  INT32_C(   804154320) },
      { UINT8_C(228), UINT8_C(148), UINT8_C( 43), UINT8_C( 12), UINT8_C( 54), UINT8_C( 58), UINT8_C( 49), UINT8_C(234),
        UINT8_C(140), UINT8_C(240), UINT8_C( 39), UINT8_C( 78), UINT8_C(223), UINT8_C(244), UINT8_C(138), UINT8_C( 38),
        UINT8_C(252), UINT8_C(200), UINT8_C( 48), UINT8_C( 93), UINT8_C(254), UINT8_C(110), UINT8_C( 32), UINT8_C( 56),
        UINT8_C( 30), UINT8_C( 95), UINT8_C(218), UINT8_C(238), UINT8_C(203), UINT8_C(200), UINT8_C( 29), UINT8_C(175),
        UINT8_C( 93), UINT8_C( 73), UINT8_C(188), UINT8_C(147), UINT8_C(131), UINT8_C(237), UINT8_C(126), UINT8_C( 15),
        UINT8_C(221), UINT8_C(165), UINT8_C( 93), UINT8_C(188), UINT8_C(154), UINT8_C(231), UINT8_C(227), UINT8_C(150),
        UINT8_C(175), UINT8_C( 19), UINT8_C(244), UINT8_C(174), UINT8_C(129), UINT8_C( 20), UINT8_C(230), UINT8_C(159),
        UINT8_C(115), UINT8_C(193), UINT8_C(141), UINT8_C( 62), UINT8_C(137), UINT8_C(171), UINT8_C(238), UINT8_C(230) },
      { -INT8_C(  12), -INT8_C(  86),  INT8_C( 122),  INT8_C( 119), -INT8_C( 105), -INT8_C(   8), -INT8_C( 122),  INT8_C( 116),
        -INT8_C(  99), -INT8_C(  28),  INT8_C(  48),  INT8_C(  55), -INT8_C(  53),  INT8_C(  19), -INT8_C(  50),  INT8_C( 123),
         INT8_C(  39), -INT8_C(  62),  INT8_C(  41), -INT8_C(  88), -INT8_C(  42),  INT8_C(  15),  INT8_C(  72),  INT8_C(  73),
        -INT8_C(  48), -INT8_C(  43), -INT8_C( 120),  INT8_C(  90),      INT8_MIN,  INT8_C( 118),  INT8_C(  64),  INT8_C( 116),
         INT8_C(  32), -INT8_C(  70), -INT8_C(  21), -INT8_C(  73), -INT8_C(  78),  INT8_C( 114),  INT8_C(  43),  INT8_C(  80),
         INT8_C(  86),  INT8_C(  91), -INT8_C( 121),  INT8_C(  33),  INT8_C( 111),  INT8_C(  85), -INT8_C( 100), -INT8_C( 106),
         INT8_C(  23), -INT8_C(  59),  INT8_C(  62), -INT8_C(  19), -INT8_C(  43), -INT8_C( 122),  INT8_C(  55), -INT8_C(  91),
         INT8_C(  92), -INT8_C(  65), -INT8_C(   1), -INT8_C(  36),  INT8_C(  53),  INT8_C(  64),  INT8_C(  81),  INT8_C(  85) },
      {  INT32_C(  1515003278),  INT32_C(   318499412), -INT32_C(  1706829142), -INT32_C(  1875883320),  INT32_C(    37434662),  INT32_C(   871911297),  INT32_C(  2104613704),  INT32_C(  1277980068),
        -INT32_C(    56215630),  INT32_C(   604962210),  INT32_C(  1035977696),  INT32_C(  1020127346),  INT32_C(   171852237), -INT32_C(  1036185581), -INT32_C(  1572888760),  INT32_C(   804211353) } },
  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_dpbusd_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
  #else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_dpbusd_epi32(src, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
  #endif
}

static int
test_simde_mm512_dpbusd_epi32 (SIMDE_MUNIT_TEST_ARGS) {
  #if 1
  const struct {
    int32_t src[16];
    uint8_t a[64];
    int8_t  b[64];
    int32_t r[16];
  } test_vec[] = {

  };

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde__m512i src = simde_mm512_loadu_epi32(test_vec[i].src);
    simde__m512i a = simde_mm512_loadu_epi8(test_vec[i].a);
    simde__m512i b = simde_mm512_loadu_epi8(test_vec[i].b);
    simde__m512i r = simde_mm512_dpbusd_epi32(src, a, b);
    simde_test_x86_assert_equal_i32x16(r, simde_mm512_loadu_epi32(test_vec[i].r));
  }

  return 0;
  #else
  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde__m512i src = simde_test_x86_random_i32x16();
    simde__m512i a = simde_test_x86_random_u8x64();
    simde__m512i b = simde_test_x86_random_i8x64();
    simde__m512i r = simde_mm512_dpbusd_epi32(src, a, b);

    simde_test_x86_write_i32x16(2, src, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_x86_write_u8x64(2, a, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i8x64(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_x86_write_i32x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;
  #endif
}

SIMDE_TEST_FUNC_LIST_BEGIN
  SIMDE_TEST_FUNC_LIST_ENTRY(mm512_dpbusd_epi32)
SIMDE_TEST_FUNC_LIST_END

#include <test/x86/avx512/test-avx512-footer.h>
