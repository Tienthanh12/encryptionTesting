#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// Function to convert ASCII string to array of bits
void asciiToBitArray(const std::string& asciiString, bool bitArray[]) {
    int index = 0;
    
    // Convert each character to its binary representation
    for (char c : asciiString) {
        // Convert character to ASCII code
        int asciiValue = static_cast<int>(c);
        
        // Convert ASCII code to binary
        std::bitset<7> binary(asciiValue); // ASCII uses 7 bits
        
        // Append each bit to the bit array
        for (int i = 0; i < 7; ++i) {
            bitArray[index++] = binary[i];
        }
    }
}

int main() {
    // Input ASCII string
    std::string input = "HELLO";
    const int arraySize = input.length() * 7; // Each ASCII character has 7 bits
    
    // Array to store bits
    bool bitArray[arraySize];
    
    // Convert ASCII string to array of bits
    asciiToBitArray(input, bitArray);
    
    // Output the result
    std::cout << "ASCII string: " << input << std::endl;
    std::cout << "Bit array: ";
    for (int i = 0; i < arraySize; ++i) {
        std::cout << bitArray[i];
    }
    std::cout << std::endl;
    
    return 0;
}
