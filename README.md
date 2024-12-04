# Plugin for Symbiotic contracts

This repository contains code for the plugin for Symbiotic contracts.

## Smart Contracts and functions

The implemented Smart Contracts and functions can be found in
[PLUGIN_SPECIFICATION.md](./PLUGIN_SPECIFICATION.md)

## Testing

For testing, we use [Ragger](https://github.com/LedgerHQ/ragger) for
simulating a Ledger device, to run the tests, use the Ledger plugin on VSCode or
run them with:

```bash
pip3 install -r ./tests/requirements.txt
```

```bash
pytest ./tests --device <nanox/nanosp/stax/flex>
```
