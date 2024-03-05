#ifndef PUZZLETEST_H
#define PUZZLETEST_H

#include "Hanoi.h"
#include <cassert>
#include <chrono>

class PuzzleTest {
public:
    void runTests() {
        measureTime(&PuzzleTest::testMoveSingleDisk);
        measureTime(&PuzzleTest::testMoveEntireTower);
        measureTime(&PuzzleTest::testMoveInvalidDisk);
        measureTime(&PuzzleTest::testPrintEmptyTower);
        measureTime(&PuzzleTest::testPrintFullTower);
    }

private:
    void measureTime(void (PuzzleTest::*testFunc)()) {
        auto start = std::chrono::high_resolution_clock::now();
        (this->*testFunc)(); // Call the specified test function
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "Duration: " << duration.count() << " microseconds\n";
    }

    void testMoveSingleDisk() {
        auto start = std::chrono::high_resolution_clock::now();
        Hanoi puzzle(3); // Create a puzzle with 3 disks
        puzzle.move_single_disk(0, 1); // Move a disk from tower 0 to tower 1
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        assert(puzzle.getTower(0).size() == 2); // Tower 0 should have 2 disks remaining
        assert(puzzle.getTower(1).size() == 1); // Tower 1 should have 1 disk added
        std::cout << "testMoveSingleDisk Duration: " << duration.count() << " microseconds\n";
    }

    void testMoveEntireTower() {
        auto start = std::chrono::high_resolution_clock::now();
        Hanoi puzzle(3); // Create a puzzle with 3 disks
        puzzle.move(3, 0, 2); // Move the entire tower from tower 0 to tower 2
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        assert(puzzle.getTower(0).empty()); // Tower 0 should be empty
        assert(puzzle.getTower(2).size() == 3); // Tower 2 should have all 3 disks
        std::cout << "testMoveEntireTower Duration: " << duration.count() << " microseconds\n";
    }

    void testMoveInvalidDisk() {
        auto start = std::chrono::high_resolution_clock::now();
        Hanoi puzzle(3); // Create a puzzle with 3 disks
        // Attempt to move a disk from an empty tower
        puzzle.move_single_disk(2, 1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        assert(puzzle.getTower(2).empty()); // No disk should be moved
        assert(puzzle.getTower(1).empty()); // Target tower should still be empty
        std::cout << "testMoveInvalidDisk Duration: " << duration.count() << " microseconds\n";
    }

    void testPrintEmptyTower() {
        auto start = std::chrono::high_resolution_clock::now();
        Hanoi puzzle(3); // Create a puzzle with 3 disks
        puzzle.print(); // Print the tower configuration
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        std::cout << "testPrintEmptyTower Duration: " << duration.count() << " microseconds\n";
        // No disk should be printed in any tower
        // (assertions here may vary depending on print() implementation)
    }

    void testPrintFullTower() {
        auto start = std::chrono::high_resolution_clock::now();
        Hanoi puzzle(3); // Create a puzzle with 3 disks
        puzzle.move(3, 0, 2); // Move the entire tower from tower 0 to tower 2
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        puzzle.print(); // Print the tower configuration
        std::cout << "testPrintFullTower Duration: " << duration.count() << " microseconds\n";
        // All disks should be printed in the target tower
        // (assertions here may vary depending on print() implementation)
    }

    // Add more test cases for other methods
};

#endif /* PUZZLETEST_H */
