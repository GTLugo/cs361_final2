#include "miner.hpp"

namespace gtl {
  // O(1) complexity
  Miner::Miner(std::vector<std::string> args)
      : args_{std::move(args)} {
    if (args_.size() != 2) {
      throw std::runtime_error("Usage: ./mining path_to_input_file");
    }
  }

  // O(2N) complexity
  void Miner::run() {
    // O(1) complexity
    openFile();
    // O(N) complexity
    parseFile();
    // O(N) complexity
    printSubStrings();
  }

  // O(1) complexity
  bool Miner::isAlphabetical(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }

  // O(1) complexity
  void Miner::openFile() {
    file_.open(args_[1]);
    if (!file_.is_open()) {
      throw std::runtime_error("Failed to open file!");
    }
  }

  // O(N) complexity
  void Miner::parseFile() {
    char ch{static_cast<char>(file_.get())}, nextCh{};
    std::stringstream str{};
    if (file_.good()) {
      // O(N) complexity
      while (file_.get(nextCh)) {
        // O(1) complexity
        // Check if the values are in alphabet range and in order
        if ((isAlphabetical(ch) && isAlphabetical(nextCh))
            && (ch == nextCh || (ch + 1) == nextCh)) {
          str << ch;
        } else {
          // Append previous char and then push to str
          str << ch;
          // O(1) complexity
          if (str.str().size() >= 2) {
            subStrings_.push_back(str.str());
          }
          // Clear str to prep for next substring
          str.str(std::string{});
        }
        ch = nextCh;
      }
    }
  }

  // O(N) complexity
  void Miner::printSubStrings() {
    for (const auto& s : subStrings_) {
      std::cout << s << "\n";
    }
  }
}