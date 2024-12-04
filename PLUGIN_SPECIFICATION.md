# Technical Specification

## About

This documentation describes the smart contracts and functions supported by the boilerplate plugin.

## Smart Contracts

Smart contracts covered by the plugin shall be described here:

| Network  | Smart Contract      | Address                                      |
| -------- | ------------------- | -------------------------------------------- |
| Ethereum | Symbiotic (wstETH)  | `0xc329400492c6ff2438472d4651ad17389fcb843a` |
| Ethereum | Symbiotic (cbETH)   | `0xb26ff591f44b04e78de18f43b46f8b70c6676984` |
| Ethereum | Symbiotic (wBETH)   | `0x422f5accc812c396600010f224b320a743695f85` |
| Ethereum | Symbiotic (rETH)    | `0x03bf48b8a1b37fbead1ecabcf15b98b924ffa5ac` |
| Ethereum | Symbiotic (mETH)    | `0x475d3eb031d250070b63fa145f0fcfc5d97c304a` |
| Ethereum | Symbiotic (swETH)   | `0x38b86004842d3fa4596f0b7a0b53de90745ab654` |
| Ethereum | Symbiotic (sfrxETH) | `0x5198cb44d7b2e993ebdda9cad3b9a0eaa32769d2` |
| Ethereum | Symbiotic (ETHx)    | `0xbdea8e677f9f7c294a4556005c640ee505be6925` |

## Functions

For the smart contracts implemented, the functions covered by the plugin shall be described here:

| Contract  | Function  | Selector     | Displayed Parameters                                                                                                                                                                                                                                                                                     |
| --------- | --------- | ------------ | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Symbiotic | deposit   | `0x47e7ef24` | <table><tbody> <tr><td><code>address recipient</code></td></tr> <tr><td><code>uint256 amount</code></td></tr> </tbody></table>                                                                                                                                                                           |
| Symbiotic | deposit   | `0xc5758489` | <table><tbody> <tr><td><code>address recipient</code></td></tr> <tr><td><code>uint256 amount</code></td></tr> <tr><td><code>uint256 deadline</code></td></tr> <tr><td><code>bytes32 v</code></td></tr> <tr><td><code>bytes32 r</code></td></tr> <tr><td><code>bytes32 s</code></td></tr></tbody></table> |
| Symbiotic | issueDebt | `0x7715be0b` | <table><tbody> <tr><td><code>address recipient</code></td></tr> <tr><td><code>uint256 amount</code></td></tr> </tbody></table>                                                                                                                                                                           |
| Symbiotic | withdraw  | `0xf3fef3a3` | <table><tbody> <tr><td><code>address recipient</code></td></tr> <tr><td><code>uint256 amount</code></td></tr> </tbody></table>                                                                                                                                                                           |
