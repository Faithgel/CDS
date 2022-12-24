#ifndef PERMUTATIONMRRR_H
#define PERMUTATIONMRRR_H

#include <iostream>
#include <sdsl/vectors.hpp>

using namespace std;
using namespace sdsl;

namespace Permutation
{
    class Permutacion
    {
    private:
        int_vector<> perm;
        bit_vector sampled;
        int_vector<> rev_links;
        rank_support_v<> rb;

    public:
        Permutacion(int_vector<> &perm, bit_vector &sampled, int_vector<> &rev_links)
        {
            this->perm = perm;
            this->sampled = sampled;
            sdsl::util::init_support(rb, &sampled);
            this->rev_links = rev_links;
        }

        int pi_minus_one(int buscar, int pos, bool shortcut = false)
        {
            if (perm[pos - 1] == buscar)
                return pos;
            if (sampled[pos - 1] == 1 && !shortcut)
            {
                pos = rev_links[rb(pos) - 1];
                return pi_minus_one(buscar, pos, true);
            }
            else
            {
                pos = perm[pos - 1];
                return pi_minus_one(buscar, pos, shortcut);
            }
        }
    };
}

#endif // PERMUTATIONMRRR_H