# HID Protocol Definitions

## Version 0 (unversioned, no `protocol_version` message defined yet):
```c
enum message_id {
  message_id_set_rgb_mode = 0x01,
  message_id_set_rgb_hsv,
  message_id_increase_brightness,
  message_id_decrease_brightness,
  message_id_get_dynamic_keymap,
  message_id_set_dynamic_keymap,

  message_id_jump_to_bootloader,
};
```

## Version 1:
```c
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
  message_id_set_mute_led_disabled,
};
```

## Version 2:
```c
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
  message_id_set_mute_led_disabled,
  message_id_set_macro,
  message_id_get_macro,
};
```
