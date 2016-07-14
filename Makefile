
COMMIT="剑指Offer--064-数据流中的中位数--http://blog.csdn.net/gatieme/article/details/51908274"

GITHUB_COMMIT=$(COMMIT)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

