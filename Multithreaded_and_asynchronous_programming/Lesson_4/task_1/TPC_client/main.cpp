#include <iostream>
#include <ws2tcpip.h>
#include <winsock.h>
#include <winsock2.h>


int main()
{
	const char* hello = "Hello from client";


	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	int connect(int sockfd, const struct sockaddr* addr, socklen_t addrlen);
	size_t send(int sockfd, const void* hello, size_t strlen(hello), int flags);
	size_t recv(int sockfd, const void* buf, size_t len, int flags);
	return 0;
}