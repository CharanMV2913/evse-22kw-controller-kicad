# Schematic capture and assembly checklist

The current board outline is not fabrication-ready until all items below are completed and reviewed.

## Schematic

- [ ] Select exact ESP32-S3-WROOM-1 variant and validate boot pins.
- [ ] Select certified 24 V SELV supply and define current budget.
- [ ] Select CP front-end/reference design and validate IEC 61851 behavior.
- [ ] Define the exact RCD/RDC-DD and PE/phase monitor dry-contact behavior.
- [ ] Complete safety-chain hardware logic independent of firmware.
- [ ] Add watchdog supervisor and reset behavior.
- [ ] Add reverse-polarity, overcurrent, and transient protection to external interfaces.
- [ ] Add connector pinout, keying, labels, and shield/chassis strategy.
- [ ] Annotate every component and assign exact footprints.
- [ ] Run ERC with intentional exceptions documented.

## PCB

- [ ] Place antenna keepout and USB connector first.
- [ ] Place isolation components as a physical boundary.
- [ ] Route clocks/USB/RF per vendor guidance.
- [ ] Route CP/PP away from noisy switching and RS-485.
- [ ] Add mounting holes and enclosure datum references.
- [ ] Add test points and production labels.
- [ ] Run DRC with manufacturer rules.
- [ ] Generate 3D and assembly review.

## Verification

- [ ] Test with a current-limited SELV bench supply only.
- [ ] Verify boot-fail and watchdog-fail contactor shutdown.
- [ ] Verify every safety input causes a latched non-energized state.
- [ ] Verify welded-contactor detection using a simulator.
- [ ] Verify CP/PP state machine with a certified EVSE test instrument.
- [ ] Verify isolation and dielectric withstand through a qualified lab.
- [ ] Complete thermal, EMC, enclosure, RCD and installation validation before mains use.
