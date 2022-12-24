#include "CompactArray.h"
#include "UnaryBase.h"
#include "PermutationMRRR.h"
#include "PartialSum.h"
#include "PerfectHashing.h"
#include <sdsl/vectors.hpp>
#include <sdsl/rank_support.hpp>
#include <sdsl/select_support.hpp>
#include <iostream>
#include <sdsl/util.hpp>
#include <vector>

using namespace std;
using namespace CompactArray;
using namespace UnaryBase;
using namespace Permutation;
using namespace PartialSum;
using namespace sdsl;
using namespace PerfectHashing;

int main()
{   
    //CompactArray
    /*
    CompactArray::CompactArray *ca = new CompactArray::CompactArray(10, 3);
    for(auto i = 0; i < 10; i++)
    {
        ca->write(i, i);
    }

    for(auto i = 0; i < 10; i++)
    {
        cout << ca->read(i) << endl;
    }
    */
    

    //UnaryBase
    uint8_t original[] = {2, 4, 1, 5, 7, 9};
    int n = 6;
    int bits = 0;
    for (int i = 0; i < n; i++) {
        bits += original[i];
    }
    
    bits += n;
    uint8_t *unario = new uint8_t[(bits + 7) / 8]();
    UnaryBase::UnaryBase::toUnary(original, unario, n);
    UnaryBase::UnaryBase::printBitArray(unario, bits);
    cout << endl;
    
    //PermutationMRRR
    int_vector<> v = {1,4,9,2,7,5,3,6,8};
    sdsl::util::bit_compress(v);

    bit_vector bv(9, 0);
    bv[2] = 1;
    bv[4] = 1;
    bv[7] = 1;

    int_vector<> rev_links = {5,8,3};
    sdsl::util::bit_compress(rev_links);
    Permutation::Permutacion *permutacion = new Permutation::Permutacion( v, bv, rev_links);
    cout << "PI - 1 (1) = " << permutacion->pi_minus_one(1, 1) << endl;
    cout << "PI - 1 (9) = " << permutacion->pi_minus_one(9,9) << endl;

    //PartialSum
    vector<int> v2 = {1,2,3,4};
    PartialSum::PartialSum *partialSum = new PartialSum::PartialSum(v2);
    cout<< "Sum(4) = " << partialSum->Sum(4) << endl;
    cout << "Search(6) = " << partialSum->Search(6) << endl;

    //PerfectHashing
    int_vector <> v3 = {1,3,4,5};
    int_vector <> keys = {1,2,3,4};

    PerfectHashing::PerfectHash *perfectHash = new PerfectHashing::PerfectHash(v3, keys);
    cout << "Hash(2) = " << perfectHash->hashData(2) << endl;

}