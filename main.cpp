#include <iostream>
#include "node.h"
#include "windows.h" //Included to make certain UTF-8 symbols appear on Windows

int main()
{
    //Included to make certain UTF-8 symbols appear on Windows
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 10);


    Node<int> noden;

    noden.insert(&noden,50);
    noden.insert(&noden,30);
    noden.insert(&noden,20);
    noden.insert(&noden,40);
    noden.insert(&noden,110);
    noden.insert(&noden,60);
    noden.insert(&noden,80);
    noden.insert(&noden,100);
    noden.insert(&noden,180);
    noden.insert(&noden,10);


    std::cout << "pre order ";
    noden.preOrder(&noden);
    std::cout<< std::endl;

    std::cout << "post order ";
    noden.postOrder(&noden);
    std::cout<< std::endl;


    noden.Delete(&noden, 20);

    std::cout << "pre order ";
    noden.preOrder(&noden);
    std::cout<< std::endl;

    std::cout << "post order ";
    noden.postOrder(&noden);
    std::cout<< std::endl;


    noden.PrintTree(&noden);

}
