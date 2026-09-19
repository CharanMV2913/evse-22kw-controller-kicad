# Prototype implementation specification

This document is the release baseline for schematic capture and assembly of the control PCB. It intentionally excludes the hazardous 415 V power path.

## Functional sections

### A. 24 V SELV input

`J1-1 = +24V_SELv`, `J1-2 = 0V_SELv`. Provide an input fuse/PTC, reverse-polarity protection, TVS, and buck/LDO rails for 12 V and 3.3 V. The selected supply must be certified and current-limited.

### B. ESP32-S3

Use an ESP32-S3-WROOM-1 module with the manufacturer's recommended decoupling, boot strapping, USB/UART programming interface, antenna keepout, and exposed-ground requirements. Do not route copper or place metal under the antenna keepout.

### C. Hardware safety interlock

The external safety chain provides an isolated `SAFETY_OK` status and independently interrupts the external contactor coil circuit. The PCB's `CONTACTOR_REQUEST` is only an enable request. The request path must default low during reset and be ANDed with a hardware watchdog/fault signal before reaching the external relay interface.

Inputs are active-low normally-closed safety contacts unless the selected certified module specifies otherwise:

- emergency stop
- RCD/RDC-DD trip
- PE monitor healthy
- phase/voltage monitor healthy
- thermal monitor healthy
- enclosure/door interlock

### D. Control Pilot / Proximity Pilot

Use a dedicated IEC 61851-compatible CP front end or a verified reference circuit. CP must provide state measurement, diode check, pilot duty-cycle measurement, and protected ±12 V pilot drive. PP is measured through a protected divider and must not be connected directly to an ESP32 pin. Final resistor values depend on the selected Type 2 inlet/socket and cable ratings.

### E. External module interfaces

All field/status inputs are isolated dry-contact or isolated digital interfaces. Provide current limiting, surge suppression, pull-up selection, and a defined inactive state. RS-485 requires an isolated transceiver, termination selection, bias selection, and shield/chassis treatment defined by the enclosure design.

## Required net names

`+24V_SELV`, `+12V_SELV`, `+3V3`, `0V_SELV`, `CP_IN`, `CP_DRIVE`, `PP_SENSE`, `CONTACTOR_REQUEST`, `SAFETY_OK`, `RCD_STATUS`, `RDC_DD_STATUS`, `E_STOP_STATUS`, `PE_MONITOR_STATUS`, `PHASE_MONITOR_STATUS`, `OVERTEMP_1`, `OVERTEMP_2`, `CONTACTOR_AUX_1`, `CONTACTOR_AUX_2`, `RS485_A`, `RS485_B`, `USB_D+`, `USB_D-`, `JTAG`, and `RESET_N`.

## Design constraints

- Four-layer board: signal / ground / power / signal.
- Keep field connectors at the board edge and separate from USB/RF.
- No mains nets, mains terminals, or mains-referenced components on the PCB.
- Maintain the isolation distances specified by each isolator and the applicable insulation coordination review.
- Add test points for every supply rail, CP, PP, safety status, reset, and contactor request.
- Add a clearly marked programming/service connector that cannot be mistaken for a field connector.
