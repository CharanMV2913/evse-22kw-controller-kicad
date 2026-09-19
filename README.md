# 22 kW India Type 2 EVSE Controller

Prototype control-board project for a three-phase 415 V AC, 32 A/phase IEC Type 2 EVSE.

## Scope

This project is deliberately limited to the SELV/control PCB. The 415 V power path, RCD/RCM, MCB/fuses, SPD, contactor, PE monitoring, and field wiring must be implemented with appropriately rated and certified external hardware.

The board is not a complete charger and must not be connected to mains without review, insulation/withstand testing, earth verification, RCD testing, enclosure validation, and applicable Indian compliance assessment.

## Baseline

- India: 415 V AC, 3-phase + N, 50 Hz
- Maximum output: 22 kW / 32 A per phase
- Connector: IEC 62196-2 Type 2
- Controller: ESP32-S3 module (prototype target: ESP32-S3-WROOM-1)
- External contactor/relay module; 24 V DC coil assumed
- RCD options: Type A + certified 6 mA DC RDC-DD, or Type B RCD

Do not install both RCD arrangements in series unless a qualified engineer has specifically verified selectivity and compatibility. The controller accepts isolated trip/status contacts from the selected external protection assembly.

## Repository contents

- `evse-22kw-controller.kicad_pcb` — initial 100 mm x 80 mm, four-layer control-board outline and design setup
- `evse-22kw-controller.kicad_pro` — KiCad project placeholder
- `docs/block-diagram.md` — system partition and safety interlock
- `docs/interface-and-pinmap.md` — proposed interfaces and ESP32-S3 mapping
- `docs/bom.md` — component categories and selection requirements
- `docs/safety-and-validation.md` — mandatory safety boundaries and test plan

The PCB file is intentionally an unpopulated starting board. Component selection and schematic capture must be completed against the exact external modules before fabrication.
