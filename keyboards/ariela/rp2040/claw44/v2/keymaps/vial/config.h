#pragma once


#define VIAL_KEYBOARD_UID {0xAD, 0x42, 0xC2, 0xA6, 0xB8, 0x86, 0xA4, 0x65}
#define VIAL_UNLOCK_COMBO_ROWS {0, 4}
#define VIAL_UNLOCK_COMBO_COLS {2, 3}

/* define RP2040 boot用 */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.

/* define RP2040 PC起動時認識用（SPLIT_USB_DETECTが有効となっているため） */
#define SPLIT_USB_TIMEOUT 7000 //Default 2000
#define SPLIT_USB_TIMEOUT_POLL 25 //Default 10
