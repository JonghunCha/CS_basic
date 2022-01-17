/*
이 코드는 TCP소켓 프로그래밍의 서버측 코드이다.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 7000
//에러 발생시 호출되는 함수로 msg에 해당하는 문구를 perror로 출력후 종료
void error(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, clilen, pid;
    struct sockaddr_in cli_addr, serv_addr;

    char buff[30];

    //socket호출(도메인은 IPv4, TCP통신을 위한 SOCK_STREAM)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("server : socket() error");
    }

    //서버 주소 설정
    bzero((void*)&serv_addr, sizeof(serv_addr));    //serv_addr 0으로 초기화
    serv_addr.sin_family = AF_INET; //IPv4통신
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //서버의 IP주소 설정
    serv_addr.sin_port = htons(SERV_TCP_PORT);  //서버에서 사용할 포트번호 설정

    //서버의 IP주소와 포트번호를 socket descriptor에 할당
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("server : bind() error");
    }

    //연결요청을 대기(대기 큐의 크기 5로 설정)
    listen(sockfd, 5);

    //서버는 계속해서 동작하며 sockfd에 요청이 들어왔을 때 연결을 받아들인다
    clilen = sizeof(cli_addr);
    while (1) {
        //newsockfd는 요청이 들어왔을 때 해당 요청을 처리하는 socket descriptor
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
        if (newsockfd < 0) {
            error("server : accept() error");
        }
        //서버는 또 다른 요청을 받아야 하기 때문에 fork를 통해 자식 프로세스가 클라이언트의 요청을 처리
        pid = fork();
        if (pid == 0) {
            //자식프로세스에선 기존의 sockfd는 필요없음
            close(sockfd);
            //클라이언트로부터 온 메시지를 읽고 출력
            if (read(newsockfd, buff, 29) <= 0) {
                error("server : read() error");
            }
            printf("Server : Received String = %s\n", buff);
            close(newsockfd);
            exit(0);
        }
        close(newsockfd);
        if (pid < 0) {
            error("server : fork() error");
        }
    }
    close(sockfd);

    return 0;
}