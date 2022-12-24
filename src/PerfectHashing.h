#ifndef PERFECTHASHING_H
#define PERFECTHASHING_H

#include <sdsl/vectors.hpp>
#include <sdsl/rank_support.hpp>
#include <stdlib.h>
#include <iostream>
using namespace sdsl;
using namespace std;

namespace PerfectHashing
{
    class PerfectHash
    {
    private:
        int_vector<> v;
        bit_vector bv;
        rank_support_v<> rank;

    public:
        PerfectHash(int_vector<> v, int_vector<> keys) : v(v)
        {
            int size = 0;
            for (auto key : keys) size += key;
            bv = bit_vector(size, 0);
            for (auto key : keys) bv[key - 1] = 1;
            rank = rank_support_v<>(&bv);
        }

        int hashData(int key)
        {
            return (v[rank(key) - 1]);
        }
    };

} // namespace PerfectHashing

#endif // PERFECTHASHING_H