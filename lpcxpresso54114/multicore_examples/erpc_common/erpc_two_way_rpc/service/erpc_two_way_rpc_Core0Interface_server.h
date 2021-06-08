/*
 * Copyright 2018 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.8.0 on Thu Oct  8 16:38:34 2020.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#if !defined(_erpc_two_way_rpc_Core0Interface_server_h_)
#define _erpc_two_way_rpc_Core0Interface_server_h_

#ifdef __cplusplus
#include "erpc_server.h"
#include "erpc_codec.h"
extern "C"
{
#include "erpc_two_way_rpc_Core0Interface.h"
#include <stdint.h>
#include <stdbool.h>
}

#if 10800 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif


/*!
 * @brief Service subclass for Core0Interface.
 */
class Core0Interface_service : public erpc::Service
{
public:
    Core0Interface_service() : Service(kCore0Interface_service_id) {}

    /*! @brief Call the correct server shim based on method unique ID. */
    virtual erpc_status_t handleInvocation(uint32_t methodId, uint32_t sequence, erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory);

private:
    /*! @brief Server shim for setGetNumberFunction of Core0Interface interface. */
    erpc_status_t setGetNumberFunction_shim(erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory, uint32_t sequence);

    /*! @brief Server shim for getGetNumberFunction of Core0Interface interface. */
    erpc_status_t getGetNumberFunction_shim(erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory, uint32_t sequence);

    /*! @brief Server shim for nestedCallGetNumber of Core0Interface interface. */
    erpc_status_t nestedCallGetNumber_shim(erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory, uint32_t sequence);

    /*! @brief Server shim for getNumberFromCore1 of Core0Interface interface. */
    erpc_status_t getNumberFromCore1_shim(erpc::Codec * codec, erpc::MessageBufferFactory *messageFactory, uint32_t sequence);
};

extern "C" {
#else
#include "erpc_two_way_rpc_Core0Interface.h"
#endif // __cplusplus

typedef void * erpc_service_t;

erpc_service_t create_Core0Interface_service(void);

void destroy_Core0Interface_service(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _erpc_two_way_rpc_Core0Interface_server_h_
