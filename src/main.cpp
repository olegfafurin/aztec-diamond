#include <iostream>
#include "AztecTilingCounter.h"

int main() {
    AztecTilingCounter counter;

    std::cout << "Aztec Diamond Tiling Counter" << std::endl;
    std::cout << "========================================" << std::endl;

    for (int n = 1; n <= 10; ++n) {
        try {
            BigInt result = counter.countTilings(n);
            std::cout << "Order n=" << n << ": " << result << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "An error occurred for n=" << n << ": " << e.what() << std::endl;
        }
    }
    return 0;
}