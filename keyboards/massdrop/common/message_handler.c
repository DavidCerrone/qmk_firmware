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

    case message_id_set_rgb_mode:
      rgblight_mode(command_data[0]);
      break;

    case message_id_increase_brightness:
      rgblight_increase_val();
      break;

    case message_id_decrease_brightness:
      rgblight_decrease_val();
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
