#include "server.h"
#include <QtNetwork>
#include <QString>
    using namespace std;



server::server()
{



    m_blockSize = 0;
    QNetworkConfigurationManager manager;
     QNetworkConfiguration config = manager.defaultConfiguration();
     m_network_session = new QNetworkSession(config, this);

     // La méthode sessionOuverte sera appelée sur le signal opened
     connect( m_network_session, SIGNAL(opened()), this,
                    SLOT(sessionOuverte()) );

     // Ouverture de la session
     m_network_session->open();

     // La méthode connexionClient sera appelée sur le signal newConnection
     connect( m_tcp_server, SIGNAL(newConnection()), this,
              SLOT(connexionClient()) );
}


void Server::sessionOuverte()
{
 m_tcp_server = new QTcpServer(this); // instanciation
// on écoute sur le port 53000
 if (!m_tcp_server->listen(QHostAddress::Any, 53000))
 {
 std::cout << "Le serveur n'a pas été correctement
lance." << std::endl;
 }
 else
 {
 std::cout << "Le serveur est pret \n\nIP: " <<
m_tcp_server->serverAddress().toString().toStdString()
 << std::endl << "port: " << m_tcp_server->serverPort()
<< std::endl
 << "Lancez l'application Client maintenant."
<< std::endl;
 }
}
