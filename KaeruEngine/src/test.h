#ifndef MYLIB_H
#define MYLIB_H

#ifdef _WIN32
  #ifdef KAERU_EXPORTS
    #define KAERU_API __declspec(dllexport)
  #else
    #define KAERU_API __declspec(dllimport)
  #endif
#else
  #define KAERU_API
#endif

extern "C" {
    KAERU_API void hello();
}

#endif // MYLIB_H

