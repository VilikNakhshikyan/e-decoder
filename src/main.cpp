#include "decoder/decoder.h"
#include "encoder/encoder.h"
#include <iostream>
#include <string>
int main()
{
    std::string text;
    int count;
    std::cout << "Enter text." << std::endl;
    std::getline(std::cin,text);
    std::cout << "Enter the encoding code." << std::endl;
    std::cin >> count;
    text = encoder(text, count);
    std::cout << "Dncoded text: " << text << std::endl;
    std::cout << "Enter the decoding code." << std::endl;
    std::cin >> count;
    std::cout << "Decoded text: " << decoder(text, count) << std::endl;
}
