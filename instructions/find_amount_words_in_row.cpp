#include "stdio.h"
#include <iostream>


int main(void){
    std::string text {"When in Rome, do as the Romans do."};
    const std::string separators{ " ,;:.\"!?'*\n" };
    unsigned count{};
    size_t start { text.find_first_not_of(separators) };
    while (start != std::string::npos) {
        count++;
        size_t end = text.find_first_of(separators, start + 1);
        if (end == std::string::npos){
            end = text.length();
        }
        start = text.find_first_not_of(separators, end + 1);
    }
    std::cout << "Text contains " << count << " words" << std::endl;

}