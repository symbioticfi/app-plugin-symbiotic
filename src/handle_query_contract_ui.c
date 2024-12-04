#include "plugin.h"
#include "utils.h"

static bool symbiotic_deposit_issue_debt_withdraw_ui(ethQueryContractUI_t *msg,
                                                     const context_t *context) {
    switch (msg->screenIndex) {
        case 0:
            strlcpy(msg->title, "Amount", msg->titleLength);
            amountToString(context->vault_shares,
                           sizeof(context->vault_shares),
                           0,
                           "",
                           msg->msg,
                           msg->msgLength);
            return true;

        case 1:
            strlcpy(msg->title, "Recipient", msg->titleLength);
            display_first_and_last_bytes(msg, (uint8_t *) context->receiver, ADDRESS_LENGTH, 3);
            return true;

        default:
            PRINTF("Received an invalid screenIndex\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return false;
    }
}

static bool symbiotic_deposit_sig_ui(ethQueryContractUI_t *msg, const context_t *context) {
    switch (msg->screenIndex) {
        case 0:
            strlcpy(msg->title, "Amount", msg->titleLength);
            amountToString(context->vault_shares,
                           sizeof(context->vault_shares),
                           0,
                           "",
                           msg->msg,
                           msg->msgLength);
            return true;

        case 1:
            strlcpy(msg->title, "Deadline", msg->titleLength);
            amountToString(context->timestamp,
                           sizeof(context->timestamp),
                           0,
                           "",
                           msg->msg,
                           msg->msgLength);
            return true;

        case 2:
            strlcpy(msg->title, "V", msg->titleLength);
            display_first_and_last_bytes(msg, (uint8_t *) context->signature1 + 15, 0, 1);
            return true;

        case 3:
            strlcpy(msg->title, "R", msg->titleLength);
            display_first_and_last_bytes(msg, (uint8_t *) context->exit_queue_index, 6, 3);
            return true;

        case 4:
            strlcpy(msg->title, "S", msg->titleLength);
            display_first_and_last_bytes(msg, (uint8_t *) context->exit_queue_index + 6, 6, 3);
            return true;

        case 5:
            strlcpy(msg->title, "Recipient", msg->titleLength);
            display_first_and_last_bytes(msg, (uint8_t *) context->receiver, ADDRESS_LENGTH, 3);
            return true;

        default:
            PRINTF("Received an invalid screenIndex\n");
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            return false;
    }
}

void handle_query_contract_ui(ethQueryContractUI_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;
    bool ret = false;
    // msg->title is the upper line displayed on the device.
    // msg->msg is the lower line displayed on the device.
    // Clean the display fields.
    memset(msg->title, 0, msg->titleLength);
    memset(msg->msg, 0, msg->msgLength);

    switch (context->selectorIndex) {
        case SYMBIOTIC_DEPOSIT:
        case SYMBIOTIC_ISSUE_DEBT:
        case SYMBIOTIC_WITHDRAW:
            ret = symbiotic_deposit_issue_debt_withdraw_ui(msg, context);
            break;

        case SYMBIOTIC_DEPOSIT_SIG:
            ret = symbiotic_deposit_sig_ui(msg, context);
            break;

        default:
            PRINTF("Received an invalid selectorIndex\n");
    }
    msg->result = ret ? ETH_PLUGIN_RESULT_OK : ETH_PLUGIN_RESULT_ERROR;
}