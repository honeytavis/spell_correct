///
/// @file     Dictionary.cc
/// @author   tavis(honeytavis@aliyun.com)
/// @date     2016-03-25 18:02
///

#include "Dictionary.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <dirent.h>

#include <cctype>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define DEBUG 

namespace sc {

Dictionary::Dictionary(const std::string& dic, const std::string& wordLibPath) 
:_dic(dic)
,_wordLibPath(wordLibPath)
{
  std::ifstream ifs(_dic); 
  if (ifs.good()) {
  std::string line; 
    while (getline(ifs, line)) {
      std::stringstream ss; 
      ss << line; 
      std::string tmp; 
      ss >> tmp; 
      std::cout << tmp << ' '; 
      ss >> tmp; 
      std::cout << tmp << '\n'; 
    }
    ifs.close(); 
  } else {
    DIR* pDir = ::opendir(_wordLibPath.c_str()); 
    if (pDir == NULL) {
      perror("opendir()");
      exit(EXIT_FAILURE); 
    }
    std::vector<std::string> wordLibs; 
    struct dirent* pDirInfo = NULL; 
    while ((pDirInfo = readdir(pDir)) != NULL) {
      if (pDirInfo->d_name[0] != '.') {
        std::string tmp; 
        tmp += _wordLibPath; 
        tmp += pDirInfo->d_name; 
        wordLibs.push_back(tmp); 
      }
    }
    closedir(pDir); 
#ifdef DEBUG 
    for (auto i : wordLibs) {
      std::cout << i << '\n'; 
    }
#endif

    for (auto i : wordLibs) {
      std::ifstream ifs(i); 
      std::string tmp; 
      while (ifs >> tmp) {
        bool isWord = true; 
        for (auto c = tmp.begin(); c != tmp.end(); ++c) {
          if (!isalpha(*c)) {
            isWord = false; 
            break; 
          }
        }
        if (isWord) {
          ++_content[tmp]; 
        }
      }
      ifs.close(); 
    }
#ifdef DEBUG
    for (auto i : _content) {
      std::cout << i.first << ": "
                << i.second << '\n'; 
    }
#endif
  } // else
} // Dictionary

void Dictionary::fileWrite()
{
  std::ofstream ofs(_dic); 
  if (ofs.good()) {
    for (auto i : _content) {
      ofs << i.first << ' ' 
          << i.second << '\n'; 
    }
  } else {
    perror("ofstream error"); 
    exit(EXIT_FAILURE); 
  }
}

} // end of namespace
