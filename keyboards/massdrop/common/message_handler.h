#ifndef MESSAGE_HANDLER_H
#define MESSAGE_HANDLER_H

#include <print.h>
#include "quantum.h"
#include "dynamic_keymap.h"
#include "raw_hid.h"
#include "message_id.h"

void raw_hid_receive(uint8_t *data, uint8_t length);

#endif //MESSAGE_HANDLER_H
