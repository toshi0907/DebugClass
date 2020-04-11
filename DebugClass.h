#pragma once
#include <bits/stdc++.h>

class DebugClass {
  const int iWidthVar = 10;
  const int iWidthBar = 100;
  const int iWidthFilename = 12;
  const int iWidthLine = 5;

public:
  DebugClass() {}

  // for values
  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  void debug(T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5) {
    std::cerr << "\x1b[33m" << std::setw(iWidthVar) << arg1 << " ";
    std::cerr << "\x1b[31m" << std::setw(iWidthVar) << arg2 << " ";
    std::cerr << "\x1b[33m" << std::setw(iWidthVar) << arg3 << " ";
    std::cerr << "\x1b[31m" << std::setw(iWidthVar) << arg4 << " ";
    std::cerr << "\x1b[33m" << std::setw(iWidthVar) << arg5 << " ";
    std::cerr << "\x1b[39m" << std::endl;
  }

  template <typename T1, typename T2, typename T3, typename T4>
  void debug(T1 arg1, T2 arg2, T3 arg3, T4 arg4) {
    debug(arg1, arg2, arg3, arg4, "");
  }

  template <typename T1, typename T2, typename T3>
  void debug(T1 arg1, T2 arg2, T3 arg3) {
    debug(arg1, arg2, arg3, "");
  }

  template <typename T1, typename T2> void debug(T1 arg1, T2 arg2) {
    debug(arg1, arg2, "");
  }

  template <typename T1> void debug(T1 arg1) { debug(arg1, ""); }

  // with filename & line
  template <typename T1, typename T2, typename T3, typename T4, typename T5>
  void debugFl(const char *pcFile, int iLine, T1 arg1, T2 arg2, T3 arg3,
               T4 arg4, T5 arg5) {
    std::cerr << "\x1b[31m" << std::setw(iWidthFilename) << pcFile;
    std::cerr << " [" << std::setw(iWidthLine) << iLine << "]";

    debug(arg1, arg2, arg3, arg4, arg5);
  }

  template <typename T1, typename T2, typename T3, typename T4>
  void debugFl(const char *pcFile, int iLine, T1 arg1, T2 arg2, T3 arg3,
               T4 arg4) {
    debugFl(pcFile, iLine, arg1, arg2, arg3, arg4, "");
  }

  template <typename T1, typename T2, typename T3>
  void debugFl(const char *pcFile, int iLine, T1 arg1, T2 arg2, T3 arg3) {
    debugFl(pcFile, iLine, arg1, arg2, arg3, "");
  }

  template <typename T1, typename T2>
  void debugFl(const char *pcFile, int iLine, T1 arg1, T2 arg2) {
    debugFl(pcFile, iLine, arg1, arg2, "");
  }

  template <typename T1> void debugFl(const char *pcFile, int iLine, T1 arg1) {
    debugFl(pcFile, iLine, arg1, "");
  }

  template <typename T1, typename T2, typename T3, typename T4>
  void debugName(const char *pcName1, T1 arg1, const char *pcName2, T2 arg2,
                 const char *pcName3, T3 arg3, const char *pcName4, T4 arg4) {
    if (strlen(pcName1) != 0)
      std::cerr << "\x1b[33m" << pcName1 << "[" << std::setw(iWidthVar) << arg1
                << "] ";
    if (strlen(pcName2) != 0)
      std::cerr << "\x1b[31m" << pcName2 << "[" << std::setw(iWidthVar) << arg2
                << "] ";
    if (strlen(pcName3) != 0)
      std::cerr << "\x1b[33m" << pcName3 << "[" << std::setw(iWidthVar) << arg3
                << "] ";
    if (strlen(pcName4) != 0)
      std::cerr << "\x1b[31m" << pcName4 << "[" << std::setw(iWidthVar) << arg4
                << "] ";
    std::cerr << "\x1b[39m" << std::endl;
  }

  template <typename T1, typename T2, typename T3>
  void debugName(const char *pcName1, T1 arg1, const char *pcName2, T2 arg2,
                 const char *pcName3, T3 arg3) {
    debugName(pcName1, arg1, pcName2, arg2, pcName3, arg3, "", "");
  }

  template <typename T1, typename T2>
  void debugName(const char *pcName1, T1 arg1, const char *pcName2, T2 arg2) {
    debugName(pcName1, arg1, pcName2, arg2, "", "");
  }

  template <typename T1> void debugName(const char *pcName1, T1 arg1) {
    debugName(pcName1, arg1, "", "");
  }

  void debugBar(double dPercent) {
    std::cerr << std::setw(iWidthVar) << dPercent * 100 << "%";
    for (int i = 0; i < iWidthBar; ++i) {
      if (i < dPercent * iWidthBar)
        std::cerr << "=";
      else
        std::cerr << "_";
    }
    std::cerr << std::endl;
  }
};

static DebugClass dbg;

#define _DD dbg.debug
#define _DF(...) dbg.debugFl(__FILE__, __LINE__, __VA_ARGS__)
#define _D1(arg1) dbg.debugName(#arg1, arg1)
#define _D2(arg1, arg2) dbg.debugName(#arg1, arg1, #arg2, arg2)
#define _D3(arg1, arg2, arg3)                                                  \
  dbg.debugName(#arg1, arg1, #arg2, arg2, #arg3, arg3)
#define _D4(arg1, arg2, arg3, arg4)                                            \
  dbg.debugName(#arg1, arg1, #arg2, arg2, #arg3, arg3, #arg4, arg4)
#define _DB dbg.debugBar
