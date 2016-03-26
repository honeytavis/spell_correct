///
/// @file     Dictionary.cc
/// @author   Tavis(honeytavis@aliyun.com)
/// @date     2016-03-25 18:02
///

#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <fstream>
#include <sstream>

namespace sc {

Dictionary::Dictionary(const std::string& dic) 
{
  std::ifstream ifs(dic); 
  if (!ifs.good()) {
    perror("ifstream"); 
    exit(EXIT_FAILURE); 
  }

/*
  std::pair<std::string, size_t> record("", 0); 
  std::stringstream ss; 
  std::string tmp; 
  while (getline(ifs, ss)) {
    while (ss >> tmp) {
      ss >> tmp; 
      _content.insert(record); 
    }
  }
*/
  
  ifs.close(); 
}

//bool Dictionary::append(const std::string& wordLibs) {}

// std::map<std::string, size_t> _record 

} // end of namespace
