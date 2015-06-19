#ifndef PROTON_CPP_BLOCKINGCONNECTION_H
#define PROTON_CPP_BLOCKINGCONNECTION_H

/*
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 *
 */
#include "proton/export.hpp"
#include "proton/handle.hpp"
#include "proton/endpoint.hpp"
#include "proton/container.hpp"
#include "proton/duration.hpp"
#include "proton/messaging_handler.hpp"
#include "proton/types.h"
#include <string>

struct pn_connection_t;

namespace proton {

class container;
class blocking_connection_impl;
class ssl_domain;
class blocking_sender;
class wait_condition;

class blocking_connection : public handle<blocking_connection_impl>
{
  public:
    PN_CPP_EXTERN blocking_connection();
    PN_CPP_EXTERN blocking_connection(const blocking_connection& c);
    PN_CPP_EXTERN blocking_connection& operator=(const blocking_connection& c);
    PN_CPP_EXTERN ~blocking_connection();

    PN_CPP_EXTERN blocking_connection(std::string &url, duration = duration::FOREVER,
                                         ssl_domain *ssld=0, container *c=0);
    PN_CPP_EXTERN void close();

    PN_CPP_EXTERN blocking_sender create_sender(std::string &address, handler *h=0);
    PN_CPP_EXTERN void wait(wait_condition &condition);
    PN_CPP_EXTERN void wait(wait_condition &condition, std::string &msg, duration timeout=duration::FOREVER);
    PN_CPP_EXTERN duration timeout();
  private:
    friend class private_impl_ref<blocking_connection>;
};

}

#endif  /*!PROTON_CPP_BLOCKINGCONNECTION_H*/