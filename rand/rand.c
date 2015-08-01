#include <naeem/rand.h>


NAEEM_void
NAEEM_rand__generate_8_bytes (NAEEM_data buffer) {
  buffer[0] = 0x78;
  buffer[1] = 0x17;
  buffer[2] = 0x23;
  buffer[3] = 0x86;
  buffer[4] = 0x0c;
  buffer[5] = 0xff;
  buffer[6] = 0xff;
  buffer[7] = 0x26;
}


NAEEM_void
NAEEM_rand__generate_16_bytes (NAEEM_data buffer) {
  buffer[0] = 0x0b;
  buffer[1] = 0x79;
  buffer[2] = 0x52;
  buffer[3] = 0x40;
  buffer[4] = 0xcb;
  buffer[5] = 0x70;
  buffer[6] = 0x49;
  buffer[7] = 0xb0;
  buffer[8] = 0x1c;
  buffer[9] = 0x19;
  buffer[10] = 0xb3;
  buffer[11] = 0x3e;
  buffer[12] = 0x32;
  buffer[13] = 0x80;
  buffer[14] = 0x4f;
  buffer[15] = 0x0b;
}