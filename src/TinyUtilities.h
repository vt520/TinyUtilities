#ifndef _vt520_tinyutilities_h
#define _vt520_tinyutilities_h
#include<Arduino.h>
    namespace Tiny {
        using modmath_t = unsigned long;
        using pmath_t = unsigned;
        using millis_t = unsigned long;

        struct {
            using modmath_ti = long long;
            modmath_t Difference(modmath_t start, modmath_t end, modmath_t basis) {
                modmath_ti result = end;
                result -= start;
                if (result < 0) result += basis;
                return result;
            }
        } Modulus;

        struct {
            const millis_t millis_t_max = (millis_t) 0 | 0xffffffffffffffffLL;
            millis_t Difference(millis_t start, millis_t end) {
                return Modulus.Difference(start, end, millis_t_max);
            }
        } Millis;

        namespace Memory {
            struct Segment {
                const void * address; 
                const pmath_t length;
                bool Accomodates(pmath_t length) {
                    return this->length >= length;
                }
                bool Overflows(pmath_t offset, pmath_t length) {
                    return !Accomodates(length) || offset + length > this->length;
                }
                Segment Offset(pmath_t offset, pmath_t length) {
                    if (Overflows(offset, length)) {
                        length = this->length - offset;
                    }
                    return {this->address + offset, length};
                }
            };
        }
    }

#endif