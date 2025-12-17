
/*
 * краткая сводка по архитектуре вялый ты человек -
 * * handle_connection - у нас будет тут, а класс ConnectionAcceptor будет в базовом сервере
 * * Удалить handle_connection из SessionManager
 * * Сервер оперирует только SessionManager и ConnectionAcceptor
 * * При инициализации сервера нам надо чтобы при получении нового подключения в connectionAcceptor бы вызывали регистрацию в SessionManager . Подсказка CALLBACK and fuctional lib
 * * Теперь у нас есть сессия с клиентом. Что дальше? Дальше нам надо обрабатывать пакеты передаваемой информации.
 * * посколько система масштабируемая мы делаем так, что любой пакет - тип, размер, данные.
 * * в будущем надо закинуть сюда шифрование и дешифрование. (Но это уже будут отдельные классы encrypt и decrypt), коды шифрования в которой будут как то круто работать.
 TODO  В принципе все
 */

#ifndef NETWORKAPP_CONNECTIONACCEPTOR_H
#define NETWORKAPP_CONNECTIONACCEPTOR_H

#include <boost/asio.hpp>
#include <functional>
#include <Singleton.hpp>

class ConnectionAcceptor : public Singleton<ConnectionAcceptor> {
public:
    explicit ConnectionAcceptor(boost::asio::io_context& accept_context, unsigned short accept_port);
    explicit ConnectionAcceptor();

    void WaitConnectionAccept();

    void SetConfig(boost::asio::io_context accept_context ,unsigned short accept_port);

private:
    unsigned short port_;
    boost::asio::ip::tcp::endpoint endpoint_;
    boost::asio::ip::tcp::acceptor acceptor_;
};


#endif //NETWORKAPP_CONNECTIONACCEPTOR_H
