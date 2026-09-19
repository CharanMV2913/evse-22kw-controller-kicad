# BOM and selection requirements

This is a selection checklist, not a release BOM. Exact manufacturer part numbers require the final schematic, enclosure, supply, and certification strategy.

| Reference/category | Requirement |
|---|---|
| U1 | ESP32-S3-WROOM-1 or approved equivalent; module antenna keepout respected |
| U2 | Isolated RS-485 transceiver if an external meter is used |
| U3 | Hardware watchdog/supervisor with reset output |
| U4 | CP front-end designed for IEC 61851 pilot levels and protected from transients |
| U5 | Isolated DC/DC or certified SELV supply interface as required by system architecture |
| K1 | External 24 V contactor/relay safety interface; suitably rated and certified |
| F1 | Local low-voltage input protection, sized for the selected supply |
| TVS parts | Rated for each external interface and its fault/transient environment |
| Optocouplers/digital isolators | Safety/status inputs with required isolation voltage and creepage |
| J1-J6 | Touch-safe, keyed, locking connectors with appropriate ratings |
| Sensors | External RCD/RDC-DD, PE monitor, phase monitor, and thermal devices with isolated status outputs |

The Type A + 6 mA RDC-DD and Type B RCD are alternative protection architectures. Select one certified external assembly and document its trip contact behavior, reset behavior, leakage limits, and coordination with the upstream installation.
