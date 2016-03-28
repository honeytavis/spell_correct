///
/// @file     Configuration.cc
/// @author   Tavis(honeytavis@aliyun.com)
/// @date     2016-03-25 18:04
///

#include "Config.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <iostream>
#include <fstream>

namespace sc {

Configuration::Configuration(const std::string& conf)
{
  std::ifstream ifs(conf); 
  if (!ifs.good()) {
    perror("ifstream"); 
    exit(EXIT_FAILURE); 
  }

  std::string wordLibsPath; 
  if (getline(ifs, wordLibsPath) < 0) {
    perror("ifstream"); 
    exit(EXIT_FAILURE); 
  }

  ifs.close(); 

  DIR* pDir = ::opendir(wordLibsPath.c_str());
  if (pDir == NULL) {
    perror("opendir()"); 
    exit(EXIT_FAILURE);
  }

  struct dirent* pDirInfo = NULL; 
  while ((pDirInfo = readdir(pDir)) != NULL) {
    //if (strcmp(pDirInfo->d_name, ".") && strcmp(pDirInfo->d_name, "..")) {
    if (pDirInfo->d_name[0] != '.') {
      std::string wordLib(wordLibsPath); 
      wordLib += pDirInfo->d_name; 
      _wordLibs.push_back(wordLib); 
    }
  }

  closedir(pDir); 

  for (auto i : _wordLibs) {
    std::cout << i << '\n';
  } 
}

} // end of namespace
