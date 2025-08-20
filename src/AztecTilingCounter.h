#ifndef AZTEC_TILING_COUNTER_H
#define AZTEC_TILING_COUNTER_H

#include <map>
#include <boost/multiprecision/cpp_int.hpp>

// Define a type for the large integers required for counting tilings.
using BigInt = boost::multiprecision::cpp_int;

// The DPTable stores the core of the dynamic programming state:
// a map from a binary mask to the number of ways to achieve that state.
using DPTable = std::map<int, BigInt>;

/**
 * @class AztecTilingCounter
 * @brief Calculates the number of domino tilings of an Aztec Diamond of order n.
 *
 * This class implements a dynamic programming approach using a transfer matrix method.
 * It sweeps through the diamond one diagonal at a time. The state transition
 * is non-deterministic and is handled by the generateTransitions function.
 */
class AztecTilingCounter {
public:
    /**
     * @brief Calculates the number of domino tilings for an Aztec Diamond of order n.
     * @param n The order of the Aztec Diamond. Must be a non-negative integer.
     * @return The total number of valid domino tilings.
     */
    BigInt countTilings(int n);

private:
    /**
     * @brief Gets the size of the k-th diagonal for an Aztec Diamond of order n.
     * @param k The index of the diagonal (from 0 to 2n).
     * @param n The order of the Aztec Diamond.
     * @return The size of the diagonal (either n or n+1).
     */
    int getDiagonalSize(int k, int n);

    /**
     * @brief Generates all possible next-level masks from a single current-level mask.
     *
     * This function encapsulates the core combinatorial logic. Given the constraints
     * of the incoming `mask`, it finds all valid ways to tile the free cells of the
     * current diagonal and returns a map of the resulting `new_mask`s for the next diagonal and the number
     * of ways each can be formed.
     *
     * @param mask The incoming mask for the current diagonal.
     * @param d_size The size of the current diagonal.
     * @param d_next_size The size of the next diagonal.
     * @return A DPTable mapping each possible new_mask to the number of ways it can be reached.
     */
    DPTable generateTransitions(int mask, int d_size, int d_next_size);
    /**
     * @brief The recursive function that explores all valid tilings of a diagonal.
     *
     * @param position The current cell index on the diagonal being tiled.
     * @param d_size The size of the current diagonal.
     * @param d_next_size The size of the next diagonal.
     * @param current_mask The incoming mask defining which cells are already covered.
     * @param next_mask The outgoing mask being built by placing dominoes to the next diagonal.
     * @param results The map where the final generated masks and their counts are stored.
     */
    void exploreTilings(
        int position,
        int d_size,
        int d_next_size,
        int current_mask,
        int next_mask,
        DPTable& results
    );
};

#endif // AZTEC_TILING_COUNTER_H