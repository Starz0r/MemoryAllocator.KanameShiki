#pragma once



namespace KanameShiki {
namespace Lzc {



inline uint32_t Msb(uint32_t v) {
    #if defined(_MSC_VER) && defined(__LZCNT__)
    uint32_t tmp = _lzcnt_u32(v);
    #elif defined(__GNUC__)
    uint32_t tmp = v != 0 ? __builtin_clz(v) : 32;
	#else
    uint32_t tmp = 0;

    if (v == 0)	return 32;

    if (v <= 0x0000FFFF) { tmp += 16; v <<= 16; }
    if (v <= 0x00FFFFFF) { tmp += 8;  v <<= 8; }
    if (v <= 0x0FFFFFFF) { tmp += 4;  v <<= 4; }
    if (v <= 0x3FFFFFFF) { tmp += 2;  v <<= 2; }
    if (v <= 0x7FFFFFFF) { tmp += 1;  v <<= 1; }
    #endif
		
	return 31 - tmp;
}
inline uint64_t Msb(uint64_t v) {
    #if defined(_MSC_VER) && defined(__LZCNT__)
    uint64_t tmp = _lzcnt_u64(v);
    #elif defined(__GNUC__)
    uint64_t tmp = v != 0 ? __builtin_clz(v) : 64;
	#else
    uint64_t tmp = 0;

    if (v == 0)	return 64;
	
	if (v <= 0x000000FF) { tmp += 32; v <<= 32; }
    if (v <= 0x0000FFFF) { tmp += 16; v <<= 16; }
    if (v <= 0x00FFFFFF) { tmp += 8;  v <<= 8; }
    if (v <= 0x0FFFFFFF) { tmp += 4;  v <<= 4; }
    if (v <= 0x3FFFFFFF) { tmp += 2;  v <<= 2; }
    if (v <= 0x7FFFFFFF) { tmp += 1;  v <<= 1; }
    #endif
		
	return 63 - tmp;
}
inline uint32_t Lsb(uint32_t v){ return _tzcnt_u32(v); }
inline uint64_t Lsb(uint64_t v){ return _tzcnt_u64(v); }



}
}