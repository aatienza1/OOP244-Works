/***********************************************************************
// OOP244 Workshop # 10
//
// Version 1.0
// Date: 2023/11/25
// Author: Alicia Atienza
// Description:
//
// Revision History
// -----------------------------------------------------------
// Name: Alicia Atienza           Date:11/30/2023            Reason
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H
namespace sdds {
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType& key, size_t size) {

        // Dynamic array of int
        int* indices = new int[size + 1]; 
        size_t indexCount = 0;

        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                // store the indices
                indices[indexCount++] = static_cast<int>(i); 
            }
        }


        // No key
        if (indexCount == 0) {
            indices[indexCount++] = -1; 
        }
        else {
            indices[indexCount] = -1; 
        }

        return indices;
    }
    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int* indices) {
        std::cout << title << std::endl;

        // If indices are good
        if (indices != nullptr && indices[0] != -1) {

            // pwint it
            for (int i = 0; indices[i] != -1; ++i) {
                std::cout << array[indices[i]];

                if (indices[i + 1] != -1) {
                    std::cout << ", ";
                }
            }
        }
        else {
            std::cout << "Empty Selection";
        }

        std::cout << std::endl;
    }
}
#endif // end selection