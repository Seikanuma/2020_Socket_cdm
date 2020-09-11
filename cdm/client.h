#ifndef CLIENT_H
#define CLIENT_H
#include <QtNetwork>

class client
{
public:
    client();

private:
private slots:
 void lireTexte();
 void afficherErreur( QAbstractSocket::SocketError
 socketError);


 QTcpSocket *m_tcpSocket;
  quint16 m_blockSize;
  QNetworkSession *m_networkSession;

};

#endif // CLIENT_H
