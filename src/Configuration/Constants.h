#pragma once

namespace Constants
{
    namespace General
    {
        constexpr float FactorWhToKWh = 0.001f;
        constexpr uint32_t MillisPerSecond = 1000;
    };

    namespace ModbusRTU
    {
        constexpr uint8_t RegisterSize = 2;
        constexpr uint16_t NumReadRetries = 3;
        constexpr uint16_t NumWriteRetries = 5;
        constexpr uint16_t RetryDelayMs = 25;
    };

    namespace HeidelbergWallbox
    {
        constexpr uint32_t ModbusTimeoutMs = 2000;
        constexpr uint32_t ModbusBaudrate = 19200;
        constexpr float InitialChargingCurrentLimitA = 16.0f;
        constexpr float CurrentFactor = 0.1f;
        constexpr float VoltageFactor = 1.0f;            // Add missing constant
        constexpr float TemperatureFactor = 0.1f;        // Add missing constant
        constexpr float FailSafeCurrentA = 16.0f;        // Add missing constant
        constexpr bool AllowStandby = true;              // Add missing constant
        constexpr uint16_t WatchdogTimeoutS = 60;        // Add missing constant
        constexpr uint8_t ModbusServerId = 1;            // Add missing constant
    };

    namespace HeidelbergRegisters
    {
        constexpr uint16_t WatchdogTimeout = 257;
        constexpr uint16_t DisableStandby = 258;
        constexpr uint16_t LockStatus = 259;        // Add lock status register
        constexpr uint16_t ChargingState = 5;
        constexpr uint16_t MaximalCurrent = 261;
        constexpr uint16_t Power = 14;
        constexpr uint16_t Energy = 17;
        constexpr uint16_t FailsafeCurrent = 262;
        constexpr uint16_t Currents = 6;
        constexpr uint16_t Voltages = 10;
        constexpr uint16_t PcbTemperature = 9;
    };

    namespace DummyWallbox
    {
        constexpr float ChargingVoltageV = 230.0f;
        constexpr uint8_t NumPhases = 3;
        constexpr float MaxChargingCurrentA = 16.0f;
        constexpr float FailSafeCurrentA = 16.0f;
        constexpr float TemperatureDegCel = 23.4f;
        constexpr float InitialChargingCurrentLimitA = 16.0f;
    };

    namespace DaheimladenRegisters
    {
        constexpr uint16_t Status = 0;
        constexpr uint16_t LimitChargingCurrent = 91;
        constexpr uint16_t ConnectionTimeoutTime = 89;
        constexpr uint16_t EnergyMeter = 28;
        constexpr uint16_t TotalChargingPower = 12;
        constexpr uint16_t ChargeCurrents = 6;
        constexpr uint16_t ChargeVoltages = 109;
        constexpr uint16_t MaxChargingCurrentAfterConnectionLoss = 87;
        constexpr uint16_t RfidStationId = 38;
        constexpr uint16_t RfidCardId = 54;
    };

    namespace DaheimladenWallbox
    {
        constexpr uint8_t ServerId = 0xFF;
        constexpr uint16_t TCPPort = 502;
        constexpr uint8_t MaxClients = 8;
        constexpr uint32_t TimeoutMs = 60000;
        constexpr float VoltageFactor = 10.0f;
        constexpr float CurrentFactor = 10.0f;
        constexpr float EnergyFactor = 0.01f;
    };

    namespace WiFi
    {
        constexpr uint16_t MaxNumWifiClients = 8;
        constexpr uint32_t ConnectionTimeoutMs = 30000;
        constexpr uint32_t CaptivePortalTimeoutS = 5 * 60;
    };

    namespace WebServer
    {
        constexpr bool Enabled = true;
        constexpr uint16_t Port = 80;
        extern const char* CaptivePortalName;
        extern const char* LocalIpUrl;
    };

    namespace MQTT
    {
        constexpr uint16_t PublishIntervalMs = 500;
    };

#ifdef RELAY_LOCK_ENABLED
    namespace RelayLock
    {
        constexpr bool RelayActiveHigh = true;      // Relay is active when pin is HIGH
        constexpr uint32_t DebounceMs = 100;        // Debounce time for relay state changes
    };
#endif
};
