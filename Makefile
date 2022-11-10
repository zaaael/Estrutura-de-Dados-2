all: clear pointers linkedlist doublylinkedlist generalizedlinkedlist hash binarysearchtree

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

stack:
	@echo ""
	@echo "======================================="
	@echo "|           Pilha, Prova              |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de Pilha. Programa stack"
	gcc log.h log.c Stack.h Stack.c StackTeste.c -o stack
	chmod +x stack

hash:
	@echo ""
	@echo "======================================="
	@echo "|           Tabela Hash               |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de Hash. Programa hash"
	gcc log.h log.c Hash.h Hash.c HashTeste.c DoublyLinkedList.h DoublyLinkedList.c -o hash
	chmod +x hash

binarysearchtree:
	@echo ""
	@echo "======================================="
	@echo "|           Árvore Binária            |"
	@echo "======================================="
	@echo -e "\nCompilando o exemplo de Árvore Binária. Programa binarysearchtree"
	gcc log.h log.c BinarySearchTree.h BinarySearchTree.c BinarySearchTree.c -o binarysearchtree
	chmod +x binarysearchtree

clear:
	@echo ""
	@echo "======================================="
	@echo "|          REMOVENDO PROGRAMAS        |"          
	@echo "======================================="

	@echo -e "\nRemovendo os arquivos compilados"
	rm -f pointers linkedlist logs doublylinkedlist generalizedlinkedlist stack hash binarysearchtree