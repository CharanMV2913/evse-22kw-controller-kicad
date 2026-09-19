# KiCad completion procedure

This procedure is required before the project can be considered complete.

## 1. Start from a clean KiCad project

Open the project in the target KiCad version and replace any placeholder or malformed library entries using the official KiCad libraries and vendor-provided footprints.

## 2. Capture the schematic

Create these hierarchical sheets:

- `power_se_lv`: protected 24 V input, fuse/PTC, reverse-polarity protection, regulator rails, supervisor;
- `esp32s3`: exact module, reset/boot, USB/JTAG and decoupling;
- `safety_interlock`: isolated status contacts and hardware request inhibit;
- `cp_pp`: selected IEC 61851 CP/PP reference circuit;
- `contactor_io`: external 24 V relay/contactor interface and auxiliary feedback;
- `rs485_service`: isolated meter interface and service connector.

Every external input needs a defined inactive state, transient protection, and a documented isolation boundary. Every connector must have a pinout table and mating-part reference.

## 3. Validate

Run annotation, electrical rules check, footprint assignment, and design review. Do not suppress errors merely to obtain a clean report; document every intentional exception.

## 4. Place and route

Use the selected manufacturer's recommended land patterns. Keep the RF antenna area clear. Separate field interfaces, CP/PP, switching outputs, USB, and RF. Apply the required creepage and clearance based on the actual isolation ratings and enclosure.

## 5. Release

Run PCB design rules, inspect the 3D board, generate the BOM and pick-and-place files, and have an independent engineer review the power and safety interface. Do not generate or use mains fabrication outputs until this review is complete.
