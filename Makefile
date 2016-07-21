
COMMIT_0="剑指Offer--题集目录索引--http://blog.csdn.net/gatieme/article/details/51916802"

COMMIT_3="剑指Offer–003–二维数组中的查找--http://blog.csdn.net/gatieme/article/details/51100125"
COMMIT_4="剑指Offer–004-替换空格--http://blog.csdn.net/gatieme/article/details/51100630"
COMMIT_5="剑指Offer–005-从尾到头打印链表--http://blog.csdn.net/gatieme/article/details/51107632"
COMMIT_6="剑指Offer–006-重构二叉树--http://blog.csdn.net/gatieme/article/details/51108612"
COMMIT_7="剑指Offer–007-用两个栈实现队列--http://blog.csdn.net/gatieme/article/details/51112580"
COMMIT_8="剑指Offer–008-旋转数组的最小数字--http://blog.csdn.net/gatieme/article/details/51115386"
COMMIT_9="剑指Offer–009-斐波那契数列--http://blog.csdn.net/gatieme/article/details/51115810"


GITHUB_COMMIT=$(COMMIT_8)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

