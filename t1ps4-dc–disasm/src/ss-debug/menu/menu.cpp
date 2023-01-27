#include "menu.h"
#include "../../dc/menu/menu.h"
#include "../../stringid/sidbase.h"

#include <stdio.h>

extern uintptr_t g_moduleBase;

void Menu::DumpMenuPageArray(MenuPageArray* pMenuPageArray)
{
	if (pMenuPageArray)
	{
		uint64_t numEntries = pMenuPageArray->m_numElements;
		if (numEntries)
		{
			for (uint64_t iEntry = 0; iEntry < numEntries; iEntry++)
			{
				MenuPage* pPage = &pMenuPageArray->m_pMenuPage[iEntry];
				printf("    :menu-page '%s\n    :root-menu '%s\n    :transition-type '%s\n    --------------------\n",
					pPage->m_pageName,
					pPage->m_rootMenuName != NULL ? pPage->m_rootMenuName : "",
					StringIdToStringInternal(pPage->m_transitionId)
				);
				MenuControlArray* pMcArray = pPage->m_pMenuControlArray;
				if (pMcArray)
				{
					uint64_t numElements = pMcArray->m_numElements;
					if (numElements)
					{
						for (uint32_t iElement = 0; iElement < numElements; iElement++)
						{
							MenuControl* pControl = &pMcArray->m_pMenuControl[iElement];
							printf("         @ 0x%016llX\n", (reinterpret_cast<uintptr_t>(pControl) - g_moduleBase));
							printf("        :button-name '%s\n        :action-name '%s\n        --------------------\n", pControl->m_buttonName, pControl->m_actionName);
						}
					}
				}
			}
		}
	}
}