#ifndef UnaryBase_h
#define UnaryBase_h

#include <iostream>

namespace UnaryBase
{   
    class UnaryBase
    {
    public:
        UnaryBase();
        ~UnaryBase();
        static void toUnary(uint8_t *ori, uint8_t *dest, int n);
        static void printBitArray(const uint8_t *T, size_t T_size);
        static bool access(const uint8_t *e, const size_t p);
        static void BitSet(uint8_t *e, const size_t p);
        static void BitClear(uint8_t *e, const size_t p);
    };

    void UnaryBase::toUnary(uint8_t *ori, uint8_t *dest, int n)
    {
        int j=0;
        for (int i = 0; i < n; i++) {
            BitSet(dest,j+ori[i]);
            j+=ori[i]+1;
        }
    }

    void UnaryBase::printBitArray(const uint8_t *T, size_t T_size)
    {
        for (int i = 0; i < T_size; i++) {
            std::cout << access(T, i);
            if ((i + 1) % 4 == 0) {
                std::cout << " ";
            } else if ((i + 1) % 64 == 0) {
                std::cout << std::endl;
            }
        }
    }

    bool UnaryBase::access(const uint8_t *e, const size_t p)
    {
        return 0 != ((e[p / 8] & (uint8_t) 1 << (8 - 1 - (p % 8))));
    }

    void UnaryBase::BitSet(uint8_t *e, const size_t p)
    {
        e[p / 8] |= ((uint8_t) 1 << (8 - 1 - (p % 8)));
    }

    void UnaryBase::BitClear(uint8_t *e, const size_t p)
    {
        e[p / 8] &= ~((uint8_t) 1 << (8 - 1 - (p % 8)));
    }

} // namespace UnaryBase

#endif /* UnaryBase_h */