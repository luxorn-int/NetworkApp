project(BaseServer)

SET(DEPENDS_LIST
        INetworkApp
        ISession
        SessionManager
        Boost::filesystem
    )
SET(ADDITIONAL_INCLUDE_DIR
        ${Boost_INCLUDE_DIRS}
        )

include(lib)