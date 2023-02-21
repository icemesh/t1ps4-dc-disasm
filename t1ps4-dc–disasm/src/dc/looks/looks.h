/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include "../../stringid/stringid.h"

struct SymbolArray;

struct LookMesh;

//0x14
struct LookMeshArrayPtr
{
	LookMesh**	m_apLookMesh;
	int64_t		m_count;
	uint32_t	m_padding;
};

//0x3C
struct Look
{
	StringId			m_nameId;///< <c>0x00</c>: eg SID("joel-npc")
	StringId			m_skelId;///< <c>0x04</c>: eg SID("joel-skel")
	uint64_t			m_unk;///< <c>0x08</c>: always 0 ?
	LookMeshArrayPtr*	m_pArray;///< <c>0x10</c>: 
	StringId			m_ambientOccluderId;///< <c>0x18</c>: eg SID("default-ambient-occluders*)
	uint32_t			m_ambientOccluderIdPad;///< <c>0x1C</c>: padding 
	SymbolArray*		m_pSymbolArray;///< <c>0x20</c>:  
	uint64_t			m_unk2;///< <c>0x28</c>: always 0 ?
	uint64_t			m_unkInt;///< <c>0x30</c>: always 2 ?
	uint32_t			m_padding;///< <c>0x38</c>: padding probably
};

struct LookMesh
{
	uint32_t m_unk;///< <c>0x00</c>: always 0 ?
	StringId m_meshId;///< <c>0x04</c>: eg SID("joel-leg-holster") || SID("
	StringId m_attachablePropId;///< <c>0x08</c>: SID("flashlight")
	uint8_t m_imLazy[0x18];///< <c>0x0C</c>: always 0?
	uint32_t m_unkInt;///< <c>0x24</c>: sometims set to 1
	uint8_t m_imLazy2[0x14];///< <c>0x28</c>: always 0?
};