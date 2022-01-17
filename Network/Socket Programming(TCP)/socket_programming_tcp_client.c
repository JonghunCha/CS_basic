/*
이 코드는 TCP소켓 프로그래밍의 클라이언트측 코드이다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 7000
#define SERV_HOST_ADDR "서버가 위치한 ip주소"

void error(char* msg) {
	perror(msg);
	exit(1);
}

int main(int argc, char* argv[]) {
	int sockfd;
	struct sockaddr_in serv_addr;

	//socket호출(도메인은 IPv4, TCP통신을 위한 SOCK_STREAM)
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		error("server : socket() error");
	}

	//서버 주소 설정
	bzero((void*)&serv_addr, sizeof(serv_addr));    //serv_addr 0으로 초기화
	serv_addr.sin_family = AF_INET; //IPv4통신
	serv_addr.sin_addr.s_addr = htonl(SERV_HOST_ADDR);  //서버의 IP주소 설정
	serv_addr.sin_port = htons(SERV_TCP_PORT);  //서버에서 사용할 포트번호 설정

	//서버에 연결을 요청
	if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
		error("client : connect() error");
	}

	//sockfd를 통해 서버에 데이터 전송
	if (write(sockfd, "Hello World", 20) < 20) {
		error("client : write() error");
	}
	close(sockfd);

	return 0;
}