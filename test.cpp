#include "DebugClass.h"

int main() {
  short sTest = 12;
  int iTest = 999;
  double dTest = 1.23;
  std::string strTest = "test";
  const char *pcTest = __FILE__;

  //  number only
  for (int i = 0; i < 5; ++i)
    _DD(rand() % 10000, rand() % 10000, rand() % 10000, rand() % 10000);

  // number with name
  for (int i = 0; i < 3; ++i)
    _D3(rand() % 10000, rand() % 10000, rand() % 10000);
  for (int i = 0; i < 3; ++i)
    _D4(rand() % 10000, rand() % 10000, rand() % 10000, rand() % 10000);

  // number with filename and line number
  _DF(1, 2, 3, 4);

  // databar
  for (int i = 0; i < 5; ++i)
    _DB((double)(rand() % 1000) / 1000.0);

  // csv
  for (int i = 0; i < 5; ++i)
    _DCSV(rand() % 10000, rand() % 10000, rand() % 10000, rand() % 10000);

  return 0;
}
