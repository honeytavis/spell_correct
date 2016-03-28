///
/// @file     Config.cc
/// @author   Tavis(honeytavis@aliyun.com)
/// @date     2016-03-25 18:04
///

#include "Config.h"

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <fstream>

//#define DEBUG

namespace sc {

Config::Config(const std::string& conf)
{
  std::ifstream ifs(conf); 
  if (!ifs.good()) {
    perror("ifstream"); 
    exit(EXIT_FAILURE); 
  }
  std::string tmp; 
  while (getline(ifs, tmp)) {
    _etc.push_back(tmp); 
  }
  ifs.close(); 

#ifdef DEBUG
  std::cout << '\n'; 
  for (auto i : _etc) {
    std::cout << i << '\n'; 
  }
  std::cout << '\n'; 
#endif
}

std::string Config::getDic()
{
  return _etc[0]; 
}

std::string Config::getWordLibPath()
{
  return _etc[1]; 
}

} // end of namespace
