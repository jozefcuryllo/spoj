#include <iostream>
#include <math.h>
#include <list>

int process(std::istream &in, std::ostream &out)
{
    unsigned int numberOfLines;
    in >> numberOfLines;

    while (numberOfLines--)
    {
        unsigned int from;
        unsigned int to;
        in >> from >> to;
        from = std::max((unsigned int)2, from);
        bool isPrime;
        unsigned int sqrt_to;
        
        for (unsigned int i = from; i <= to; i++)
        {
            isPrime = true;
            sqrt_to = std::min((unsigned int)sqrt(to), i - 1);

            for (unsigned int j = 2; j < sqrt_to + 1; j++)
            {
                if (i % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                out << i << "\n";
            }
        }

        if (numberOfLines)
        {
            out << "\n";
        }
    }

    return 0;
}
