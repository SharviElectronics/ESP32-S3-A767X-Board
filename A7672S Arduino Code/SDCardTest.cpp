#include <SPI.h>
#include <SD.h>

// MicroSD SPI Pins
#define SD_CS    46
#define SD_MOSI  4
#define SD_SCK   5
#define SD_MISO  6

void setup() {

  // USB Serial Monitor
  Serial.begin(115200);
  delay(1000);

  Serial.println("Initializing MicroSD Card...");

  // Start SPI with custom pins
  SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  // Initialize SD card
  if (!SD.begin(SD_CS, SPI)) {
    Serial.println("❌ SD Card initialization failed!");
    return;
  }

  Serial.println("✅ SD Card initialized successfully!");

  // Print card type
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD card attached.");
    return;
  }

  Serial.print("Card Type: ");
  if (cardType == CARD_MMC) Serial.println("MMC");
  else if (cardType == CARD_SD) Serial.println("SDSC");
  else if (cardType == CARD_SDHC) Serial.println("SDHC");
  else Serial.println("UNKNOWN");

  // Print card size
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("Card Size: %llu MB\n", cardSize);
}

void loop() {
}
