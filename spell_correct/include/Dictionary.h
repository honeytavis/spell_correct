#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <cstddef>
#include <string>
#include <map>

namespace sc {

class Dictionary {
public:
  Dictionary(const std::string& dic); // dictionary on disk
  bool append(const std::string& wordLibs); // append record to dictionary

private:
  std::map<std::string, size_t> _content; // dictionary content
}; 

} // end of namespace
#endif
