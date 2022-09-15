all: clear pointers linkedlist doublylinkedlist generalizedlinkedlist

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
	@echo -e "\nCompilando o exemplo de lista simplesmente ligada. Programa linkedlist"
	gcc log.h log.c LinkedList.h LinkedList.c LinkedListTeste.c -o linkedlist
	chmod +x linkedlist

doublylinkedlist:
	@echo ""
	@echo "======================================="
	@echo "|           LISTAS DUPLAS             |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de lista duplamente ligada. Programa doublylinkedlist"
	gcc log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTeste.c -o doublylinkedlist
	chmod +x doublylinkedlist

generalizedlinkedlist:
	@echo ""
	@echo "======================================="
	@echo "|           LISTA GENERALIZADA        |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de lista generalizada. Programa generalizedlinkedlist"
	gcc log.h log.c GeneralizedLinkedList.h GeneralizedLinkedList.c GeneralizedLinkedListTeste.c -o generalizedlinkedlist
	chmod +x generalizedlinkedlist

clear:
	@echo ""
	@echo "======================================="
	@echo "|          REMOVENDO PROGRAMAS        |"          
	@echo "======================================="

	@echo -e "\nRemovendo os arquivos compilados"
	rm -f pointers linkedlist logs doublylinkedlist generalizedlinkedlist