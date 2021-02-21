// C_plus_plus_Sandbox.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

http://www.techiedelight.com/min-heap-max-heap-implementation-c/
Implement a heap data structure in c++
 Output:

Size is 3
2 3
Size is 4
4 5 15 45
true
Vector::at() : index is out of range(Heap underflow)
Vector::at() : index is out of range(Heap underflow)
*******************************************************************************/
#include <stdio.h>      /* printf */
#include <math.h> 
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Data structure to store a min-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> A;

    // return parent of `A[i]`
    // don't call this function if `i` is already a root node
    int PARENT(int i) {
        return floor((i - 1) / 2);
    }

    // return left child of `A[i]`
    int LEFT(int i) {
        return (2 * i + 1);
    }

    // return right child of `A[i]`
    int RIGHT(int i) {
        return (2 * i + 2);
    }

    // Recursive heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify_down(int i)
    {
        /* When removing an element, always remove the root
        1.Grab the root
        2.Swap the element at index into the roots position
        3.decrement index
        4.while the "out of place element" has a larger priority than any child, swap the out of place element with the smallest child
        this last step is known as "heapify down", and can be implemented recursively */

        //1.Grab the root
        int smallest = i;
        int left = LEFT(i);
        int right = RIGHT(i);

        //2.Swap the element at index into the roots position
        //if current root is greater than the left child and
        //child is not outside of array bounds
        if (A[smallest] > A[left] && left < size())
        {
            //replace current root with left child 
            smallest = left;
        }

        //if current root is greater than the right child and
        //child is not outside of array bounds        
        if (A[smallest] > A[right] && right < size())
        {
            smallest = right;
        }

        //check if smaller node was found.
        if (smallest != i)
        {
            //Smaller node found so swap current root with node pointed to by 
            //smallest index and make recursive call
            swap(A[i], A[smallest]);
            heapify_down(i);
        }

    }

    // Recursive heapify-up algorithm
    void heapify_up(int i)
    {

    }

public:
    // return size of the heap
    unsigned int size() {
        return A.size();
    }

    // Function to check if the heap is empty or not
    bool empty() {
        return 0;
    }

    // insert key into the heap
    void push(int key)
    {

    }

    // Function to remove an element with the lowest priority (present at the root)
    void pop()
    {

    }

    // Function to return an element with the lowest priority (present at the root)
    int top()
    {
        return 0;
    }
};

int main()
{
    PriorityQueue pq;

    // Note: The element's value decides priority

    pq.push(3);
    pq.push(2);
    pq.push(15);

    cout << "Size is " << pq.size() << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    pq.push(5);
    pq.push(4);
    pq.push(45);

    cout << endl << "Size is " << pq.size() << endl;

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << pq.top() << " ";
    pq.pop();

    cout << endl << std::boolalpha << pq.empty();

    pq.top();    // top operation on an empty heap
    pq.pop();    // pop operation on an empty heap

    return 0;

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
