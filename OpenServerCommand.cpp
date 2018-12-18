#include "OpenServerCommand.h"

int OpenServerCommand::doCommand(vector<string> array) {
    vector<string>::iterator it = array.begin();
    if(Isnumber(*it)) {
        port = stoi(*it);
    }
    if(Isnumber(*(it+1))) {
        hertz = stoi(*(it+1));
    }
    if((port != -1) && (hertz != -1)) {
        int server_fd, new_socket, valread;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[1024] = {0};
        string hello = "Hello from server";
        // Creating socket file descriptor
        if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        {
               throw runtime_error("socket failed");
        }

        // Forcefully attaching socket to the port 8080
        if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                           &opt, sizeof(opt)))
        {
            throw runtime_error("setsockopt");
        }
            address.sin_family = AF_INET;
            address.sin_addr.s_addr = INADDR_ANY;
            address.sin_port = htons( port );

            // Forcefully attaching socket to the port 8080
            if (bind(server_fd, (struct sockaddr *)&address,
                     sizeof(address))<0)
            {
                throw runtime_error("bind failed");
            }
            if (listen(server_fd, 3) < 0)
            {
                throw runtime_error("listen");
            }
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                     (socklen_t*)&addrlen))<0)
            {
                throw runtime_error("accept");

            }
            valread = read( new_socket , buffer, 1024);
            cout << buffer << endl;
            send(new_socket ,hello.c_str(),hello.length() , 0 );
            cout << "Hello message sent\n";
        }
    return parametersNum + 1;
}

bool OpenServerCommand::Isnumber(string s) {
    for(int i =0; i<s.length(); i++) {
        if(((s[i]<'0') || (s[i]>'9'))) {
            return false;
        }
    }
    return true;
}