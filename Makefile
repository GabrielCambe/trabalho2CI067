NOME = -o edit
SRC = ./src/
INCLUDE = ./include/

MAIN_src = $(SRC)main.c

CC = gcc
CC_flags = -Wall -I$(INCLUDE)


all: editor 

editor:
	$(CC) $(NOME) $(MAIN_src) $(CC_flags)

purge:
	rm edit

#regras para o controle de versão
commit:
	git update-index
	git commit -m "commit com MAKE"
	git push

update:
	git update-index --add
	git commit -a --dry-run
	git add --all
