#ifndef CompactArray_h
#define CompactArray_h

#include <iostream>
#include <bitset>

using namespace std;
namespace CompactArray
{
    class CompactArray
    {
    private:
        unsigned int *A;
        int l;
        int n;
        const unsigned int w = sizeof(unsigned int) * 8;

        unsigned int bitsread(unsigned int *W, int jp, int j)
        {
            if (jp > j)
                return 0;
            unsigned int r = (j % w) + 1;
            if ((j / w) == (jp / w))
                return (W[j / w] >> (w - r)) % (1 << (j - jp + 1));
            unsigned int rp = jp % w;
            unsigned int aux = (W[jp / w] % (1 << (w - rp))) << r;
            return (W[j / w] >> (w - r)) + aux;
        }

        unsigned int read(unsigned int *A, int l, int i)
        {
            return bitsread(A, (i - 1) * l, i * l - 1);
        }

        void bitswrite(unsigned int *W, int jp, int j, unsigned int x)
        {
            if (jp > j) return;
            unsigned int r = (j % w) + 1;
            if ((j / w) == (jp / w))
            {
                W[j / w] -= (((W[j / w] >> (w - r)) % (1 << (j - jp + 1))) << (w - r));
                W[j / w] += (x << (w - r));
            }
            else
            {
                unsigned int rp = jp % w;
                W[j / w] = (W[j / w] % (1 << (w - r))) + ((x % (1 << r)) << (w - r)); 
                W[jp / w] -= (W[jp / w] % (1 << (w - rp)));
                W[jp / w] += (x >> r);
            }
        }

        void write(unsigned int *A, int l, int i, unsigned int x)
        {                                            
            bitswrite(A, (i - 1) * l, i * l - 1, x); 
        }

    public:
        CompactArray(int n, int l)
        {
            this->n = n;
            this->l = l;
            A = new unsigned int[(n * l) / w + 1];
        }

        ~CompactArray()
        {
            delete[] A;
        }

        unsigned int read(int i)
        {
            return read(A, l, i);
        }

        void write(int i, unsigned int x)
        {
            write(A, l, i, x);
        }

        void print()
        {
            for (int i = 1; i <= n; i++)
            {
                cout << read(i) << " ";
            }
            cout << endl;
        }
    };

} // namespace CompactArray

#endif /* CompactArray_h */