#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <cstddef>

class Dictionary {
public:
  Dictionary(const std::string& fileName);  // build dictionary
  bool append(const std::string& fileName); // append record to dictionary

private:
  std::string _fileName;                 // dictionary name
  std::map<std::string, size_t> _record; // dictionary content
}; 

#endif
