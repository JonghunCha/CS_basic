/*
�� �ڵ�� TCP���� ���α׷����� ������ �ڵ��̴�.
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
//���� �߻��� ȣ��Ǵ� �Լ��� msg�� �ش��ϴ� ������ perror�� ����� ����
void error(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, clilen, pid;
    struct sockaddr_in cli_addr, serv_addr;

    char buff[30];

    //socketȣ��(�������� IPv4, TCP����� ���� SOCK_STREAM)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("server : socket() error");
    }

    //���� �ּ� ����
    bzero((void*)&serv_addr, sizeof(serv_addr));    //serv_addr 0���� �ʱ�ȭ
    serv_addr.sin_family = AF_INET; //IPv4���
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //������ IP�ּ� ����
    serv_addr.sin_port = htons(SERV_TCP_PORT);  //�������� ����� ��Ʈ��ȣ ����

    //������ IP�ּҿ� ��Ʈ��ȣ�� socket descriptor�� �Ҵ�
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("server : bind() error");
    }

    //�����û�� ���(��� ť�� ũ�� 5�� ����)
    listen(sockfd, 5);

    //������ ����ؼ� �����ϸ� sockfd�� ��û�� ������ �� ������ �޾Ƶ��δ�
    clilen = sizeof(cli_addr);
    while (1) {
        //newsockfd�� ��û�� ������ �� �ش� ��û�� ó���ϴ� socket descriptor
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
        if (newsockfd < 0) {
            error("server : accept() error");
        }
        //������ �� �ٸ� ��û�� �޾ƾ� �ϱ� ������ fork�� ���� �ڽ� ���μ����� Ŭ���̾�Ʈ�� ��û�� ó��
        pid = fork();
        if (pid == 0) {
            //�ڽ����μ������� ������ sockfd�� �ʿ����
            close(sockfd);
            //Ŭ���̾�Ʈ�κ��� �� �޽����� �а� ���
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