project(BaseServer)

SET(DEPENDS_LIST
        INetworkApp
        ISession
        SessionManager
        ConnectionAcceptor
        Boost::filesystem
    )
SET(ADDITIONAL_INCLUDE_DIR
        ${Boost_INCLUDE_DIRS}
        )

include(lib)