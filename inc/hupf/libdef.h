#pragma once

#if defined(_MSC_VER) && defined(_WIN32)
  #ifdef LIBHUPF_EXPORTS
    #define LIBHUPF_LIBRARY_INTERFACE __declspec(dllexport)
  #else
    #define LIBHUPF_LIBRARY_INTERFACE __declspec(dllimport)
  #endif
#else
  #define LIBHUPF_LIBRARY_INTERFACE
#endif

