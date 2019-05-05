#ifndef MESSAGE_ID_H

#ifdef RAW_ENABLE
#define MESSAGE_ID_H

//Device protocol version
#define HID_PROTOCOL_VER 1

//HID protocol version 1
enum message_id {
    message_id_protocol_version = 0x01,
    message_id_bootloader,

    message_id_increase_brightness,
    message_id_decrease_brightness,

    message_id_increase_pattern,
    message_id_decrease_pattern,

    message_id_increase_speed,
    message_id_decrease_speed,

    message_id_set_rgb_hsv_noeeprom,

    message_id_toggle_mode,
};

#endif //RAW_ENABLE
#endif //MESSAGE_ID_H
