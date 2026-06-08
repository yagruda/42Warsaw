#include "Serializer.hpp"

#include <iostream>

int main() {
  Data GameSerializer = {10, true};

  std::cout << "Original Data address: " << &GameSerializer << std::endl;
  std::cout << "Original Data values - val1: " << GameSerializer.data_int << ", val2: " << GameSerializer.data_bool << std::endl;

  uintptr_t serialized = Serializer::serialize(&GameSerializer);
  std::cout << "Serialized Data (uintptr_t): " << serialized << std::endl;

  Data* deserialized = Serializer::deserialize(serialized);
  std::cout << "Deserialized Data address: " << deserialized << std::endl;
  std::cout << "Deserialized Data values - val1: " << deserialized->data_int << ", val2: " << deserialized->data_bool << std::endl;

  if (deserialized == &GameSerializer) {
      std::cout << "SUCCESS: The pointers match!" << std::endl;
  } else {
      std::cout << "FAILURE: The pointers do not match!" << std::endl;
  }

  return 0;
}