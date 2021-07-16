#ifndef _HAMMING_TYPES_HH
#define _HAMMING_TYPES_HH

#include<array>
#include<cstdint>
#include<string>
#include<vector>

namespace hamming {

using DistIntType = uint8_t;

struct DataSet
{
  DataSet(std::vector<std::string>&, bool include_x = false, bool clear_input_data = false, std::vector<std::size_t>&& indices = {});
  DataSet(const std::string&);
  DataSet(std::vector<DistIntType>&& distances);
  void dump(const std::string&);
  void dump_lower_triangular(const std::string&);
  void dump_sequence_indices(const std::string&);
  int operator[](const std::array<std::size_t, 2>&) const;

  std::size_t nsamples;
  std::vector<DistIntType> result;
  std::vector<std::size_t> sequence_indices{};
};

}

#endif
