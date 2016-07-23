# -*- coding:utf-8-*-



class Solution:

    def IsPopOrder(self, pushV, popV):

        # write code here

        if len(pushV) != len(popV):

            return False

        elif len(pushV) ==0:

            return False

        x = popV[0]

        if x not in pushV:

            return False

        for i in range(len(popV)) :

            position = pushV.index(popV[i])

            if len(pushV) == 1 :

                if pushV[0] == popV[i]:

                    return True

            try:

                if popV[i+1] == pushV[position-1]:

                    pushV.remove(pushV[position])

                elif popV[i+1] in pushV[position:]:

                    pushV.remove(pushV[position])

                else:

                    return False

            except IndexError:

                return False

        else:

            return True


if __name__ == "__main__" :

    nPush = [ 1, 2, 3, 4, 5 ]
    nPop1 = [ 4, 5, 3, 2, 1 ]
    nPop2 = [ 4, 3, 5, 1, 2 ]
    nPop3 = [ 5, 4, 3, 2, 1 ]
    nPop4 = [ 4, 5, 2, 3, 1 ]

    solu = Solution( )
    print solu.IsPopOrder(nPush, nPop1)
    print solu.IsPopOrder(nPush, nPop2)
    print solu.IsPopOrder(nPush, nPop3)
    print solu.IsPopOrder(nPush, nPop4)

