#define CATCH_CONFIG_MAIN

#include "tests.hh"

namespace hamming {

std::string make_test_string(int n, std::mt19937 &gen, bool include_x) {
  std::string s;
  std::size_t max_index = 4;
  if (include_x) {
    ++max_index;
  }
  std::uniform_int_distribution<> distrib(0, max_index);
  std::array<char, 20> c{'A', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'Y'};
  s.reserve(n);
  for (int i = 0; i < n; ++i) {
    s.push_back(c[distrib(gen)]);
  }
  return s;
}

std::vector<GeneBlock> make_gene_vector(int n, std::mt19937 &gen,
                                        bool include_x) {
  return from_string(make_test_string(n, gen, include_x));
}

void write_test_fasta(const std::string &filename, int n, std::size_t n_seq,
                      std::mt19937 &gen, bool include_x) {
  std::ofstream fs;
  fs.open(filename);
  for (std::size_t i = 0; i < n_seq; ++i) {
    fs << ">seq" << i << "\n" << make_test_string(n, gen, include_x) << "\n";
  }
  fs.close();
}
} // namespace hamming
