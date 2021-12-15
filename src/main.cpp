#include "core/miner.hpp"

// O(3N) complexity
int main(const int argc, const char* argv[]) {
  try {
    // Convert args to more convenient format
    std::vector<std::string> args(argc);
    // O(N) complexity
    for (int i = 0; i < argc; ++i) {
      args[i] = argv[i];
    }

    // O(1) complexity
    gtl::Miner miner{args};
    // O(2N) complexity
    miner.run();
  } catch (const std::exception& e) {
    std::cerr << e.what() << "\n";
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}