#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define BENCH

#define USE_MIMALLOC
//#define USE_RPMALLOC
//#define USE_TBB
//#define USE_DEBUG_MSVC

// TODO...
//#define USE_HOARD
//#define USE_TCMALLOC
//#define USE_JEMALLOC



#if defined(USE_MIMALLOC)
#include <../extern/mimalloc/include/mimalloc.h>
#define CUSTOM_MALLOC  mi_malloc
#define CUSTOM_REALLOC mi_realloc
#define CUSTOM_FREE    mi_free
#define ALLOCATOR      "mi"
#elif defined(USE_RPMALLOC)
#include <../extern/rpmalloc/rpmalloc/rpmalloc.h>
#define CUSTOM_MALLOC  rpmalloc
#define CUSTOM_REALLOC rprealloc
#define CUSTOM_FREE    rpfree
#define ALLOCATOR      "rp"
#elif defined(USE_TBB)
#include <../extern/tbb/include/tbb/scalable_allocator.h>
#define CUSTOM_MALLOC  scalable_malloc
#define CUSTOM_REALLOC scalable_realloc
#define CUSTOM_FREE    scalable_free
#define ALLOCATOR      "tbb"
#elif defined(USE_JEMALLOC)
#include <../extern/jmalloc/jemalloc.h>
#define CUSTOM_MALLOC  je_malloc
#define CUSTOM_REALLOC je_realloc
#define CUSTOM_FREE    je_free
#define ALLOCATOR      "je"
#elif defined(USE_TCMALLOC)
#include <../extern/gperftools/src/windows/gperftools/tcmalloc.h>
#define CUSTOM_MALLOC  tc_malloc
#define CUSTOM_REALLOC tc_realloc
#define CUSTOM_FREE    tc_free
#define ALLOCATOR      "tc"
#elif defined(USE_HOARD)
#include <stdint.h>
void* xxmalloc(size_t size);
void  xxfree(void* p);
void* xxrealloc(void * ptr, size_t sz);
#define CUSTOM_MALLOC  xxmalloc
#define CUSTOM_REALLOC xxrealloc
#define CUSTOM_FREE    xxfree
#define ALLOCATOR      "hd"
#elif defined(USE_DEBUG_MSVC)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define CUSTOM_MALLOC  malloc
#define CUSTOM_REALLOC realloc
#define CUSTOM_FREE    free
#define ALLOCATOR      "debug-msvc"
#else
#include <stdlib.h>
#include <stdbool.h>
#define CUSTOM_MALLOC  malloc
#define CUSTOM_REALLOC realloc
#define CUSTOM_FREE    free
#define ALLOCATOR      "sys"
#endif

#ifndef TESTNAME
#define TESTNAME "test"
#endif

#define _REENTRANT