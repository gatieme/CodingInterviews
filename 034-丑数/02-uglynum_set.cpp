#include <iostream>
#include <set>


using namespace std;


//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain



class Solution
{

public:

    int GetUglyNumber_Solution(int index)
    {
        if(index <= 0)
        {
            return 0;
        }

        if(index == 1)
        {
            return 1;
        }

        set<long> st;
        set<long>::iterator it;
        st.insert(2);
        st.insert(3);
        st.insert(5);

        for(it = st.begin(); it != st.end(); it++)
        {
           int len = st.size( );

           if(len >= index * 2)
           {
               break;
           }
           st.insert(*it * 2);
           st.insert(*it * 3);
           st.insert(*it * 5);
        }

        int count = 0;
        for(long num : st)
        {
            count++;
            if(count == index - 1)
                return num;
        }

        return 0;
    }
};

int __tmain( )
{
    Solution solu;

    cout <<solu.GetUglyNumber_Solution(3) <<endl;

    return 0;
}
