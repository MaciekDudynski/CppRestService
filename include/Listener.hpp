#pragma once

#include "ListenerIface.hpp"

#include <memory>

namespace web::http::experimental::listener
{
    class http_listener;
}

namespace service
{
    namespace utils
    {
        class NetworkInfoProviderIface;
    }

    class DispatcherIface;

    class Listener : public ListenerIface
    {
      public:
        explicit Listener( const std::string & endpoint,
          std::unique_ptr< utils::NetworkInfoProviderIface > networkInfoProvider,
          std::unique_ptr< DispatcherIface > dispatcher );
        ~Listener() override;

        void start() override;
        void stop() override;

      private:
        std::unique_ptr< utils::NetworkInfoProviderIface > _networkInfoProvider;
        std::unique_ptr< DispatcherIface > _dispatcher;
        std::unique_ptr< web::http::experimental::listener::http_listener > _listener;

        ListenerState _currentState;
    };
} // namespace service
