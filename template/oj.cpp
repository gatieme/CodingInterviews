#include <iostream>

#include <cstdio>
#include <cstdlib>


using namespace std;



//  调试开关
#define DEBUG


#ifdef DEBUG

#define debug       cout
#define dprintf     printf

#else

#define debug       0 && cout
#define dprintf     0 && printf

#endif // DEBUG




int main( )
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int a, b;
    while(scanf("%d%d", &a, &b) != EOF)
    {
        printf("%d\n", a + b);
    }


    return EXIT_SUCCESS;
}
