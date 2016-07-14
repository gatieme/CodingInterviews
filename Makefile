
COMMIT="剑指Offer--062-序列化二叉树--http://blog.csdn.net/gatieme/article/details/51901268"


GITHUB_COMMIT=$(COMMIT)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

