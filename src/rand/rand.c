/*  The MIT License (MIT)
 *
 *  Copyright (c) 2015 LabCrypto Org.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include <org/labcrypto/abettor/rand.h>


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__rand__generate_8_bytes (
  ORG_LABCRYPTO_ABETTOR_data buffer
) {
  buffer[0] = 0x78;
  buffer[1] = 0x17;
  buffer[2] = 0x23;
  buffer[3] = 0x86;
  buffer[4] = 0x0c;
  buffer[5] = 0xff;
  buffer[6] = 0xff;
  buffer[7] = 0x26;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__rand__generate_16_bytes (
  ORG_LABCRYPTO_ABETTOR_data buffer
) {
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