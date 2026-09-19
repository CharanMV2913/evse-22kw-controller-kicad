#include <stdint.h>

// Reference-only state logic. Replace with project HAL and verified CP/PP implementation.
enum class EvseState : uint8_t {
  Boot,
  Idle,
  Connected,
  Ready,
  Charging,
  Stopping,
  FaultLatched
};

struct SafetyInputs {
  bool rcdHealthy;
  bool rdcDdHealthy;
  bool emergencyStopHealthy;
  bool peHealthy;
  bool phaseHealthy;
  bool temperatureHealthy;
  bool hardwareInterlockHealthy;
  bool contactorOpen;
};

static bool allSafetyHealthy(const SafetyInputs& s) {
  return s.rcdHealthy && s.rdcDdHealthy && s.emergencyStopHealthy &&
         s.peHealthy && s.phaseHealthy && s.temperatureHealthy &&
         s.hardwareInterlockHealthy;
}

// Always call this output path before any recovery attempt. The external
// hardwired safety chain remains the primary contactor shutdown mechanism.
static bool contactorRequest(EvseState state, const SafetyInputs& safety,
                            bool vehicleRequestsEnergy) {
  if (state != EvseState::Ready && state != EvseState::Charging) return false;
  if (!allSafetyHealthy(safety)) return false;
  if (!safety.contactorOpen && state == EvseState::Ready) return false;
  return vehicleRequestsEnergy;
}
