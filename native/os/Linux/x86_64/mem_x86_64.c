#include <c/mem.h>
#include <c/app.h>
#define _GNU_SOURCE
#include <emmintrin.h>
#include <sys/mman.h>


extern void *memcpy(void*, const void*, size_t);

/////////////////////////////////////////////
//////// Memory managment functions ///////// 
///////////////////////////////////////////// 

/*
void fast_copy(void *dst, const void *src, size_t n) {
#if defined(__AVX512F__)
    // 64 
    for (size_t i = 0; i < n / 64; ++i) {
        __m512i data = _mm512_loadu_si512((__m512i*)((char*)src + i * 64));
        _mm512_storeu_si512((__m512i*)((char*)dst + i * 64), data);
    }
#elif defined(__AVX2__)
    // 32
    for (size_t i = 0; i < n / 32; ++i) {
        __m256i data = _mm256_loadu_si256((__m256i*)((char*)src + i * 32));
        _mm256_storeu_si256((__m256i*)((char*)dst + i * 32), data);
    }
#elif defined(__SSE2__)
    // 16 
    for (size_t i = 0; i < n / 16; ++i) {
        __m128i data = _mm_loadu_si128((__m128i*)((char*)src + i * 16));
        _mm_storeu_si128((__m128i*)((char*)dst + i * 16), data);
    }
#else
    // 
#endif
}
*/

// TODO: FINISH IT.
err_t mem_copy(memory_t* dest, const memory_t src) {



    if (dest->allocated < src.used)  {
        
    }

    if (min_size > 64) {

    }

    if (min_size > 32) {

    }

    if (min_size > 16) {
        
    }

    memcpy(dest->data, dest)
}

err_t mem_set(memory_t* mem, u8_t data) {

}

err_t mem_move(memory_t* mem1, memory_t* mem2) {

}

ssize_t mem_compare(memory_t mem1, memory_t mem2) {

}
