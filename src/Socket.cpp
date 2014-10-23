#include "Socket.h"

#include <iostream>

#ifdef _MSC_VER
#include <WS2tcpip.h>
#include <WinSock2.h>
#else
//#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>
#endif

using std::cout;

namespace sd
{
	bool ServerSocket::Create()
	{
		sock = socket(af, type, proto);
		return (sock >= 0);
	}

	bool  ServerSocket::Bind(const std::string& address)
	{
		

		memset(&sockAddress, 0, sizeof(sockAddress));
		sockAddress.sin_port = htons(port);
		if (address.empty())
		{
			sockAddress.sin_addr.s_addr = INADDR_ANY;
		}
		else
		{
			inet_pton(AF_INET, address.c_str(), &sockAddress.sin_addr);
		}

		int error = bind(sock, (const sockaddr *)&sockAddress, sizeof(sockAddress));
		
		return (error == 0);
	}

	bool ServerSocket::Start(const std::string& address, const unsigned int thePort)
	{
		if (port > 0)
		{
			SetPort(thePort);
		}

		if (Create() && Bind(address))
		{
			return (0 == listen(sock, SOMAXCONN));
		}
	}
	//http://www.binarytides.com/multiple-socket-connections-fdset-select-linux/
	void ServerSocket::Run()
	{
		SOCKET max_sd = 0, sd, newSock;
		int activity = 0, valread = 0;

		int addrlen = sizeof(sockAddress);
		char addressStr[INET_ADDRSTRLEN];

		//a message
		std::string message = "ECHO Daemon v1.0 \r\n";
		char buffer[1025];  //data buffer of 1K
		cout << "Running Server..." << std::endl;

		while (true)
		{
			//clear the socket set
			FD_ZERO(&fdSockets);

			//add master socket to set
			FD_SET(sock, &fdSockets);
			max_sd = sock;

			//add child sockets to set
			for (unsigned int i = 0; i < MAX_CLIENTS; i++)
			{
				//socket descriptor
				sd = m_clientsPtr[i];

				//if valid socket descriptor then add to read list
				if (sd > 0)
					FD_SET(sd, &fdSockets);

				//highest file descriptor number, need it for the select function
				if (sd > max_sd)
					max_sd = sd;
			}

			//wait for an activity on one of the sockets , timeout is NULL , so wait indefinitely
			activity = select(max_sd + 1, &fdSockets, NULL, NULL, NULL);

			if ((activity < 0) && (errno != EINTR))
			{
				cout <<"select error";
			}

			//If something happened on the master socket , then its an incoming connection
			if (FD_ISSET(sock, &fdSockets))
			{
				if ((newSock = accept(sock, (struct sockaddr *)&sockAddress, (socklen_t*)&addrlen))<0)
				{
					perror("accept");
					exit(EXIT_FAILURE);
				}

				
				inet_ntop(AF_INET, &sockAddress.sin_addr, addressStr, INET_ADDRSTRLEN);
				//inform user of socket number - used in send and receive commands
				printf("New connection , socket fd is %d , ip is : %s , port : %d \n", newSock, addressStr, ntohs(sockAddress.sin_port));

				//send new connection greeting message
				if (send(newSock, message.c_str(), message.size(), 0) != message.size())
				{
					perror("send");
				}

				cout<<"Welcome message sent successfully"<<std::endl;

				//add new socket to array of sockets
				for (unsigned int i = 0; i < MAX_CLIENTS; i++)
				{
					//if position is empty
					if (m_clientsPtr[i] == 0)
					{
						m_clientsPtr[i] = newSock;
						printf("Adding to list of sockets as %d\n", i);

						break;
					}
				}
			}

			//else its some IO operation on some other socket :)
			for (unsigned int i = 0; i < MAX_CLIENTS; i++)
			{
				sd = m_clientsPtr[i];

				if (FD_ISSET(sd, &fdSockets))
				{
					//Check if it was for closing , and also read the incoming message
					if ((valread = recv(sd, buffer, 1024, 0)) == 0)
					{
						//Somebody disconnected , get his details and print
						getpeername(sd, (struct sockaddr*)&sockAddress, (socklen_t*)&addrlen);
						inet_ntop(AF_INET, &sockAddress.sin_addr, addressStr, INET_ADDRSTRLEN);
						printf("Host disconnected , ip %s , port %d \n", addressStr, ntohs(sockAddress.sin_port));

						//Close the socket and mark as 0 in list for reuse
#ifdef _MSC_VER
						closesocket(sd);
#else
						close(sd);
#endif
						
						m_clientsPtr[i] = 0;
					}

					//Echo back the message that came in
					else
					{
						//set the string terminating NULL byte on the end of the data read
						buffer[valread] = '\0';
						send(sd, buffer, strlen(buffer), 0);
					}
				}
			}
		}
	
	}



	bool ClientSocket::Create()
	{
		sock = socket(af, type, proto);
		return (sock >= 0);
	}

	void ClientSocket::Run()
	{
		cout << "Running Server..." << std::endl;

		if (connect(sock, (struct sockaddr *)&sockAddress, sizeof(sockAddress)) < 0)
		{
			printf("\n Error : Connect Failed \n");
			return 1;
		}
	}

	bool ClientSocket::Start(const std::string& address, const unsigned int thePort)
	{
		if (port > 0)
		{
			SetPort(thePort);
		}

		return true;
	}
}
