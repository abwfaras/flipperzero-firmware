#pragma once

#include <nfc/protocols/nfc_generic_event.h>

#include "iso15693_3_listener.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    Iso15693_3ListenerStateIdle,
    Iso15693_3ListenerStateActive,
} Iso15693_3ListenerState;

struct Iso15693_3Listener {
    Nfc* nfc;
    Iso15693_3Data* data;
    Iso15693_3ListenerState state;

    BitBuffer* tx_buffer;

    NfcGenericEvent generic_event;
    Iso15693_3ListenerEvent iso15693_3_event;
    Iso15693_3ListenerEventData iso15693_3_event_data;
    NfcGenericCallback callback;
    void* context;
};

Iso15693_3Error iso15693_3_listener_sleep(Iso15693_3Listener* instance);

Iso15693_3Error
    iso15693_3_listener_send_frame(Iso15693_3Listener* instance, const BitBuffer* tx_buffer);

#ifdef __cplusplus
}
#endif