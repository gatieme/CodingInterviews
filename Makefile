
GITHUB_COMMIT=$(COMMIT)


all:github


github:
	git add -A
	git commit -m $(GITHUB_COMMIT)
	git push origin master

