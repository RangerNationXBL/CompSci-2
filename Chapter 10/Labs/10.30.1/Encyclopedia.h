#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book {
public:
    void SetEdition(const std::string& e);
    void SetNumPages(int n);

    std::string GetEdition() const;
    int GetNumPages() const;

    void PrintInfo();

private:
    std::string edition;
    int numPages;
};

#endif
