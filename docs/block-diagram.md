# System block diagram

```text
  415 V 3-phase supply
          |
  [External certified power assembly]
  isolator | MCB/fuses | SPD | RCD/RCM
          |
     4-pole contactor -------------------- Type 2 socket
          |                                      |
          +-- auxiliary contacts                 +-- CP / PP

  [Control PCB: SELV only]
  ESP32-S3 -> CP/PP interface -> Type 2 connector
      |
      +-> enable request -> hardware safety interlock -> external contactor coil driver
      |
      +<- isolated feedback: RCD/RDC-DD, PE monitor, phase monitor,
      |   emergency stop, overtemperature, contactor auxiliary contacts
      |
      +-> optional isolated RS-485 energy meter / service communications
```

## Hardwired shutdown

The ESP32-S3 may request charging, but it must not be the sole safety shutdown path. The external contactor coil-enable circuit must be interrupted by the normally-closed safety chain, including emergency stop, RCD/RDC-DD trip, PE fault, overtemperature, and phase/voltage fault. The controller should observe the resulting isolated status contacts and enter a latched fault state.

## Isolation boundary

No 415 V conductor is routed on this board. Field inputs must be SELV or galvanically isolated dry contacts. CP/PP circuitry must be designed for the selected Type 2 socket and protected against connector transients.
