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
    //A GRID with 3 rows and 5 columns
    int matrix[4][5] = { {1, 0, 1, 0, 0},
                         {0, 1, 0, 0, 0},
                         {1, 0, 1, 0, 0},
                         {0, 0, 0, 1, 0}};
    //and save the row position, only the cells with value 1
    vector<int> row;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == 1)
            {
                row.push_back(j);
            }
        }
    }

    cout << "Row positions: ";
    for (int i = 0; i < row.size(); i++)
    {
        cout << row[i] << " ";
    }
    cout << endl;
    
    return 0;
}