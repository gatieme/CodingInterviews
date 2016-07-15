
COMMIT="剑指Offer--题集目录索引--http://blog.csdn.net/gatieme/article/details/51916802"

GITHUB_COMMIT=$(COMMIT)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

