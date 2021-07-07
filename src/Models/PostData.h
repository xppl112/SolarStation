struct PostData {
    long timestamp;

    float temperature;
    float humidity;

    float solarVoltage;
    float solarCurrent;
    float batteryVoltage;
    float arduinoVoltage;
    float gsmVoltage;

    bool isSafeMode;
    bool isEconomyMode;
    int restartsCount;
    int gsmErrors;
};