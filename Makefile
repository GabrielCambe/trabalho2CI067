commit:
	git update-index
	git commit -m "commit com MAKE"
	git push

commit-dr:
	git commit -a --dry-run
	git update-index
