///
/// @file     main.cc
/// @author   Tavis(honeytavis@aliyun.com)
/// @date     2016-03-25 17:59
///

#include "Config.h"
#include "Dictionary.h"
#include <iostream>

int main()
{
  sc::Config myConf("./config/config"); 
  sc::Dictionary myDic(myConf.getDic(), myConf.getWordLibs());
  myDic.fileWrite(); 

  return 0; 
}
