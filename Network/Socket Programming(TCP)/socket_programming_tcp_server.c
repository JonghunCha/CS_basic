/*
�� �ڵ�� TCP���� ���α׷����� ������ �ڵ��̸�, Ŭ���̾�Ʈ�κ��� ���� �޽����� �ܼ��� ������ִ� ��ɸ� �����Ͽ���.
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERV_TCP_PORT 7000
#define SERV_HOST_ADDR "58.79.216.156"
//���� �߻��� ȣ��Ǵ� �Լ��� msg�� �ش��ϴ� ������ perror�� ����� ����
void error(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    int sockfd, newsockfd, clilen;
    char* pname;

    struct sockaddr_in cli_addr, serv_addr;

    int pid;

    char buff[30];
    pname = argv[0];

    //socketȣ��(�������� IPv4, TCP����� ���� SOCK_STREAM)
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        puts("Server : socket() error");
        exit(1);
    }

    //���� �ּ� ����
    bzero((void*)&serv_addr, sizeof(serv_addr));    //serv_addr 0���� �ʱ�ȭ
    serv_addr.sin_family = AF_INET; //IPv4���
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);  //������ IP�ּ� ����
    serv_addr.sin_port = htons(SERV_TCP_PORT);  //�������� ����� ��Ʈ��ȣ ����

    //������ IP�ּҿ� ��Ʈ��ȣ�� socket descriptor�� �Ҵ�
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        puts("Server : bind() error");
        exit(1);
    }

    //�����û�� ���(��� ť�� ũ�� 5�� ����)
    listen(sockfd, 5);

    //������ ����ؼ� �����ϸ� sockfd�� ��û�� ������ �� ������ �޾Ƶ��δ�
    clilen = sizeof(cli_addr);
    while (1) {
        //newsockfd�� ��û�� ������ �� �ش� ��û�� ó���ϴ� socket descriptor
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);
        if (newsockfd < 0) {
            puts("Server : accept() error");
            exit(1);
        }
        //������ �� �ٸ� ��û�� �޾ƾ� �ϱ� ������ fork�� ���� �ڽ� ���μ����� Ŭ���̾�Ʈ�� ��û�� ó��
        pid = fork();
        if (pid == 0) {
            //�ڽ����μ������� ������ sockfd�� �ʿ����
            close(sockfd);
            //Ŭ���̾�Ʈ�κ��� �� �޽����� �а� ���
            if (read(newsockfd, buff, 29) <= 0) {
                puts("Server : read() error");
                exit(1);
            }
            printf("Server : Received String = %s\n", buff);
            close(newsockfd);
            exit(0);
        }
        close(newsockfd);
        if (pid < 0) {
            puts("Server : fork() error");
        }
    }
    close(sockfd);

    return 0;
}