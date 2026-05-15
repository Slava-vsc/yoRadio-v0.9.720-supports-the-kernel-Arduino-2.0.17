#ifndef utf8RusGFX_h
#define utf8RusGFX_h

char* DspCore::utf8Rus(const char* str, bool uppercase) {
  static char strn[BUFLEN];
  strlcpy(strn, str, BUFLEN);

  int i = 0, j = 0;
  while (strn[i]) {
    uint8_t c = (uint8_t)strn[i];

    // --- Two-byte UTF-8 Cyrillic ---
    if ((c == 0xD0 || c == 0xD1) && strn[i + 1]) {
      uint8_t n = (uint8_t)strn[i + 1];
      uint8_t ch = 0;

      if (c == 0xD0) {
        if (n == 0x81) ch = 0xA8;      // Ё
        else if (n == 0x84) ch = 0xAA; // Ґ
        else if (n == 0x86) ch = 0xB2; // І
        else if (n == 0x87) ch = 0xAF; // Ї
        else if (n >= 0x90 && n <= 0xBF) ch = n + 0x30; // А–п
      } else if (c == 0xD1) {
        if (n == 0x91) ch = 0xB8;      // ё
        else if (n == 0x94) ch = 0xBA; // ґ
        else if (n == 0x96) ch = 0xB3; // і
        else if (n == 0x97) ch = 0xBF; // ї
        else if (n >= 0x80 && n <= 0x8F) ch = n + 0x70; // р–я
      }

      if (ch) strn[j++] = uppercase ? toupper(ch) : ch;
      i += 2;
    }
    else {
      // --- ASCII or single-byte symbols ---
      strn[j++] = uppercase ? toupper(c) : c;
      i++;
    }
  }

  strn[j] = '\0';
  return strn;
}

#endif
