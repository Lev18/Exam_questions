#include <unordered_map>
#include <iostream>
#include <string>

// hello, dear student, hello dear friends
std::unordered_map<std::string, int> func(const std::string& row) {
  std::unordered_map<std::string, int> words_count{};
  std::string words{};

  for (const char& ch : row) {
    if (ch != ' ' && ch != ',') {
      words += ch;
    } else if(!words.empty()) {
      ++words_count[words];
      words.clear();
    }
  }
  
  if(!words.empty()) {
    ++words_count[words];
  }

  return words_count;
}



int main() {
  std::string str = "hello, dear student, hello dear friends";
  std::unordered_map<std::string, int>woo = func(str);
  for(const auto& t : woo) {
    std::cout << t.first << ":" << t.second << std::endl;
  }

  return 0;
}
