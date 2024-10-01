// main and only main write with chatgpt 

#include <iostream>
#include <exception>

#include "vecteur.hpp"
#include "iterator.hpp"

int main() {
    // Test 1: Default constructor and initial state
    Vecteur v;
    std::cout << "Initial size: " << v.size() << std::endl; // Should be 0

    // Test 2: Adding elements
    v.add(10);
    v.add(20);
    v.add(30);
    std::cout << "After adding 3 elements, size: " << v.size() << std::endl; // Should be 3

    // Test 3: Printing elements
    std::cout << "Vector elements: ";
    v.print(std::cout); // Should print "10 20 30"
    std::cout << std::endl;

    // Test 4: Accessing elements
    std::cout << "Element at index 0: " << v.get(0) << std::endl; // Should print 10
    std::cout << "Element at index 1: " << v.get(1) << std::endl; // Should print 20
    std::cout << "Element at index 2: " << v.get(2) << std::endl; // Should print 30

    // Test 5: Attempting to access an invalid index
    try {
        std::cout << "Attempting to access index 5: ";
        std::cout << v.get(5) << std::endl; // Should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl; // Should catch the exception
    }

    // Test 6: Testing resizing functionality
    for (int i = 1; i <= 10; ++i) {
        v.add(i * 10); // Adding elements to trigger resizing
    }
    std::cout << "After adding 10 more elements, size: " << v.size() << std::endl; // Should be 13
    std::cout << "Vector elements after resizing: ";
    v.print(std::cout); // Should print "10 20 30 10 20 30 40 50 60 70 80 90 100"
    std::cout << std::endl;

    // Test 7: Testing copy constructor
    Vecteur vCopy = v; // Copying the vector
    std::cout << "Copied vector size: " << vCopy.size() << std::endl; // Should be 13
    std::cout << "Copied vector elements: ";
    vCopy.print(std::cout); // Should print the same elements as v
    std::cout << std::endl;

    // Test 8: Testing assignment operator
    Vecteur vAssign;
    vAssign = v; // Using assignment operator
    std::cout << "Assigned vector size: " << vAssign.size() << std::endl; // Should be 13
    std::cout << "Assigned vector elements: ";
    vAssign.print(std::cout); // Should print the same elements as v
    std::cout << std::endl;

    // Test 9: Testing constructor with initial capacity
    Vecteur v2(5);
    std::cout << "Size of v2 (initial capacity 5): " << v2.size() << std::endl; // Expected: 0

    // Test 10: Test add function
    v2.add(10);
    v2.add(20);
    v2.add(30);
    std::cout << "Contents of v2 after adding elements: ";
    v2.print(std::cout); // Expected: 10 20 30
    std::cout << std::endl;

    // Test 11: Test indexing operator
    std::cout << "Element at index 1 in v2: " << v2[1] << std::endl; // Expected: 20

    // Test 12: Testing copy constructor again
    Vecteur v3(v2);
    std::cout << "Contents of v3 (copy of v2): ";
    v3.print(std::cout); // Expected: 10 20 30
    std::cout << std::endl;

    // Test 13: Testing assignment operator again
    Vecteur v4;
    v4 = v2;
    std::cout << "Contents of v4 after assignment from v2: ";
    v4.print(std::cout); // Expected: 10 20 30
    std::cout << std::endl;

    // Test 14: Testing addition operator
    Vecteur v5 = v2 + v3; // Should contain elements from v2 followed by elements from v3
    std::cout << "Contents of v5 (v2 + v3): ";
    v5.print(std::cout); // Expected: 10 20 30 10 20 30
    std::cout << std::endl;

    // Test 15: Testing scalar product
    int scalarProduct = v2 * v3; // Expected: 10*10 + 20*20 + 30*30
    std::cout << "Scalar product of v2 and v3: " << scalarProduct << std::endl; // Expected: 1400

    // Test 16: Test out-of-bounds access
    try {
        std::cout << "Trying to access index 5 in v2: " << v2[5] << std::endl; // Should throw
    } catch (const std::out_of_range &e) {
        std::cout << "Exception: " << e.what() << std::endl; // Expected: "Index out of range"
    }

    // Test 17: Getting size
    std::cout << "Size of v2: " << v2.size() << std::endl; // Expected: 3

    // Test 18: Using iterator to print elements
    std::cout << "Vector v2 elements using iterator: ";
    for (Iterator it = v2.begin(); it != v2.end(); ++it) {
        std::cout << *it << " "; // Dereference iterator to get the value
    }
    std::cout << std::endl;

    // Test 19: Iterating through an empty vector
    Vecteur emptyVec;
    std::cout << "Iterating through an empty vector: ";
    for (Iterator it = emptyVec.begin(); it != emptyVec.end(); ++it) {
        std::cout << *it << " "; // Should not output anything
    }
    std::cout << "Done." << std::endl;

    // Test 20: Iterator inequality
    Iterator itStart = v2.begin();
    Iterator itEnd = v2.end();

    // Move the start iterator to the first element
    itStart++;
    std::cout << "Testing iterator inequality: ";
    std::cout << (itStart == itEnd ? "Equal" : "Not Equal") << std::endl; // Should print "Not Equal"

    // Test 21: Using post-increment operator
    std::cout << "Using post-increment operator: ";
    for (Iterator it = v2.begin(); it != v2.end();) {
        std::cout << *it << " "; // Print the current element
        it++; // Move to the next element
    }
    std::cout << std::endl;

    // Test 22: Accessing elements using iterator with dereferencing
    std::cout << "Accessing elements using iterator: ";
    for (Iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << "Element: " << *it << std::endl; // Should print each element in v
    }

    // Test 23: Modifying elements via iterator (if supported)
    std::cout << "Modifying elements via iterator: ";
    for (Iterator it = v.begin(); it != v.end(); ++it) {
        *it += 5; // Increment each element by 5
    }
    std::cout << "Vector elements after modification: ";
    v.print(std::cout); // Should print modified elements
    std::cout << std::endl;

    return EXIT_SUCCESS;
}
