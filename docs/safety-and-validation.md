# Safety and validation requirements

## Safety boundary

This prototype board is SELV/control electronics only. It is not a mains-rated PCB and does not replace an RCD, RDC-DD, protective device, contactor, isolator, PE monitor, or certified EVSE controller.

## Required external protection

- Main isolator and coordinated overcurrent protection
- Surge protection suitable for the installation
- Type A 30 mA plus certified 6 mA DC RDC-DD, or a Type B RCD
- 4-pole contactor where required by the installation/design
- Emergency-stop device and normally-closed safety loop
- PE continuity/earth monitoring appropriate to the selected EVSE architecture
- Phase sequence/loss and voltage monitoring
- Thermal monitoring of socket/terminals/contactor where required

## Firmware safety rules

1. Boot into a non-energized state.
2. Require all safety inputs healthy before a contactor request.
3. Never infer safety from Wi-Fi, cloud, or user-interface state.
4. Remove the request on watchdog reset, brownout, invalid CP state, or communication failure.
5. Latch faults until a deliberate, safe reset procedure is completed.
6. Verify contactor auxiliary feedback after every transition and detect welded contacts.

## Validation before any mains connection

- Visual inspection and polarity/continuity checks
- Protective-earth continuity and bonding verification
- SELV-to-field isolation and insulation-resistance testing
- Dielectric withstand testing by a qualified laboratory/engineer
- Emergency-stop and hardwired safety-chain interruption tests
- RCD/RDC-DD trip and reset tests using calibrated equipment
- Contactor weld and auxiliary-feedback tests
- CP/PP conformance and state-transition tests
- Thermal and enclosure ingress validation
- EMC and functional testing under representative load
- Review against applicable Indian requirements, IS 17017 series, IEC 61851, IEC 62955, and local electrical rules

Do not use this repository as evidence that the resulting assembly is certified or safe for public or unattended operation.
