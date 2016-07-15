
COMMIT="剑指Offer--065-滑动窗口的最大值--http://blog.csdn.net/gatieme/article/details/51915826"

GITHUB_COMMIT=$(COMMIT)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

