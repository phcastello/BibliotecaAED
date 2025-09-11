#pragma once
// Visibilidade de símbolos (útil quando futuramente houver partes compiladas)
#if defined(_WIN32) || defined(_WIN64)
  #if defined(DATASTRUCTLIB_BUILDING_LIBRARY)
    #define DSL_API __declspec(dllexport)
  #else
    #define DSL_API __declspec(dllimport)
  #endif
#else
  #define DSL_API __attribute__((visibility("default")))
#endif
