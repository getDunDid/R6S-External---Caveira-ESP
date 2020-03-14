/*

	Definitions for features and whatnot

*/

#include "Game.h"
#include "Offsets.h"

namespace RainbowSix
{
	bool esp()
	{
		uintptr_t game_manager = RPM<uintptr_t>(base_address + address_game_manager);
		if (!game_manager) return false;

		uintptr_t entity_list = RPM<uintptr_t>(game_manager + offset_entity_list);
		int entity_count = RPM<DWORD>(game_manager + offset_entity_count) & 0x3fffffff;
		if (!entity_list || !entity_count) return false;

		for (int i = 0; i < entity_count; i++)
		{
			uintptr_t entity_object = RPM<uintptr_t>(entity_list + i * 0x8);
			if (!entity_object) continue;

			uintptr_t chain2 = RPM<uintptr_t>(entity_object + 0x28); if (!chain2) continue;
			uintptr_t chain3 = RPM<uintptr_t>(chain2 + 0xD8); if (!chain3) continue;

			for (auto current_component = 0x80; current_component < 0xf0; current_component += sizeof(uintptr_t))
			{
				uintptr_t chain4 = RPM<uintptr_t>(chain3 + current_component);
				if (!chain4) continue;

				if (RPM<uintptr_t>(chain4) != (base_address + address_v_table)) continue;

				WPM<BYTE>(chain4 + 0x552, bCaveiraESPStatus);
				WPM<BYTE>(chain4 + 0x554, bCaveiraESPStatus);
			}
		}
	}
}