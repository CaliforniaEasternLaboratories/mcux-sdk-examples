/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.8.0 on Thu Oct  8 16:38:34 2020.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "erpc_matrix_multiply_server.h"
#include <new>
#include "erpc_port.h"
#include "erpc_manually_constructed.h"

#if 10800 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

#if ERPC_NESTED_CALLS_DETECTION
extern bool nestingDetection;
#endif

static ManuallyConstructed<MatrixMultiplyService_service> s_MatrixMultiplyService_service;



// Constant variable definitions
#pragma weak matrix_size
extern const int32_t matrix_size = 5;


// Call the correct server shim based on method unique ID.
erpc_status_t MatrixMultiplyService_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory)
{
    switch (methodId)
    {
        case kMatrixMultiplyService_erpcMatrixMultiply_id:
            return erpcMatrixMultiply_shim(codec, messageFactory, sequence);

        default:
            return kErpcStatus_InvalidArgument;
    }
}

// Server shim for erpcMatrixMultiply of MatrixMultiplyService interface.
erpc_status_t MatrixMultiplyService_service::erpcMatrixMultiply_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    Matrix matrix1;
    Matrix matrix2;
    Matrix result_matrix;

    // startReadMessage() was already called before this shim was invoked.

    for (uint32_t arrayCount0 = 0; arrayCount0 < 5; ++arrayCount0)
    {
        for (uint32_t arrayCount1 = 0; arrayCount1 < 5; ++arrayCount1)
        {
            codec->read(&matrix1[arrayCount0][arrayCount1]);
        }
    }

    for (uint32_t arrayCount0 = 0; arrayCount0 < 5; ++arrayCount0)
    {
        for (uint32_t arrayCount1 = 0; arrayCount1 < 5; ++arrayCount1)
        {
            codec->read(&matrix2[arrayCount0][arrayCount1]);
        }
    }

    err = codec->getStatus();
    if (!err)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        erpcMatrixMultiply(matrix1, matrix2, result_matrix);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (!err)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kMatrixMultiplyService_service_id, kMatrixMultiplyService_erpcMatrixMultiply_id, sequence);

        for (uint32_t arrayCount0 = 0; arrayCount0 < 5; ++arrayCount0)
        {
            for (uint32_t arrayCount1 = 0; arrayCount1 < 5; ++arrayCount1)
            {
                codec->write(result_matrix[arrayCount0][arrayCount1]);
            }
        }

        err = codec->getStatus();
    }

    return err;
}

erpc_service_t create_MatrixMultiplyService_service()
{
    s_MatrixMultiplyService_service.construct();
    return s_MatrixMultiplyService_service.get();
}

void destroy_MatrixMultiplyService_service()
{
    s_MatrixMultiplyService_service.destroy();
}
