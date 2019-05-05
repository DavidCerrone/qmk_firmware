//HID message handler
#include "message_handler.h"
#include QMK_KEYBOARD_H
#include "led_matrix.h"

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

        case message_id_bootloader:
            reset_keyboard();
            break;

        case message_id_increase_brightness:
            rgblight_increase_val();
            break;

        case message_id_decrease_brightness:
            rgblight_decrease_val();
            break;

        case message_id_increase_pattern:
            rgblight_step();
            break;

        case message_id_decrease_pattern:
            rgblight_step_reverse();
            break;

        case message_id_increase_speed:
            rgblight_increase_speed();
            break;

        case message_id_decrease_speed:
            rgblight_decrease_speed();
            break;

        case message_id_set_rgb_hsv_noeeprom:
            rgblight_sethsv_noeeprom(((uint16_t)((uint16_t)command_data[0] << (uint8_t)8) | (uint16_t)command_data[1]), command_data[2], command_data[3]);
            break;

        case message_id_toggle_mode:
            switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_KEYLIGHT: {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
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
