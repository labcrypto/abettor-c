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
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <org/labcrypto/abettor/net/udp.h>


ORG_LABCRYPTO_ABETTOR_socket_fd
ORG_LABCRYPTO_ABETTOR__net__UDP_server__bind_on_ipv4_address (
  ORG_LABCRYPTO_ABETTOR_ip_v4_address bind_ipv4_address,
  ORG_LABCRYPTO_ABETTOR_port bind_port
) {
  int sockfd;
  struct sockaddr_in serveraddr;
  int optval;
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    printf("ERROR opening socket.\n");
  }
  optval = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, 
       (const void *)&optval , sizeof(int));
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = inet_addr(bind_ipv4_address);
  serveraddr.sin_port = htons((unsigned short)bind_port);
  if (bind(sockfd, (struct sockaddr *) &serveraddr, 
     sizeof(serveraddr)) < 0) {
    printf("ERROR on binding.\n");
    return 0;
  }
  return sockfd;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__net__UDP_server__send_data (
  ORG_LABCRYPTO_ABETTOR_socket_fd server_socket_fd,
  ORG_LABCRYPTO_ABETTOR_data data,
  ORG_LABCRYPTO_ABETTOR_length data_length
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_length
ORG_LABCRYPTO_ABETTOR__net__UDP_server__receive_data (
  ORG_LABCRYPTO_ABETTOR_socket_fd server_socket_fd,
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_length buffer_length
) {
  // TODO
  return 0;
}


ORG_LABCRYPTO_ABETTOR_void
ORG_LABCRYPTO_ABETTOR__net__UDP_client__send_data (
  ORG_LABCRYPTO_ABETTOR_hostname target_host,
  ORG_LABCRYPTO_ABETTOR_port target_port,
  ORG_LABCRYPTO_ABETTOR_data data,
  ORG_LABCRYPTO_ABETTOR_length data_length
) {
  // TODO
}


ORG_LABCRYPTO_ABETTOR_length
ORG_LABCRYPTO_ABETTOR__net__UDP_client__receive_data (
  ORG_LABCRYPTO_ABETTOR_hostname target_host,
  ORG_LABCRYPTO_ABETTOR_port target_port,
  ORG_LABCRYPTO_ABETTOR_data buffer,
  ORG_LABCRYPTO_ABETTOR_length buffer_size
) {
  // TODO
  return 0;
}
