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

#include <naeem/net/udp.h>


NAEEM_socket_fd
NAEEM_net__UDP_server__bind_on_ipv4_address (
  NAEEM_ip_v4_address bind_ipv4_address,
  NAEEM_port bind_port
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


NAEEM_void
NAEEM_net__UDP_server__send_data (
  NAEEM_socket_fd server_socket_fd,
  NAEEM_data data,
  NAEEM_length data_length
) {
  // TODO
}


NAEEM_length
NAEEM_net__UDP_server__receive_data (
  NAEEM_socket_fd server_socket_fd,
  NAEEM_data buffer,
  NAEEM_length buffer_length
) {
  // TODO
  return 0;
}


NAEEM_void
NAEEM_net__UDP_client__send_data (
  NAEEM_hostname target_host,
  NAEEM_port target_port,
  NAEEM_data data,
  NAEEM_length data_length
) {
  // TODO
}


NAEEM_length
NAEEM_net__UDP_client__receive_data (
  NAEEM_hostname target_host,
  NAEEM_port target_port,
  NAEEM_data buffer,
  NAEEM_length buffer_size
) {
  // TODO
  return 0;
}
