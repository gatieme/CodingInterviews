
GITHUB_COMMIT=$(COMMIT)


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

all:github
