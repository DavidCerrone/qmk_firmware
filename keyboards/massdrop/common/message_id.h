#ifndef MESSAGE_ID_H

#ifdef RAW_ENABLE
#define MESSAGE_ID_H

//Device protocol version
#define HID_PROTOCOL_VER 2

//HID protocol version 1
enum message_id {
  message_id_protocol_version = 0x01,
  message_id_jump_to_bootloader,

  message_id_set_rgb_mode,
  message_id_set_rgb_hsv,
  message_id_set_rgb_hsv_noeeprom,
  message_id_increase_brightness,
  message_id_decrease_brightness,
  message_id_get_dynamic_keymap,
  message_id_set_dynamic_keymap,
  message_id_get_mute_led_enabled,
  message_id_set_mute_led_enabled,
  message_id_set_macro,
  message_id_get_macro,
};

#endif //RAW_ENABLE
#endif //MESSAGE_ID_H
