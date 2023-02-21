#include "looks.h"
#include "../../dc/looks/looks.h"
#include "../../stringid/sidbase.h"
#include "../../dc/state-script/state-script.h"
#include <stdio.h>

extern uintptr_t g_moduleBase;

void DumpLook(Look* pLook)
{
	if (pLook)
	{
		printf("    :name-id '%s // @ 0x%llX\n", StringIdToStringInternal(pLook->m_nameId), (uintptr_t)&pLook->m_nameId - g_moduleBase );
		printf("    :skel-id '%s // @ 0x%llX\n", StringIdToStringInternal(pLook->m_skelId), (uintptr_t)&pLook->m_skelId - g_moduleBase );
		puts("    :look-mesh-array = (");
		if (pLook->m_pArray)
		{
			LookMesh** ppArray = pLook->m_pArray->m_apLookMesh;
			int64_t count = pLook->m_pArray->m_count;
			if (count)
			{
				for (int64_t i = 0; i < count; i++)
				{
					LookMesh* pLook = ppArray[i];
					printf("        :unk '%s\n", StringIdToStringInternal(pLook->m_unk));
					printf("        :mesh-id '%s // @ 0x%llX\n", StringIdToStringInternal(pLook->m_meshId), (uintptr_t)&pLook->m_meshId- g_moduleBase);
					printf("        :attachable-prop '%s // @ 0x%llX\n         --------------------\n", StringIdToStringInternal(pLook->m_attachablePropId), (uintptr_t)&pLook->m_attachablePropId - g_moduleBase);
				}
			}

		}
		puts("     )");
		printf("    :ambient-occluder '%s\n", StringIdToStringInternal(pLook->m_ambientOccluderId));
		puts("    :symbol-array = (");
		if (pLook->m_pSymbolArray)
		{
			SymbolArray* pSymbolArray = pLook->m_pSymbolArray;
			int32_t count = pSymbolArray->m_numEntries;
			for (int32_t iSymbols = 0; iSymbols < count; iSymbols++)
			{
				printf("        : '%s // @ 0x%llX\n", StringIdToStringInternal(pSymbolArray->m_pSymbols[iSymbols]), (uintptr_t)(&pSymbolArray->m_pSymbols[iSymbols]) - g_moduleBase);
			}
		}
		puts("     )");
	}
}
