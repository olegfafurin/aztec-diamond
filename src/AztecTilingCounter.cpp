#include "AztecTilingCounter.h"
#include <stdexcept>

int AztecTilingCounter::getDiagonalSize(int k, int n) {
    return (k % 2 == 0) ? n : n + 1;
}

void AztecTilingCounter::exploreTilings(
    int position,
    int d_size,
    int d_next_size,
    int current_mask,
    int next_mask,
    DPTable &results
) {
    if (position >= d_size) {
        results[next_mask]++;
        return;
    }
    if ((current_mask >> position) & 1) {
        exploreTilings(position + 1, d_size, d_next_size, current_mask, next_mask, results);
    } else {
        if (d_size < d_next_size) {
            if (!(next_mask >> position & 1)) {
                exploreTilings(position + 1, d_size, d_next_size, current_mask, next_mask | (1 << position), results);
            }
            exploreTilings(position + 1, d_size, d_next_size, current_mask, next_mask | (1 << (position + 1)), results);
        } else {
            if (position > 0 && !(next_mask >> (position - 1) & 1)) {
                exploreTilings(position + 1, d_size, d_next_size, current_mask, next_mask | (1 << (position - 1)), results);
            }
            if (position < d_size - 1) {
                exploreTilings(position + 1, d_size, d_next_size, current_mask, next_mask | (1 << position), results);
            }
        }
    }
}

DPTable AztecTilingCounter::generateTransitions(int mask, int d_size, int d_next_size) {
    DPTable results;
    exploreTilings(0, d_size, d_next_size, mask, 0, results);
    return results;
}

BigInt AztecTilingCounter::countTilings(int n) {
    if (n < 0) {
        throw std::invalid_argument("Order n must be non-negative.");
    }
    if (n == 0) {
        return 1;
    }

    DPTable current_dp;
    current_dp[0] = 1;

    for (int k = 0; k <= 2 * n; ++k) {
        DPTable next_dp;
        const int m_k = getDiagonalSize(k, n);
        const int m_k_plus_1 = (k < 2 * n) ? getDiagonalSize(k + 1, n) : 0;

        for (const auto &[mask, count]: current_dp) {
            DPTable transitions = generateTransitions(mask, m_k, m_k_plus_1);

            for (const auto &[new_mask, ways]: transitions) {
                next_dp[new_mask] += count * ways;
            }
        }
        current_dp = next_dp;
    }

    return current_dp[0];
}
