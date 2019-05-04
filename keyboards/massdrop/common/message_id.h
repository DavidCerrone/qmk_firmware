#ifndef MESSAGE_ID_H

#ifdef RAW_ENABLE
#define MESSAGE_ID_H

//Device protocol version
#define HID_PROTOCOL_VER 1

//HID protocol version 1
enum message_id {
  message_id_protocol_version = 0x01,

  message_id_set_rgb_mode,
  message_id_increase_brightness,
  message_id_decrease_brightness,
};

#endif //RAW_ENABLE
#endif //MESSAGE_ID_H
