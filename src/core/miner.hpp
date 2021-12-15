#pragma once

#include <utility>

namespace gtl {
  class Miner {
  public:
    // O(1) complexity
    explicit Miner(std::vector<std::string> args);
    ~Miner() = default;

    // O(2N) complexity
    void run();
  private:
    std::vector<std::string> args_;

    std::vector<std::string> subStrings_;
    std::ifstream file_;

    static bool isAlphabetical(char c);

    // O(1) complexity
    void openFile();
    // O(N) complexity
    void parseFile();
    // O(N) complexity
    void printSubStrings();
  };
}