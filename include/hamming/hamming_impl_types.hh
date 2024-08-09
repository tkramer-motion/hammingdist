#pragma once

#include <array>
#include <vector>
#include <cstdint>

namespace hamming {

// 20-bit representation of gene:
using GeneBlock = std::uint64_t;
using SparseData = std::vector<std::size_t>;
constexpr std::size_t n_bits_per_gene{20};
constexpr GeneBlock mask_gene0{0xFFFFF};
constexpr GeneBlock mask_gene1{0xFFFFF00000};

} // namespace hamming
