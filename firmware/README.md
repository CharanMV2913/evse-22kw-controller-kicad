# Prototype safety firmware skeleton

This folder contains only a safe-state reference skeleton. It does not control a certified EVSE by itself and must not be used as the sole contactor safety mechanism.

The firmware must default `CONTACTOR_REQUEST` low, require all local safety inputs healthy, and latch faults. The external normally-closed safety chain must interrupt the contactor coil independently of the ESP32-S3.
