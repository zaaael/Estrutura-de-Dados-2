all: clear pointers

pointers:
	@echo -e "\nCompilando o exemplo de ponteiros. Programa pointers"
	gcc Pointers.c -o pointers
	chmod +x pointers

clear:
	@echo -e "\nRemovendo os arquivos compilados"
	rm -f pointers