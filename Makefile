
COMMIT_0="剑指Offer--题集目录索引--http://blog.csdn.net/gatieme/article/details/51916802"

COMMIT_3="剑指Offer–003–二维数组中的查找--http://blog.csdn.net/gatieme/article/details/51100125"
COMMIT_4="剑指Offer–004-替换空格--http://blog.csdn.net/gatieme/article/details/51100630"
COMMIT_5="剑指Offer–005-从尾到头打印链表--http://blog.csdn.net/gatieme/article/details/51107632"
COMMIT_6="剑指Offer–006-重构二叉树--http://blog.csdn.net/gatieme/article/details/51108612"
COMMIT_7="剑指Offer–007-用两个栈实现队列--http://blog.csdn.net/gatieme/article/details/51112580"
COMMIT_8="剑指Offer–008-旋转数组的最小数字--http://blog.csdn.net/gatieme/article/details/51115386"
COMMIT_9="剑指Offer–009-斐波那契数列--http://blog.csdn.net/gatieme/article/details/51115810"
COMMIT_10="剑指Offer–010-二进制中1的个数--http://blog.csdn.net/gatieme/article/details/51122144"
COMMIT_11="剑指Offer--011-数值的整数次方--http://blog.csdn.net/gatieme/article/details/51123043"
COMMIT_12="剑指Offer--012-打印1到最大的N位数--http://blog.csdn.net/gatieme/article/details/51132108"
COMMIT_14="剑指Offer–014-调整数组顺序使奇数位于偶数前面--http://blog.csdn.net/gatieme/article/details/51133277"
COMMIT_15="剑指Offer–015-链表中倒数第k个结点--http://blog.csdn.net/gatieme/article/details/51133817"
COMMIT_16=" 剑指Offer--016-反转链表--http://blog.csdn.net/gatieme/article/details/51135119"
COMMIT_17="剑指Offer–017-合并两个排序的链表--http://blog.csdn.net/gatieme/article/details/51138298"
COMMIT_18="剑指Offer–018-树的子结构--http://blog.csdn.net/gatieme/article/details/51151916"
COMMIT_19="剑指Offer--019-二叉树的镜像--http://blog.csdn.net/gatieme/article/details/51175749"
COMMIT_20="剑指Offer–020-顺时针打印矩阵--http://blog.csdn.net/gatieme/article/details/51916802"
COMMIT_21="剑指Offer--021-支持min操作的栈--http://blog.csdn.net/gatieme/article/details/51184578"
COMMIT_22="剑指Offer–022栈的压入、弹出序列--http://blog.csdn.net/gatieme/article/details/51190653"
COMMIT_23="剑指Offer–023-从上往下打印二叉树--http://blog.csdn.net/gatieme/article/details/51204976"
COMMIT_24="剑指Offer–024-二叉搜索树的后序遍历序列--http://blog.csdn.net/gatieme/article/details/51213665"
COMMIT_25="剑指Offer–025-二叉树中和为某一值的路径--http://blog.csdn.net/gatieme/article/details/51214182"
COMMIT_26="剑指Offer--026-复杂链表的复制--http://blog.csdn.net/gatieme/article/details/51227939"
COMMIT_27="剑指Offer--027-二叉搜索树与双向链表--http://blog.csdn.net/gatieme/article/details/51234524"
COMMIT_28="剑指Offer--028-字符串的排列--http://blog.csdn.net/gatieme/article/details/51251158"
COMMIT_29="剑指Offer--029-数组中出现次数超过一半的数字--http://blog.csdn.net/gatieme/article/details/51251311"
COMMIT_30="剑指Offer--030-最小的K个数--http://blog.csdn.net/gatieme/article/details/51277505"
COMMIT_31="剑指Offer--031-连续子数组的最大和--http://blog.csdn.net/gatieme/article/details/51287801"
COMMIT_32="剑指Offer--032-整数中1出现的次数（从1到n整数中1出现的次数）--http://blog.csdn.net/gatieme/article/details/51292339"
COMMIT_33="剑指Offer--033-把数组排成最小的数--http://blog.csdn.net/gatieme/article/details/51303662"
COMMIT_34="剑指Offer--034-丑数--http://blog.csdn.net/gatieme/article/details/51308037"
COMMIT_35="剑指Offer--035-第一个只出现一次的字符位置--http://blog.csdn.net/gatieme/article/details/51319158"
COMMIT_36="剑指Offer--036-数组中的逆序对--http://blog.csdn.net/gatieme/article/details/51326994"
COMMIT_37="剑指Offer–037-两个链表的第一个公共结点--http://blog.csdn.net/gatieme/article/details/51330871"
COMMIT_38="剑指Offer--038-数字在排序数组中出现的次数--http://blog.csdn.net/gatieme/article/details/51335323"
COMMIT_39_1="剑指Offer–039-二叉树的深度--http://blog.csdn.net/gatieme/article/details/51339884"
COMMIT_39_2="剑指Offer–039-平衡二叉树--http://blog.csdn.net/gatieme/article/details/51346422"
COMMIT_40="剑指Offer--040-数组中只出现一次的数字--http://blog.csdn.net/gatieme/article/details/51352156"
COMMIT_41="剑指Offer–041-和为S的连续正数序列--http://blog.csdn.net/gatieme/article/details/51357308"
COMMIT_42_1="剑指Offer–042-翻转单词顺序列--http://blog.csdn.net/gatieme/article/details/51419097"
COMMIT_42_2="剑指Offer–042-左旋转字符串--http://blog.csdn.net/gatieme/article/details/51407858"
COMMIT_46="剑指Offer--046-求1+2+3+...+n--http://blog.csdn.net/gatieme/article/details/51485713"


COMMIT_OTHER="修改了README.md的表示格式..."


RETURN_TOP ="<br>**您也可以选择[回到目录-剑指Offer--题集目录索引](http://blog.csdn.net/gatieme/article/details/51916802)**"



GITHUB_COMMIT=$(COMMIT_OTHER)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

