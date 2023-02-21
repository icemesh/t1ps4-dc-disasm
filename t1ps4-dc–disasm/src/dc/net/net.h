/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <stdint.h>

struct SymbolArray;

//0x10
struct NetGameArray
{
	uint64_t m_numElements;
	NetGame* m_pNetGame;
};

enum class GameType : uint32_t
{
	kObjective = 0,
	kChallenge = 1,
	kDeathmatch = 2,
	kElimination = 3,
	kInterrogation = 4
};

//0x78
struct NetGame
{
	uint32_t	m_nameId;					///< <c>0x00</c>: StringId
	uint32_t	m_unkSid;					///< <c>0x04</c>: StringId
	uint32_t	m_unkSid2;					///< <c>0x08</c>: StringId
	GameType	m_gameType;					///< <c>0x0C</c>: 0 = objective || 1 = challenge || 2 = deathmatch || 3 = elimination || 4 = interrogation
	uint32_t	m_unk;						///< <c>0x10</c>: always -1 ?
	float		m_unkFloat;					///< <c>0x14</c>: might not be a float ?
	uint32_t	m_unk2;						///< <c>0x18</c>: always -1 ?
	float		m_unkFloat;					///< <c>0x1C</c>: 
	uint8_t		m_imLazy[0xC];				///< <c>0x20</c>: always 0?
	uint32_t	m_musicPlaylistWin;			///< <c>0x2C</c>: eg SID("*net-game-win*")
	uint32_t	m_musicPlaylistLoss;		///< <c>0x30</c>: eg SID("*net-game-lose*") 
	uint8_t		m_imLazy2[0x18];			///< <c>0x34</c>: always 0?
	uint32_t	m_playerHealthSettingsId;	///< <c>0x4C</c>: usually SID("*player-health-settings-online*") 
	uint8_t		m_imLazy3[0x10];			///< <c>0x50</c>: always 0?
	int32_t		m_unkInt;					///< <c>0x60</c>: this could be a int64_t...
	uint32_t	m_unk_3;					///< <c>0x64</c>: alwasy 0 ?
	int32_t		m_unkInt2;					///< <c>0x68</c>: this could be a int64_t...
	uint32_t	m_unk_4;					///< <c>0x6C</c>: alwasy 0 ?
	uint32_t	m_respawnWeightId;			///< <c>0x70</c>: 
	uint32_t	m_unk_5;					///< <c>0x74</c>: alwasy 0 ?
}; 

//0x14
struct SwappableArray
{
	int64_t m_count;///< <c>0x00</c>: number of elements in the array
	void* m_pData;///< <c>0x08</c>: ptr to the data
	uint32_t m_padding;///< <c>0x10</c>: padding probably
};

//0x50
struct SwappableElement
{
	uint32_t		m_unkSid;				///< <c>0x00</c>: eg SID("PART_NAME_DEFAULT")
	uint32_t		m_unkSidPad;			///< <c>0x04</c>: 
	void*			m_pIdentifierArray;		///< <c>0x08</c>: 
	SymbolArray*	m_pSymbolArray;			///< <c>0x10</c>:  
	SymbolArray*	m_pSymbolArray2;		///< <c>0x18</c>:  
	SymbolArray*	m_pSymbolArray3;		///< <c>0x20</c>:  
	uint32_t		m_unk;					///< <c>0x28</c>: always 0 ?
	int64_t			m_unkInt;				///< <c>0x2C</c>: 
	uint32_t		m_unk2;					///< <c>0x28</c>: always 0 ?
	uint32_t		m_skinId;				///< <c>0x3C</c>: eg SID("*mp-white-skin*")
	int64_t			m_unkInt2;				///< <c>0x40</c>: 
	uint64_t		m_unk3;					///< <c>0x28</c>: always 0 ?
};