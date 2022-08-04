all: clear pointers linkedlist

pointers:
	@echo ""
	@echo "======================================="
	@echo "|           PONTEIROS                 |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de ponteiros. Programa pointers"
	gcc Pointers.c -o pointers
	chmod +x pointers

linkedlist:
	@echo ""
	@echo "======================================="
	@echo "|           LISTAS                    |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de lista simplesmente. Programa linkedlist"
	gcc LinkedList.h LinkedList.c LinkedListTeste.c -o linkedlist
	chmod +x linkedlist

clear:
	@echo ""
	@echo "======================================="
	@echo "|          REMOVENDO PROGRAMAS        |"          
	@echo "======================================="

	@echo -e "\nRemovendo os arquivos compilados"
	rm -f pointers linkedlist