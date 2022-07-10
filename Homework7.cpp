// Homework7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>
#include <stdexcept>
#include "IntArray.h"
using namespace std;

int main()
{
    try
    {
        // Declare an array with 10 elements
        IntArray array(10);
        try
        {
            // Fill the array with numbers 1 through 10
            for (int i{ 0 }; i < 10; ++i)
                array[i] = i + 1;
        }
        catch (const out_of_range& e)
        {
            cout << e.what() << endl;
            return 1;
        }

        // Resize the array to 8 elements
        array.resize(8);

        try
        {
            // Insert the number 20 before element with index 5
            array.insertBefore(20, 5);

            // Remove the element with index 3
            array.remove(3);
        }
        catch (const out_of_range& e)
        {
            cout << e.what() << endl;
            return 1;
        }

        // Add 30 and 40 to the end and beginning
        array.insertAtEnd(30);
        array.insertAtBeginning(40);

        // Print out all the numbers
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';

        std::cout << '\n';
    }
    catch (const length_error& e)
    {
        cout << e.what() << endl;
        return 1;
    }
    

    return 0;
}
