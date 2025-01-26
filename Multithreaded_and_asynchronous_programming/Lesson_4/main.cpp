//#include <stdio.h>
//#include <string.h>
//#include <iostream>
//#include <ws2tcpip.h>
//#include <winsock.h>
//#include <winsock2.h>
//
//#define PORT  8080 
//#define MAXLINE 1024
//


//int main_q() {
//	int sockfd;
//	char buffer[MAXLINE];
//	const char* hello = "Hello from client";
//	struct sockaddr_in  servaddr;
//	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
//		perror("socket creation failed");
//		exit(EXIT_FAILURE);
//	}
//	memset(&servaddr, 0, sizeof(servaddr));
//	servaddr.sin_family = AF_INET; servaddr.sin_port = htons(PORT);
//	servaddr.sin_addr.s_addr = INADDR_ANY;
//	socklen_t len;
//	sendto(sockfd, (const char*)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr*)&servaddr, sizeof(servaddr));
//	std::cout << "Hello message sent." << std::endl;
//	int size = recvfrom(sockfd, (char*)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr*)&servaddr, &len);
//	std::cout << "Server :" << buffer << std::endl;
//	close(sockfd);
//	return 0;
//}