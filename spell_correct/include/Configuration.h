#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class Configuration {
public:
  Configuration(const std::string& pathName); // word library path name

private:
  std::vector<std::string> _fileNames; // word library file Names
}; 

#endif
