#pragma once

enum class VehicleState
{
    Unknown,
    NotConnected,
    Connected,
    Charging,
    Error
};

class IWallbox
{
public:
    virtual ~IWallbox() = default;

    virtual void Init() = 0;
    virtual VehicleState GetState() = 0;
    virtual bool SetChargingCurrentLimit(float currentLimitA) = 0;
    virtual bool SetChargingEnabled(bool chargingEnabled) = 0;
    virtual float GetChargingCurrentLimit() = 0;
    virtual float GetEnergyMeterValue() = 0;
    virtual float GetFailsafeCurrent() = 0;
    virtual float GetChargingPower() = 0;
    virtual float GetTemperature() = 0;
    virtual bool GetChargingCurrents(float &c1A, float &c2A, float &c3A) = 0;
    virtual bool GetChargingVoltages(float &v1V, float &v2V, float &v3V) = 0;
    virtual bool IsChargingEnabled() = 0;

#ifdef RELAY_LOCK_ENABLED
    virtual bool GetLockStatus() = 0;
#endif
};