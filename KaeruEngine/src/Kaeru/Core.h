#pragma once

#ifdef _WIN32
    #ifdef ENGINE_EXPORTS
        #define KAERU_API __declspec(dllexport)
    #else
        #define KAERU_API __declspec(dllimport)
    #endif
#else
    #define KAERU_API
#endif
