//
//  util.cpp
//
//  Implementation of Timing Tests
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#include "util.h"
#include "search.h"
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

namespace csi281 {
    
    // Returns a new int array of *length* and filled
    // with numbers between *min* and *max*
    // Suggest using the facilities in STL <random>
    int *randomIntArray(const int length, const int min, const int max) {
        // YOUR CODE HERE
        
        int *randArray = new int[length];
        for (int i = 0; i < length; i++)
        {
            randArray[i] = rand() %  max + min;
        };
        
        return randArray;
    }
    
    // Finds the speed of linear versus binary search
    // in a random int array of *length* size
    // by running *numTests* and averaging them
    // Returns a pair indicating the average time it took
    // to do linear search and binary search in nanoseconds
    // Linear search should be first in the pair, and binary search
    // should be second
    //
    // Suggest using the facilities in STL <chrono>
    // For example, you can start a timer using
    // using namespace std::chrono;
    // auto start = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
    // and stop a timer using
    // auto end = duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
    // start, end will be results in nanoseconds
    pair<nanoseconds, nanoseconds> arraySearchSpeed(const int length, const int numTests) {
        int *testArray = randomIntArray(length, 0, length);
        int *testKeys = randomIntArray(numTests, 0, length);
        using namespace std::chrono;
        auto start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        // Do numTests linear searches and find the average time
        // Put the result in a variable linearSearchSpee
        
        
        for (int i = 0; i < numTests; i++)
        {
            linearSearch(testArray, length, testKeys[i]);
        }
        auto end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        auto linearSearchSpeed = ((end-start)/numTests);
        // YOUR CODE HERE
        start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        // Do numTests binary searches and find the average time
        // Put the result in a variable binarySearchSpeed
        sort(testArray, testArray + length);
        for (int i = 0; i < numTests; i++)
        {
            binarySearch(testArray, length, testKeys[i]);
        }
        // YOUR CODE HERE
        end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
        
        int binarySearchSpeed = ((end - start) / numTests);
        
        
        delete testArray;
        delete testKeys;
        
        return pair<nanoseconds, nanoseconds>(linearSearchSpeed, binarySearchSpeed);
    }
}
