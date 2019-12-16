#include <netdb.h>
#include <cstring>
#include <iostream>
#include <sstream>

using namespace std;

void setHttpServer(){
    int result;

    struct addrinfo hints;
    struct addrinfo *addr;
    socklen_t addr_size;
    struct sockaddr_storage storage;

    memset(&hints,0,sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    result = getaddrinfo(NULL,"10995",&hints,&addr);


    int server_socket;
    server_socket = socket(addr->ai_family,addr->ai_socktype,addr->ai_protocol);

    bind(server_socket,addr->ai_addr,addr->ai_addrlen);

    listen(server_socket,5);

    int acc = 0;

    for(;;){

        stringstream response;
        stringstream response_body;
        char buffer[1024];



        addr_size = sizeof addr;
        acc = accept(server_socket,NULL,NULL);

        result = recv(acc,buffer,1024,0);

        cout << result << endl;
        cout << buffer <<endl;

        if(result == -1){
            break;
        }

        response_body << "<title>C++ HTTP </title>\n"
                      << "<h1>Lol kek cheburek</h1>\n"
                      << "<p>This is body of kek lol arbidol</p>\n"
                      << "<h2>Request headers</h2>\n"
                      << "<pre>" << buffer << "</pre>\n"
                      << "<em><small>Small tag</small></em>\n";

        response << "HTTP/1.1 200 OK\r\n"
                 << "Version: HTTP/1.1\r\n"
                 << "Content-Type: text/html; charset=utf-8\r\n"
                 << "Content-Length: " << response_body.str().length()
                 << "\r\n\r\n"
                 << response_body.str();

        result = send(acc,response.str().c_str(),response.str().length(),0);

        cout << result << endl;





    }
}