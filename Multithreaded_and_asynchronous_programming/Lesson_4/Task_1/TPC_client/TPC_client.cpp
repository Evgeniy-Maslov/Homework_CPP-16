#include <iostream>
#include <ws2tcpip.h>
#include <winsock.h>
#include <winsock2.h>


int main()
{
	const char* hello = "Hello from client";
	const char* buf = "1024";
	size_t strlen_helo = std::strlen(hello);
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 6);
	if (sockfd < 0)
	{
		std::perror("socket creation failed");
		std::exit(EXIT_FAILURE);
	}
	struct sockaddr_in* servaddr{};
	servaddr->sin_family = AF_INET;
	servaddr->sin_addr.S_un.S_addr = INADDR_ANY;
	servaddr->sin_port = htons(1234);


	connect(sockfd, (SOCKADDR*)&servaddr, sizeof(servaddr));
	send(sockfd, hello, strlen_helo, MSG_DONTROUTE);
	recv(sockfd, (char*)buf, strlen_helo, MSG_WAITALL);

	return 0;
}