/******************************************************************************/
/*
  Author  - icemesh
*/
/******************************************************************************/
#pragma once

#include <stdint.h>

struct MenuPage;
struct MenuControlArray;
struct MenuControl;

//0x10
struct MenuPageArray
{
	uint64_t m_numElements;
	MenuPage* m_pMenuPage;
};

//0xA0
struct MenuPage
{
	const char*			m_pageName;				///< <c>0x00</c>:
	uint32_t			m_nameId;				///< <c>0x08</c>: StringId of the m_pageName
	uint32_t			m_nameIdPad;			///< <c>0x0C</c>: 
	const char*			m_rootMenuName;			///< <c>0x10</c>: 
	uint32_t			m_rootMenuNameId;		///< <c>0x18</c>: 
	uint32_t			m_rootMenuNameIdPad;	///< <c>0x1C</c>: 
	uint8_t				m_imLazy[0x24];			///< <c>0x20</c>: always 0 ?
	uint32_t			m_unkValus;				///< <c>0x44</c>: unk value
	MenuControlArray*	m_pMenuControlArray;	///< <c>0x48</c>:
	uint32_t			m_unkNumber;			///< <c>0x50</c>: always 0x28? 
	uint8_t				m_imLazy2[0x44];		///< <c>0x54</c>: always 0?
	uint32_t			m_transitionId;			///< <c>0x98</c>: eg SID("*basic-transition*")
	uint32_t			m_unk;					///< <c>0x9C</c>: always 0?
};

//0x14
struct MenuControlArray
{
	uint64_t		m_numElements;
	MenuControl*	m_pMenuControl;
	uint32_t		m_padding;
};

//0x70?
struct MenuControl
{
	const char* m_buttonName;		///< <c>0x00</c>:
	uint32_t	m_buttonNameId;		///< <c>0x08</c>:
	uint64_t	m_unkNum;			///< <c>0x10</c>: always 2 ?
	uint64_t	m_unkNum2;			///< <c>0x18</c>: always 0xA ?
	const char* m_actionName;		///< <c>0x20</c>: 
	uint32_t	m_actionNameId;		///< <c>0x28</c>: StringId of the action name
	uint32_t	m_actionNameIdPad;	///< <c>0x2C</c>: 
	uint32_t	m_unkNum3;			///< <c>0x30</c>: 
	uint32_t	m_unkNum4;			///< <c>0x34</c>: 
	uint8_t		m_imLazy[0x30];		///< <c>0x38</c>: always 0 ?
	uint32_t	m_unkNum5;			///< <c>0x68</c>: 
	uint32_t	m_unkNum6;			///< <c>0x6C</c>: 
};