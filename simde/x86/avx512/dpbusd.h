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

#if !defined(SIMDE_X86_AVX512_DPBUSD_H)
#define SIMDE_X86_AVX512_DPBUSD_H

#include "types.h"
#include "mov.h"
#include "../avx512.h"

HEDLEY_DIAGNOSTIC_PUSH
SIMDE_DISABLE_UNWANTED_DIAGNOSTICS
SIMDE_BEGIN_DECLS_

SIMDE_FUNCTION_ATTRIBUTES
simde__m128i
simde_mm_dpbusd_epi32 (simde__m128i src, simde__m128i a, simde__m128i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm_dpbusd_epi32(src, a, b);
  #else
      simde__m128i tmp1 = simde_mm_maddubs_epi16(a, b);
      simde__m128i tmp2 = simde_mm_madd_epi16(tmp1, simde_mm_set1_epi16(INT16_C(1)));

      return simde_mm_add_epi32(tmp2, src);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m256i
simde_mm256_dpbusd_epi32 (simde__m256i src, simde__m256i a, simde__m256i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE) && defined(SIMDE_X86_AVX512VL_NATIVE)
    return _mm256_dpbusd_epi32(src, a, b);
  #else
    simde__m256i tmp1 = simde_mm256_maddubs_epi16(a, b);
    simde__m256i tmp2 = simde_mm256_madd_epi16(tmp1, simde_mm256_set1_epi16(INT16_C(1)));

    return simde_mm256_add_epi32(tmp2, src);
  #endif
}

SIMDE_FUNCTION_ATTRIBUTES
simde__m512i
simde_mm512_dpbusd_epi32 (simde__m512i src, simde__m512i a, simde__m512i b) {
  #if defined(SIMDE_X86_AVX512VNNI_NATIVE)
    return _mm512_dpbusd_epi32(src, a, b);
  #else
    simde__m512i tmp1 = simde_mm512_maddubs_epi16(a, b);
    simde__m512i tmp2 = simde_mm512_madd_epi16(tmp1, simde_mm512_set1_epi16(INT16_C(1)));

    return simde_mm512_add_epi32(tmp2, src);
  #endif
}

SIMDE_END_DECLS_
HEDLEY_DIAGNOSTIC_POP

#endif /* !defined(SIMDE_X86_AVX512_DPBUSD_H) */
