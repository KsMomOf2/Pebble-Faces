#include "pebble_process_info.h"
#include "src/resource_ids.auto.h"

const PebbleProcessInfo __pbl_app_info __attribute__ ((section (".pbl_header"))) = {
  .header = "PBLAPP",
  .struct_version = { PROCESS_INFO_CURRENT_STRUCT_VERSION_MAJOR, PROCESS_INFO_CURRENT_STRUCT_VERSION_MINOR },
  .sdk_version = { PROCESS_INFO_CURRENT_SDK_VERSION_MAJOR, PROCESS_INFO_CURRENT_SDK_VERSION_MINOR },
  .process_version = { 1, 0 },
  .load_size = 0xb6b6,
  .offset = 0xb6b6b6b6,
  .crc = 0xb6b6b6b6,
  .name = "simplehands",
  .company = "MakeAwesomeHappen",
  .icon_resource_id = DEFAULT_MENU_ICON,
  .sym_table_addr = 0xA7A7A7A7,
  .flags = PROCESS_INFO_WATCH_FACE | PROCESS_INFO_ROCKY_APP | PROCESS_INFO_PLATFORM_DIORITE,
  .num_reloc_entries = 0xdeadcafe,
  .uuid = { 0x1A, 0x73, 0xC0, 0x3C, 0x3A, 0x1A, 0x4F, 0x1C, 0xA3, 0x02, 0xBF, 0x8B, 0x59, 0x2D, 0x4E, 0x8B },
  .virtual_size = 0xb6b6
};
