#include <iostream>
#include <ws2tcpip.h>
#include <winsock.h>
#include <winsock2.h>

int main()
{
	SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 6);
	char buffer[1024];
	const char* hello = "Hello from server";
	if (sockfd < 0) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	struct sockaddr_in servaddr, cliaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.S_un.S_addr = INADDR_ANY;
	servaddr.sin_port = htons(1234);

	cliaddr.sin_family = AF_INET;
	cliaddr.sin_addr.S_un.S_addr = INADDR_ANY;
	cliaddr.sin_port = htons(1234);

	if (bind(sockfd, (SOCKADDR*)&servaddr, sizeof(servaddr)) < 0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	socklen_t len = sizeof(cliaddr);
	int n = recvfrom(sockfd, (char*)buffer, 1024, MSG_WAITALL, (struct sockaddr*)&cliaddr, &len);
	printf("Client : %s\n", buffer);
	sendto(sockfd, (const char*)hello, strlen(hello), MSG_DONTROUTE, (const struct sockaddr*)&cliaddr, len);
	std::cout << "Hello message sent." << std::endl;

	return 0;
}
