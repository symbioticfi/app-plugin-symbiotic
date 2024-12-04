#include "plugin.h"

void handle_finalize(ethPluginFinalize_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;
    msg->result = ETH_PLUGIN_RESULT_OK;
    msg->uiType = ETH_UI_TYPE_GENERIC;

    switch (context->selectorIndex) {
        case SYMBIOTIC_DEPOSIT:
        case SYMBIOTIC_ISSUE_DEBT:
        case SYMBIOTIC_WITHDRAW:
            msg->numScreens = 1;
            goto add_recipient_screen;

        case SYMBIOTIC_DEPOSIT_SIG:
            msg->numScreens = 5;
            goto add_recipient_screen;

        add_recipient_screen:
            if (memcmp(msg->address, context->receiver, ADDRESS_LENGTH) != 0) {
                msg->numScreens += 1;
            }
            break;

        default:
            PRINTF("Selector Index not supported: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}