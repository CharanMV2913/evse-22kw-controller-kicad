# EVSE firmware safety state machine

This is implementation guidance for the ESP32-S3 prototype. It is not a safety certification or a substitute for the hardwired interlock.

```text
BOOT
  -> SELF_TEST
  -> FAULT_LATCHED       if watchdog, brownout, invalid hardware, or unsafe input
  -> IDLE                if every safety input is healthy

IDLE
  -> CONNECTED           when PP indicates a valid cable/vehicle presence
  -> FAULT_LATCHED       if any safety input is unhealthy

CONNECTED
  -> READY                when CP state is valid and vehicle requests charging
  -> IDLE                 when cable is removed
  -> FAULT_LATCHED        on CP diode/state failure or safety fault

READY
  -> CHARGING             only after hardware safety chain is healthy and contactor feedback is open
  -> IDLE                 when vehicle releases request
  -> FAULT_LATCHED        on timeout or safety fault

CHARGING
  -> STOPPING             on vehicle release, timeout, communication loss, or any safety fault

STOPPING
  -> IDLE                 only after contactor auxiliary confirms open
  -> FAULT_LATCHED        if contactor remains closed or timeout expires

FAULT_LATCHED
  -> IDLE                 only after the external safety condition is restored and a deliberate reset is accepted
```

The firmware must use a monotonic timeout source, feed the watchdog only while the state machine is healthy, and drive `CONTACTOR_REQUEST` low before attempting recovery. A cloud/UI command must never bypass the local safety checks.
