
COMMIT="剑指Offer--063-二叉搜索树的第K个结点--http://blog.csdn.net/gatieme/article/details/51902530"
GITHUB_COMMIT=$(COMMIT)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

