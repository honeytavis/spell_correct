#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <map>

namespace sc {

class Dictionary {
public:
  Dictionary(const std::string& dic, const std::string& wordLibPath);
  void init();
  void append(const std::string& libName); // append content from word libs
  int fileRead(); // copy content from disk to memory
  int fileWrite(); // copy content from memory to disk

private:
  std::string _dic;         // dictionary name with path
  std::string _wordLibPath; // word library location
  std::map<std::string, std::size_t> _content; // dictionary content
};

} // end of namespace
#endif
