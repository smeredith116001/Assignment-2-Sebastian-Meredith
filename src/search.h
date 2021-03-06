//
//  search.h
//  
//  Functions for doing linear search and binary search on an
//  arbitrary array.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//  Sebastian Meredith
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

#ifndef search_hpp
#define search_hpp

namespace csi281 {

    // Returns the first location of the found key
    // or -1 if the key is never found
    // Credit to David Kopec:
    template <typename T>
    int linearSearch(T array[], const int length, const T key) {

        for (int i = 0; i < length; i++) {
            if (array[i] == key) {
                return i;
            }
        }
        return-1;
    };

    // Returns the first location of the found key
    // or -1 if the key is never found; assumes a sorted array
    // Credit to David Kopec:
    template <typename T>
    int binarySearch(T array[], const int length, const T key) {
        int low = 0;
        int high = length - 1;;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (key < array[middle]) high = middle - 1;
            else if (key > array[middle]) low = middle + 1;
            else return middle;
        }
        return -1;
    }
};



#endif /* search_hpp */
