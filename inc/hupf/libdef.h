#pragma once

//ined(_MSC_VER) && 

#if defined(_WIN32) || defined(_WIN64)
  #ifdef LIBHUPF_EXPORTS
    #define LIBHUPF_LIBRARY_INTERFACE __declspec(dllexport)
  #else
    #define LIBHUPF_LIBRARY_INTERFACE __declspec(dllimport)
  #endif
#else
  #ifdef LIBHUPF_EXPORTS
    #define LIBHUPF_LIBRARY_INTERFACE __attribute__((__visibility__("default")))
  #else 
    #define LIBHUPF_LIBRARY_INTERFACE
#endif
