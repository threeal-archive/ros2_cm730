#ifndef CM730CONTROLLER__DATAUTIL_HPP_
#define CM730CONTROLLER__DATAUTIL_HPP_

#include "cm730controller/cm730table.hpp"

#include <cstdint>
#include <vector>

namespace cm730controller {

  class DataUtil {
  public:
    template<typename TEnum>
    static uint8_t getByte(std::vector<uint8_t> const& data, TEnum addr, TEnum startAddr) {
      return data[uint8_t(addr) - uint8_t(startAddr)];
    }

    template<typename TEnum>
    static uint16_t getWord(std::vector<uint8_t> const& data, TEnum addr, TEnum startAddr) {
      auto addr_ = uint8_t(addr) - uint8_t(startAddr);
      return uint16_t{data[addr_]} | (uint16_t{data[addr_ + 1]} << 8);
    }
  };

}  // namespace cm730controller

#endif  // CM730CONTROLLER__DATAUTIL_HPP_
