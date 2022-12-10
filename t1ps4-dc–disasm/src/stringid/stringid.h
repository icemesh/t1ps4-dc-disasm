/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <cinttypes>

extern std::uint32_t g_crc32Table[];

typedef std::uint32_t StringId;

constexpr const StringId StringIdHashConcat(std::uint32_t base, const char* str)
{
	return (*str) ? StringIdHashConcat(g_crc32Table[(base >> 24) ^ *str] ^ (base << 0x8), str + 1) : base;
}

constexpr const StringId StringIdHash(const char* str)
{
	return (str && *str) ? StringIdHashConcat(0, str) : -1;
}

// macros & constants
//-----------------------------------------------------------------------------
#define SID(str) (StringIdHash(str))
//-----------------------------------------------------------------------------
// end: macros & constant

