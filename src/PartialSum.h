#ifndef PARTIALSUM_H
#define PARTIALSUM_H

#include <sdsl/vectors.hpp>
#include <sdsl/rank_support.hpp>
#include <sdsl/select_support.hpp>

using namespace sdsl;
using namespace std;

namespace PartialSum
{
    class PartialSum
    {
    private:
        bit_vector bv;
        rank_support_v<0> rank_0;
        select_support_mcl<1> select_1;
        select_support_mcl<0> select_0;
        rank_support_v<1> rank_1;
        bit_vector TransformToUnary(vector<int> &v);

    public:
        PartialSum(vector<int> &v);
        int Sum(int i);
        int Search(int s);
        void print();
    };

    PartialSum::PartialSum(vector<int> &v)
    {
        bv = TransformToUnary(v);
        util::init_support(rank_0, &bv);
        util::init_support(select_1, &bv);
        util::init_support(select_0, &bv);
        util::init_support(rank_1, &bv);
    }

    bit_vector PartialSum::TransformToUnary(vector<int> &v)
    {
        int tam = 0;
        for (int i = 0; i < v.size(); i++)
        {
            tam += v[i];
        }
        bit_vector bv = bit_vector(tam + v.size());
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            bv[sum] = 1;
            sum++;
        }
        return bv;
    }

    int PartialSum::Sum(int i)
    {
        return rank_0(select_1(i)) - rank_0(select_1(i - 1));
    }

    int PartialSum::Search(int s)
    {//this is the inverse of Sum
        int i = select_0(s + rank_1(s));
        return i - s - rank_1(s) + 2;
    }

    void PartialSum::print()
    {
        cout << bv << endl;
    }

}

#endif // PARTIALSUM_H