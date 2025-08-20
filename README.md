# Aztec Diamond

This project explores the structure and features of a specific combinatorial structure known as Aztec Diamond.

## The Aztec Diamond structure

[Aztec Diamond](https://en.wikipedia.org/wiki/Aztec_diamond) (AD) of order `n` is a specific diamond-shaped region on a square grid, composed of `2n(n+1)` unit squares.


## Number of domino tilings

The number of complete domino tilings of an `AD(n)` is known from combinatorics and is `2^(n(n+1)/2)`.

This program calculates the number of tilings manually. We employ a dynamic programming approach.

The core idea is to sweep through the diamond one diagonal at a time. 
The state of the calculation (`DP[mask]`) represents the number of ways to tile the portion of the diamond behind the sweep line, 
where the `mask` is a bitmask to represent dominos protruding from the sweeping diagonal line boundary at a given step.

## Building and Running

This is a CMake project. The Boost library is a requirement due to the need in BigInt implementation.

### Prerequisites

- A C++ compiler
- CMake (version 3.10 or higher)
- `boost::multiprecision` library for big integer implementation

### Build Steps

1.  **Configure with CMake:** Create a build directory and run CMake from it.

    ```bash
    mkdir build
    cd build
    cmake ..
    ```

2.  **Compile:** Run `make` from within the build directory.

    ```bash
    make
    ```

3.  **Run:** Execute the compiled target.

    ```bash
    ./aztec
    ```
