#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork>

class server
{
public:
    server();


private:
    void sessionOuverte();
    void connexionClient();
    void lireTexte();

    QTcpServer *m_tcp_server; // La socket général
    QTcpSocket *m_socket_client; // La socket client
    QNetworkSession *m_network_session;
    quint16 m_blockSize;
};

#endif // SERVER_H
