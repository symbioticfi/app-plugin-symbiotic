#include "plugin.h"
#include "utils.h"

void handle_symbiotic_deposit_issue_debt_withdraw(ethPluginProvideParameter_t *msg,
                                                  context_t *context) {
    switch (context->next_param) {
        case RECEIVER:
            copy_address(context->receiver, msg->parameter, sizeof(context->receiver));
            context->next_param = SHARES;
            break;

        case SHARES:
            copy_parameter(context->vault_shares, msg->parameter, sizeof(context->vault_shares));
            context->next_param = UNEXPECTED_PARAMETER;
            break;

        // Keep this
        default:
            PRINTF("Param not supported: %d\n", context->next_param);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

void handle_symbiotic_deposit_sig(ethPluginProvideParameter_t *msg, context_t *context) {
    switch (context->next_param) {
        case RECEIVER:
            copy_address(context->receiver, msg->parameter, sizeof(context->receiver));
            context->next_param = SHARES;
            break;

        case SHARES:
            copy_parameter(context->vault_shares, msg->parameter, sizeof(context->vault_shares));
            context->next_param = DEADLINE;
            break;

        case DEADLINE:
            copy_parameter(context->timestamp, msg->parameter, sizeof(context->timestamp));
            context->next_param = SIGNATURE_1;
            break;

        case SIGNATURE_1:
            copy_parameter(context->signature1 + 15, msg->parameter + 31, 1);
            context->next_param = SIGNATURE_2;
            break;

        case SIGNATURE_2:
            copy_parameter(context->signature2, msg->parameter, 3);
            copy_parameter(context->signature2 + 3, msg->parameter + 29, 3);
            context->next_param = SIGNATURE_3;
            break;

        case SIGNATURE_3:
            copy_parameter(context->signature2 + 6, msg->parameter, 3);
            copy_parameter(context->signature2 + 9, msg->parameter + 29, 3);
            context->next_param = UNEXPECTED_PARAMETER;
            break;

        // Keep this
        default:
            PRINTF("Param not supported: %d\n", context->next_param);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}

void handle_provide_parameter(ethPluginProvideParameter_t *msg) {
    context_t *context = (context_t *) msg->pluginContext;
    // We use `%.*H`: it's a utility function to print bytes. You first give
    // the number of bytes you wish to print (in this case, `PARAMETER_LENGTH`) and then
    // the address (here `msg->parameter`).
    PRINTF("plugin provide parameter: offset %d\nBytes: %.*H\n",
           msg->parameterOffset,
           PARAMETER_LENGTH,
           msg->parameter);

    msg->result = ETH_PLUGIN_RESULT_OK;

    // EDIT THIS: adapt the cases and the names of the functions.
    switch (context->selectorIndex) {
        case SYMBIOTIC_DEPOSIT:
        case SYMBIOTIC_ISSUE_DEBT:
        case SYMBIOTIC_WITHDRAW:
            handle_symbiotic_deposit_issue_debt_withdraw(msg, context);
            break;

        case SYMBIOTIC_DEPOSIT_SIG:
            handle_symbiotic_deposit_sig(msg, context);
            break;

        default:
            PRINTF("Selector Index not supported: %d\n", context->selectorIndex);
            msg->result = ETH_PLUGIN_RESULT_ERROR;
            break;
    }
}