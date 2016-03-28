#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <map>

namespace sc {

class Dictionary {
public:
  // dictionary on disk
  Dictionary(const std::string& dic, const std::string& wordLibPath);
  void fileWrite(); // copy dictionary from memory to disk

private:
  std::string _dic;         // dictionary name
  std::string _wordLibPath; // word library location
  // dictionary content
  std::map<std::string, std::size_t> _content;
};

} // end of namespace
#endif
