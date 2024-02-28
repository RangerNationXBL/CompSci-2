#include "Encyclopedia.h"
#include <iostream>

// Mutator functions
void Encyclopedia::SetEdition(const std::string& e) {
    edition = e;
}

void Encyclopedia::SetNumPages(int n) {
    numPages = n;
}

// Accessor functions
std::string Encyclopedia::GetEdition() const {
    return edition;
}

int Encyclopedia::GetNumPages() const {
    return numPages;
}

// Override PrintInfo function
void Encyclopedia::PrintInfo() {
    // Call base class PrintInfo
    Book::PrintInfo();
    // Print additional information
    std::cout << "   Edition: " << edition << std::endl;
    std::cout << "   Number of Pages: " << numPages << std::endl;
}
