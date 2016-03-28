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
{} 

void Dictionary::init()
{
  int ret = fileRead(); 
  if (ret < 0) {
    DIR* pDir = opendir(_wordLibPath.c_str()); 
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

    for (auto i : wordLibs) {
      append(i); 
    }
  } 

#ifdef DEBUG
  for (auto i : _content) {
    std::cout << i.first << ": "
              << i.second << '\n'; 
  }
#endif
}

void Dictionary::append(const std::string& wordLib)
{
  std::ifstream ifs(wordLib); 
  std::string word; 
  while (ifs >> word) {
    bool candidate = true; 
    for (auto c = word.begin(); c != word.end(); ++c) {
      if (!isalpha(*c)) {
        candidate = false; 
        break; 
      }
    }
    if (candidate) {
      ++_content[word]; 
    }
  }
  ifs.close(); 
}

int Dictionary::fileRead()
{
  std::ifstream ifs(_dic); 
  if (!ifs.good()) {
    return -1; 
  }

  std::string line; 
  std::pair<std::string, std::size_t> record; 
  while (getline(ifs, line)) {
    std::stringstream ss(line); 
    ss >> record.first; 
    ss >> line; 
    record.second = static_cast<size_t>(atoi(line.c_str()));
    _content.insert(record); 
  }
  ifs.close(); 

  return 0; 
}

int Dictionary::fileWrite()
{
  std::ofstream ofs(_dic); 
  if (!ofs.good()) {
    return -1; 
  } 

  for (auto i : _content) {
    ofs << i.first << ' ' 
        << i.second << '\n'; 
  }

  return 0; 
}

} // end of namespace
