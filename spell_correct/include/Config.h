#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include <string>

namespace sc {

class Config {
public:
  Config(const std::string& config); // config file name 
  std::string getDic();
  std::string getWordLibPath(); 

private:
  std::vector<std::string> _etc;
  // _etc[0]: Dictionary name with path
  // _etc[1]: word library location
}; 

} // end of namespace
#endif
