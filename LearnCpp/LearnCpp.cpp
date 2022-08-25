// LearnCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <array>
#include <iostream>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <numeric>
#include <random>

#include "array.h"
#include "algorithm.h"

using course::Array;

int main()
{
    Array<int, 20> a{};

    for (size_t i{ 0 }; i < a.size(); ++i) {
        a[i] = static_cast<int>(i);
        std::cout << "a[" << i << "] = " << a[i] << '\n';
    }

    std::cout << "is_sorted: " << course::is_sorted(a.begin(), a.end()) << "\n\n";

    std::cout << "missing: " << course::find_missing_element(a.begin(), a.end()) << "\n\n";

    course::reverse(a.begin(), a.end());

    std::cout << "max: " << course::max(a.begin(), a.end()) << '\n';
    std::cout << "min: " << course::min(a.begin(), a.end()) << '\n';

    int* i = course::find_with_transposition(a.begin(), a.end(), 10);
    std::cout << "find: " << *i << "\n\n";

    course::print(a.begin(), a.end());

    std::cout << "\n\n";

    //--------------------------------------------

    Array<int, 100> b{};
    std::iota(b.begin(), b.end(), 1);

    course::print(b.begin(), b.end());

    int* bv = course::binary_search_iterative(b.begin(), b.end(), 27);
    std::cout << "bv = " << *bv << '\n';

    std::cout << "sum: " << course::sum(b.begin(), b.end()) << '\n';

    std::cout << "\n\n";

    //--------------------------------------------

    Array<int, 30> c{};

    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(1, 100);

    for (int n = 0; n < c.size(); ++n) {
        c[n] = distrib(gen);
    }

    course::print(c.begin(), c.end());
    std::cout << "\n\nis_sorted: " << course::is_sorted(c.begin(), c.end()) << "\n\n";


    //--------------------------------------------


    Array<int, 20> d{};
    for (size_t i{ 0 }; i < d.size(); ++i) {
        d[i] = static_cast<int>(i) + (i > 9 ? 5 : 4);
    }

    std::cout << "\n\nis_sorted: " << course::is_sorted(d.begin(), d.end()) << "\n\n";
    course::print(d.begin(), d.end());




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
