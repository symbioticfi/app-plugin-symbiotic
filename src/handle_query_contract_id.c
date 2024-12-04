#include "plugin.h"

// Sets the first screen to display.
void handle_query_contract_id(ethQueryContractID_t *msg) {
    const context_t *context = (const context_t *) msg->pluginContext;
    // msg->name will be the upper sentence displayed on the screen.
    // msg->version will be the lower sentence displayed on the screen.
    msg->result = ETH_PLUGIN_RESULT_OK;

    switch (context->selectorIndex) {
        case SYMBIOTIC_DEPOSIT:
            strlcpy(msg->name, "Symbiotic", msg->nameLength);
            strlcpy(msg->version, "Deposit", msg->versionLength);
            break;

        case SYMBIOTIC_DEPOSIT_SIG:
            strlcpy(msg->name, "Symbiotic", msg->nameLength);
            strlcpy(msg->version, "Deposit with signature", msg->versionLength);
            break;

        case SYMBIOTIC_ISSUE_DEBT:
            strlcpy(msg->name, "Symbiotic", msg->nameLength);
            strlcpy(msg->version, "Issue debt", msg->versionLength);
            break;

        case SYMBIOTIC_WITHDRAW:
            strlcpy(msg->name, "Symbiotic", msg->nameLength);
            strlcpy(msg->version, "Withdraw", msg->versionLength);
            break;

        default:
            PRINTF("Selector index: %d not supported\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}