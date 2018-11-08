#pragma once

#include "ControllerBase.hpp"

namespace web::json
{
    class value;
}

namespace service::controllers
{
    class Test : public ControllerBase
    {
      public:
        Test( std::shared_ptr< db::ConnectorIface > dbConnector );
        ~Test() override;

      private:
        void handleGet( const web::http::http_request & message ) const override;
    };
} // namespace service::controllers