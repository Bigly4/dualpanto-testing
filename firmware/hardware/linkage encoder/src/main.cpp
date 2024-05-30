#include <Encoder.h>
#include "Arduino.h"
#include <SPI.h>
#include <vector>

static const uint32_t c_hspiSsPin1 = 15;
static const uint32_t c_hspiSsPin2 = 5;
static const uint16_t c_nop = 0x0;
static const uint16_t c_clearError = 0x4001;
static const uint16_t c_readAngle = 0xFFFF; // 0xFFFF
static const uint16_t c_dataMask = 0x3FFF;

static const uint16_t endeffectorEncoderPin[2] = {35, 36};
static const uint16_t endeffectorEncoderPin2[2] = {34, 39};
Encoder *endeffectorEncoder[2];

std::vector<uint16_t> m_values;

int incomingByte = 0; // for incoming serial data
SPIClass m_spi(HSPI);
SPISettings m_settings(10000000, SPI_MSBFIRST, SPI_MODE1);

int channel = 0;
int c_i = 0;
uint16_t buf = 0;

void setup()
{
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

    pinMode(13, OUTPUT);
    pinMode(c_hspiSsPin1, OUTPUT);
    pinMode(c_hspiSsPin2, OUTPUT);

    for (int i = 0; i < 2; i++)
    {
        pinMode(endeffectorEncoderPin[i], INPUT);
        pinMode(endeffectorEncoderPin2[i], INPUT);
        endeffectorEncoder[i] = new Encoder(
            endeffectorEncoderPin[i], endeffectorEncoderPin2[i]);
    }

    m_values.resize(4, 0);

    m_spi.begin();
}

void loop()
{
    m_spi.beginTransaction(m_settings);
    digitalWrite(13, HIGH);
    digitalWrite(c_hspiSsPin1, HIGH);
    digitalWrite(c_hspiSsPin2, HIGH);

    if (channel == 0)
    {
        digitalWrite(c_hspiSsPin2, LOW);
    }
    else if (channel == 1)
    {
        digitalWrite(c_hspiSsPin1, LOW);
    }
    for (auto i = 0; i < m_values.size() / 2; ++i)
    {
        buf = m_spi.transfer16(c_readAngle);
        // Serial.printf("%d", buf);
        // Serial.println();
    }
    digitalWrite(c_hspiSsPin1, HIGH);
    digitalWrite(c_hspiSsPin2, HIGH);

    delayMicroseconds(1);

    if (channel == 0)
    {
        Serial.printf("\ndptest");
    }

    if (channel == 0)
        digitalWrite(c_hspiSsPin2, LOW);
    else if (channel == 1)
        digitalWrite(c_hspiSsPin1, LOW);
    for (auto i = 0; i < m_values.size() / 2; ++i)
    {
        buf = m_spi.transfer16(c_nop);
        m_values[i + channel * 2] = buf & c_dataMask;
        Serial.printf("%d,", m_values[i + channel * 2]);
    }
    digitalWrite(c_hspiSsPin1, HIGH);
    digitalWrite(c_hspiSsPin2, HIGH);

    m_spi.endTransaction();

    if (channel == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            Serial.printf("%d,", endeffectorEncoder[i]->read());
        }
    }

    c_i++;
    channel = c_i % 2;
}