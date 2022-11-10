#include <bits/stdc++.h>
#include "list.h"

void printList(sc::list<int>lista){
    std::cout << "Lista → ";
    auto itr = lista.begin();
	std::cout << *itr++;
	for (; itr != lista.end(); ++itr){
		std::cout << " " << *itr;
	}
	std::cout << endl;
}

int main(){
    /////////////////////////////////////////////////////////////////
    sc::list<int> lista;
    std::cout << "Lista → " << lista << std::endl;
    std::cout << "Size Expected (0) → " << lista.size() << std::endl;
    lista.push_back(1);
    std::cout << "Size Expected (1) → " << lista.size() << std::endl;
    lista.push_back(2);
    std::cout << "Size Expected (2) → " << lista.size() << std::endl;
    std::cout << "Lista → " << lista << std::endl;
    lista.push_back(3);
    lista.push_back(4);
    std::cout << "Lista → " << lista << std::endl;


    std::cout << "Primeiro Valor → " << *lista.begin() << std::endl;
    auto teste = lista.end()--;
    std::cout << "Ultimo Valor → " << *teste << std::endl;
    //////////////////////////////////////////////////////////
    std::cout << std::endl;
    sc::list<int> list_init{10,11,12,13,14,15};
    std::cout << "Lista → " << list_init << std::endl;
    std::cout << std::endl;
    /////////////////////////////////HACK//////////////////////
    std::list<int> hack;
    //printList(hack);
    hack.push_back(1);
    //std::cout << "Size → " << hack.size() << std::endl;
    //printList(hack);
    hack.push_back(2);
    hack.push_back(3);
    hack.push_back(4);
    hack.push_back(5);
    //printList(hack);
    auto itr = hack.begin();
    std::cout << "Primeiro Valor → " << *itr << std::endl; 
    std::cout << "Ultimo Valor → " << *hack.end() << std::endl;

    
    /////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////
    //sc::list<int> lista1(10);
    //std::cout << "Size Expected (10) → " << lista1.size() << std::endl;
    //std::cout << "Lista → " << lista1 << std::endl;
    //lista1.push_back(11);
    //std::cout << "Lista → " << lista1 << std::endl;
    //lista1.push_front(11);
    //std::cout << "Lista → " << lista1 << std::endl;
    //////////////////////////////////////////////////////////////////

    sc::list<int> list3{ 1, 2, 3, 4, 5 };
    sc::list<int> list4;
    list4 = list3;
    //printList(list4);
 
    return 0;
}