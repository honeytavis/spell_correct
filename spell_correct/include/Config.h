#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <vector>
#include <string>

namespace sc {

class Configuration {
public:
  Configuration(const std::string& conf); // config file name 

private:
  std::string _dic;                   // dictionary file name
  std::vector<std::string> _wordLibs; // word library file name
}; 

} // end of namespace
#endif
