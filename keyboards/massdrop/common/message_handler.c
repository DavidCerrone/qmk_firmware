//HID message handler
#include "message_handler.h"

#ifdef RAW_ENABLE

void handle_raw_hid_command(uint8_t *data, uint8_t length)
{
  uint8_t *command_id = &(data[0]);
	uint8_t *command_data = &(data[1]);

  dprintf("HID command %u\n", *command_id);

  switch(*command_id)
  {
    case message_id_protocol_version:
      command_data[0] = HID_PROTOCOL_VER >> 8;
      command_data[1] = HID_PROTOCOL_VER & 0xFF;
      break;

    case message_id_jump_to_bootloader:
      bootloader_jump();
      break;

    case message_id_set_rgb_mode:
      rgblight_mode(command_data[0]);
      break;

    case message_id_set_rgb_hsv:
      rgblight_sethsv(((uint16_t)((uint16_t)command_data[0] << (uint8_t)8) | (uint16_t)command_data[1]), command_data[2], command_data[3]);
      break;

    case message_id_set_rgb_hsv_noeeprom:
      rgblight_sethsv_noeeprom(((uint16_t)((uint16_t)command_data[0] << (uint8_t)8) | (uint16_t)command_data[1]), command_data[2], command_data[3]);
      break;

    case message_id_increase_brightness:
      rgblight_increase_val();
      break;

    case message_id_decrease_brightness:
      rgblight_decrease_val();
      break;

    case message_id_get_mute_led_enabled:
      break;

    case message_id_set_mute_led_enabled:
      break;

#ifdef DYNAMIC_KEYMAP_ENABLE
    case message_id_get_dynamic_keymap: ;
      uint16_t keycode = dynamic_keymap_get_keycode( command_data[0], command_data[1], command_data[2] );
			command_data[3] = keycode >> 8;
			command_data[4] = keycode & 0xFF;
      break;

    case message_id_set_dynamic_keymap:
      dynamic_keymap_set_keycode( command_data[0], command_data[1], command_data[2], ( command_data[3] << 8 ) | command_data[4] );
      break;
#endif

    case message_id_set_macro: ;

      break;

    case message_id_get_macro: ;

      break;

    default:
      dprintf("Unknown command_id: %d\n", *command_id);
      break;
  }
}

void raw_hid_receive( uint8_t *data, uint8_t length )
{
  handle_raw_hid_command(data, length);
  raw_hid_send(data, length);
}

#endif // RAW_ENABLE
