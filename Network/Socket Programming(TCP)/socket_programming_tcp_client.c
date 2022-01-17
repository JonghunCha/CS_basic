/*
�� �ڵ�� TCP���� ���α׷����� Ŭ���̾�Ʈ�� �ڵ��̴�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 7000
#define SERV_HOST_ADDR "������ ��ġ�� ip�ּ�"

void error(char* msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char* argv[]) {
	int sockfd;
	struct sockaddr_in serv_addr;

	//socketȣ��(�������� IPv4, TCP����� ���� SOCK_STREAM)
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		error("server : socket() error");
	}

	//���� �ּ� ����
	bzero((void*)&serv_addr, sizeof(serv_addr));    //serv_addr 0���� �ʱ�ȭ
	serv_addr.sin_family = AF_INET; //IPv4���
	serv_addr.sin_addr.s_addr = htonl(SERV_HOST_ADDR);  //������ IP�ּ� ����
	serv_addr.sin_port = htons(SERV_TCP_PORT);  //�������� ����� ��Ʈ��ȣ ����

	//������ ������ ��û
	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		error("client : connect() error");
	}

	//sockfd�� ���� ������ ������ ����
	if (write(sockfd, "Hello World", 20) < 20) {
		error("client : write() error");
	}
	close(sockfd);

	return 0;
}