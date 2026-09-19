# Interfaces and proposed ESP32-S3 pin map

This mapping is a starting point for an ESP32-S3-WROOM-1 prototype and must be checked against the selected module's strapping, USB/JTAG, flash, PSRAM, and boot requirements.

| GPIO | Function | Direction | Notes |
|---:|---|---|---|
| 4 | CP_ADC | input | Pilot-state measurement |
| 5 | CP_STATE | input | Comparator/state indication |
| 6 | PP_ADC | input | Protected proximity measurement |
| 7 | CONTACTOR_REQUEST | output | Request only; not the safety chain |
| 8 | CONTACTOR_AUX_1 | input | Isolated auxiliary contact |
| 9 | CONTACTOR_AUX_2 | input | Optional second auxiliary contact |
| 10 | RCD_STATUS | input | Isolated dry contact |
| 11 | RDC_DD_STATUS | input | Isolated dry contact, if used |
| 12 | E_STOP_STATUS | input | Normally-closed loop status |
| 13 | PE_MONITOR_STATUS | input | External monitor status |
| 14 | PHASE_MONITOR_STATUS | input | External relay status |
| 15 | OVERTEMP_1 | input | Socket/terminal sensor module |
| 16 | OVERTEMP_2 | input | Contactor/enclosure sensor module |
| 17 | RS485_DE_RE | output | Isolated transceiver direction |
| 18 | RS485_RX | input | Isolated Modbus meter |
| 19 | RS485_TX | output | Isolated Modbus meter |
| 20 | STATUS_GREEN | output | Status LED |
| 21 | STATUS_RED | output | Fault LED |
| 22 | SERVICE_INPUT | input | Local service/control input |
| 23 | HARDWARE_FAULT_STATUS | input | Safety-chain monitor |

## External connectors

- `J1`: 24 V SELV power input from protected external supply
- `J2`: external contactor enable/coil-interface module
- `J3`: isolated safety-status inputs
- `J4`: Type 2 CP/PP interface
- `J5`: isolated RS-485
- `J6`: service/debug header

Connector pinout and mating parts must be frozen before schematic release. Use keyed, touch-safe connectors and strain relief appropriate for the enclosure.
