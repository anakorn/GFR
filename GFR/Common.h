#ifndef GFR_COMMON_H
#define GFR_COMMON_H

#include <assert.h>
#include <stdint.h>

#pragma region Doom 3 BFG Edition GPL Source Code: https://github.com/id-Software/DOOM-3-BFG
template<bool> struct compile_time_assert_failed;
template<> struct compile_time_assert_failed<true> {};
template<int x> struct compile_time_assert_test {};
#define compile_time_assert_join2( a, b )	a##b
#define compile_time_assert_join( a, b )	compile_time_assert_join2(a,b)
#define compile_time_assert( x )			typedef compile_time_assert_test<sizeof(compile_time_assert_failed<(bool)(x)>)> compile_time_assert_join(compile_time_assert_typedef_, __LINE__)
#define assert_sizeof( type, size )			compile_time_assert( sizeof( type ) == size )
#pragma endregion

typedef int8_t		s8;
typedef int16_t		s16;
typedef int32_t		s32;
typedef int64_t		s64;
typedef uint8_t		u8;
typedef uint16_t	u16;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef float		f32;
typedef double		f64;

assert_sizeof( f32,	4 );
assert_sizeof( f64,	8 );

#endif