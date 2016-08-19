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
 
#ifndef _ORG_LABCRYPTO_ABETTOR__C__NET_UDP_H_
#define _ORG_LABCRYPTO_ABETTOR__C__NET_UDP_H_

#include <org/labcrypto/abettor/types.h>


#ifdef __cplusplus
extern "C" {
#endif


ORG_LABCRYPTO_ABETTOR_socket_fd
ORG_LABCRYPTO_ABETTOR__net__UDP_server__bind_on_ipv4_address (
  ORG_LABCRYPTO_ABETTOR_ip_v4_address /* Binding IPv4 address */,
  ORG_LABCRYPTO_ABETTOR_port /* Binding port */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__net__UDP_server__send_data (
  ORG_LABCRYPTO_ABETTOR_socket_fd /* Server socket FD */,
  ORG_LABCRYPTO_ABETTOR_data /* Buffer to be sent */,
  ORG_LABCRYPTO_ABETTOR_length /* Number of bytes to send */
);


ORG_LABCRYPTO_ABETTOR_length
ORG_LABCRYPTO_ABETTOR__net__UDP_server__receive_data (
  ORG_LABCRYPTO_ABETTOR_socket_fd /* Server socket FD */,
  ORG_LABCRYPTO_ABETTOR_data /* Buffer to be fill. */,
  ORG_LABCRYPTO_ABETTOR_length /* Maximum number of bytes */
);


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__net__UDP_client__send_data (
  ORG_LABCRYPTO_ABETTOR_hostname /* Target host */,
  ORG_LABCRYPTO_ABETTOR_port /* Target port */,
  ORG_LABCRYPTO_ABETTOR_data /* Buffer to be sent */,
  ORG_LABCRYPTO_ABETTOR_length /* Number of bytes to send */
);


ORG_LABCRYPTO_ABETTOR_length
ORG_LABCRYPTO_ABETTOR__net__UDP_client__receive_data (
  ORG_LABCRYPTO_ABETTOR_hostname /* Target host */,
  ORG_LABCRYPTO_ABETTOR_port /* Target port */,
  ORG_LABCRYPTO_ABETTOR_data /* Buffer to be fill. */,
  ORG_LABCRYPTO_ABETTOR_length /* Maximum number of bytes */
);


#ifdef __cplusplus
}
#endif

#endif