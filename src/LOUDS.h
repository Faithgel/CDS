#ifndef LOUDS_h
#define LOUDS_h

#include <iostream>
#include <sdsl/vectors.hpp>
#include <sdsl/rank_support.hpp>
#include <sdsl/select_support.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace sdsl;

namespace LOUDSTree
{

    class LOUDS
    {
    private:
        vector<string> org;
        bit_vector bv;
        select_support_mcl<1> select1;
        rank_support_v<0> rank0;
        bit_vector toLOUDS(vector<string> v );

    public:
        LOUDS(vector<string> v);
    };

    LOUDS::LOUDS(vector<string> v){
        this->org = v;

        util::init_support(select1, &bv);
        util::init_support(rank0, &bv);

    }

    bit_vector LOUDS::toLOUDS(vector<string> v){

        bit_vector bv(1);
        return bv;
    }

    /*
        output: Builds the LOUDS representation of B[1,2n+1] of T

        Q<- T.root(queue head)
        L<- L.root(queue tail)
        Allocate bitvector B[1,2n+1]
        B[0]<- 1
        B[1]<- 0

        i<- 2 (where we append bits in B)
        j<- 1 (where we 1 of node we processing now is)
        while Q!=null do
         L.next<- Q.first
         while L.next!=null do
             B[i]<- 1
            i<- i+1
            L<- L.next
            B[i]<- 0
            i<- i+1
            p <- Q; Q <- Q.next
            if B[j+1]=0 then
                p.next <- null
                j<- j+1
            j<- j+1
            Preprocess B for rank and select
    */
} // namespace LOUDS

#endif /* LOUDS_h */