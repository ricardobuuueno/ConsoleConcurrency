// ConsoleConcurrency.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

#include "templates.h"
#include "hierarchical_mutex.h"
#include "strong_types.h"
#include "quick_sort.h"
#include "custom_list.h"
#include "threadsafe_stack.h"
#include "threadsafe_queue.h"
#include "single_linked_queue.h"
#include "coroutine.h"


template <typename T>
void print(std::list<T> l)
{
    std::cout << '\n';
    for (auto i : l) {
        std::cout << i << " ";
    }

}

void hello()
{
    std::cout << "Hello concurrency world!\n";
}

int main()
{
    test_coroutine();

    //custom_list<int> il{};
    //il.insert(1);
    //il.insert(2);
    //il.insert(3);

    //hierarchical_mutex m{10000};

    //std::thread t(hello);
    //t.join();

    //Gram g{ 1000 };
    //Kilogram kg{ g };
    //Pound lb{ kg };

    //std::cout << g.get() << '\n';
    ////std::cout << kg.get() << '\n';

    //std::list<int> itens{};
    //srand(time(nullptr));

    //for (int i = 0; i < 100; ++i) {
    //    int index = rand() % 100;
    //    itens.push_back(index);
    //}

    //print(itens);

    //auto ordered = sequencial_quick_sort(itens);

    //print(ordered);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
