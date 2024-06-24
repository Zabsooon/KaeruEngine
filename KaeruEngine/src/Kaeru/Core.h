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

// Unsigned int types
typedef unsigned char       ui8;
typedef unsigned short      ui16;
typedef unsigned int        ui32;
typedef unsigned long long  ui64;

// Signed int types
typedef signed char         i8;
typedef signed short        i16;
typedef signed int          i32;
typedef signed long long    i64;

// Floating point types
typedef float               f32;
typedef double              f64;

// Boolean types
typedef int                 b32;
typedef char                b8;

// Define STATIC_ASSERT depending on compiler
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(ui8) == 1, "Expected ui8 to be 1 byte");
STATIC_ASSERT(sizeof(ui16) == 2, "Expected ui16 to be 2 bytes");
STATIC_ASSERT(sizeof(ui32) == 4, "Expected ui32 to be 4 bytes");
STATIC_ASSERT(sizeof(ui64) == 8, "Expected ui64 to be 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes");

STATIC_ASSERT(sizeof(b32) == 4, "Expected b32 to be 4 bytes");
STATIC_ASSERT(sizeof(b8) == 1, "Expected b8 to be 1 byte");
