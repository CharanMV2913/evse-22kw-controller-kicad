# Build status — not fabrication-ready

## Current status

This repository contains a **conceptual prototype baseline only**. It must not be used to order or assemble a mains-connected EVSE.

The files named `evse-22kw-controller.kicad_sch` and `evse-22kw-controller.kicad_pcb` have not been validated by KiCad ERC/DRC in this repository. They are not evidence of a complete, electrically correct schematic or routed PCB.

## Blocking items

1. Exact ESP32-S3 module variant and manufacturer footprint must be selected and checked against the vendor datasheet.
2. A certified IEC 61851 CP/PP front-end must be selected; CP/PP cannot be safely finalized from placeholder symbols.
3. The external 24 V contactor/relay interface and its coil-current/fault behavior must be specified.
4. The Type A + RDC-DD or Type B RCD architecture must be selected; both are not automatically interchangeable.
5. All field connectors, isolation requirements, protection, and enclosure interfaces must be frozen.
6. A valid KiCad schematic must be captured using installed KiCad libraries, then annotated and checked with ERC.
7. The PCB must be updated from the checked schematic, fully routed, and checked with DRC and manufacturer rules.
8. CP/PP behavior, safety-chain behavior, insulation, EMC, thermal performance, and RCD operation require qualified testing.

## Safe completion criterion

The project may only be called complete when a qualified engineer has reviewed the design and the following artifacts exist:

- valid KiCad schematic with no unexplained ERC errors;
- PCB updated from that schematic with no unexplained DRC errors;
- locked footprints and manufacturer part numbers;
- assembly drawings, BOM, and fabrication outputs;
- verified external power/safety assembly;
- documented test results for the applicable Indian and IEC requirements.

Until then, keep the board disconnected from 415 V and use only current-limited SELV bench testing.
