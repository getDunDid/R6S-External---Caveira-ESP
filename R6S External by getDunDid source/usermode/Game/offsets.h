/*

	Game offsets, top ones need to be updated every
	update generally, and for big updates other ones
	may need to be changed too.

*/
#pragma once

// RainbowSix.exe ->
#define address_game_manager 0x53b7178
#define address_v_table 0x3ab3f00

// RainbowSix.exe -> game_manager -> 
#define offset_entity_count 0xD0
#define offset_entity_list 0xC8

// RainbowSix.exe -> game_manager -> entity_list ->
#define offset_entity_index 0x8