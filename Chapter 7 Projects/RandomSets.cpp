#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() {
    const int setSize = 10;
    const int numSets = 30;  // You can adjust the number of sets as needed
    const int lowerBound = 50;
    const int upperBound = 100;

    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int setIndex = 1; setIndex <= numSets; ++setIndex) {
        std::cout << "Set " << setIndex << ":" << std::endl;

        int sum = 0;

        for (int i = 0; i < setSize; ++i) {
            int randomNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound;
            std::cout << std::setw(4) << randomNumber << " ";
            sum += randomNumber;
        }

        double average = static_cast<double>(sum) / setSize;

        std::cout << "\nSum: " << sum << "\nAverage: " << std::fixed << std::setprecision(2) << average << "\n\n";
    }

    return 0;
}
