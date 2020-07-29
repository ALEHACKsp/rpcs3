﻿#pragma once

#include "Emu/Memory/vm_ptr.h"

// Return Codes
enum CellRudpError : u32
{
	CELL_RUDP_SUCCESS                            = 0,
	CELL_RUDP_ERROR_NOT_INITIALIZED              = 0x80770001,
	CELL_RUDP_ERROR_ALREADY_INITIALIZED          = 0x80770002,
	CELL_RUDP_ERROR_INVALID_CONTEXT_ID           = 0x80770003,
	CELL_RUDP_ERROR_INVALID_ARGUMENT             = 0x80770004,
	CELL_RUDP_ERROR_INVALID_OPTION               = 0x80770005,
	CELL_RUDP_ERROR_INVALID_MUXMODE              = 0x80770006,
	CELL_RUDP_ERROR_MEMORY                       = 0x80770007,
	CELL_RUDP_ERROR_INTERNAL                     = 0x80770008,
	CELL_RUDP_ERROR_CONN_RESET                   = 0x80770009,
	CELL_RUDP_ERROR_CONN_REFUSED                 = 0x8077000a,
	CELL_RUDP_ERROR_CONN_TIMEOUT                 = 0x8077000b,
	CELL_RUDP_ERROR_CONN_VERSION_MISMATCH        = 0x8077000c,
	CELL_RUDP_ERROR_CONN_TRANSPORT_TYPE_MISMATCH = 0x8077000d,
	CELL_RUDP_ERROR_QUALITY_LEVEL_MISMATCH       = 0x8077000e,
	CELL_RUDP_ERROR_THREAD                       = 0x8077000f,
	CELL_RUDP_ERROR_THREAD_IN_USE                = 0x80770010,
	CELL_RUDP_ERROR_NOT_ACCEPTABLE               = 0x80770011,
	CELL_RUDP_ERROR_MSG_TOO_LARGE                = 0x80770012,
	CELL_RUDP_ERROR_NOT_BOUND                    = 0x80770013,
	CELL_RUDP_ERROR_CANCELLED                    = 0x80770014,
	CELL_RUDP_ERROR_INVALID_VPORT                = 0x80770015,
	CELL_RUDP_ERROR_WOULDBLOCK                   = 0x80770016,
	CELL_RUDP_ERROR_VPORT_IN_USE                 = 0x80770017,
	CELL_RUDP_ERROR_VPORT_EXHAUSTED              = 0x80770018,
	CELL_RUDP_ERROR_INVALID_SOCKET               = 0x80770019,
	CELL_RUDP_ERROR_BUFFER_TOO_SMALL             = 0x8077001a,
	CELL_RUDP_ERROR_MSG_MALFORMED                = 0x8077001b,
	CELL_RUDP_ERROR_ADDR_IN_USE                  = 0x8077001c,
	CELL_RUDP_ERROR_ALREADY_BOUND                = 0x8077001d,
	CELL_RUDP_ERROR_ALREADY_EXISTS               = 0x8077001e,
	CELL_RUDP_ERROR_INVALID_POLL_ID              = 0x8077001f,
	CELL_RUDP_ERROR_TOO_MANY_CONTEXTS            = 0x80770020,
	CELL_RUDP_ERROR_IN_PROGRESS                  = 0x80770021,
	CELL_RUDP_ERROR_NO_EVENT_HANDLER             = 0x80770022,
	CELL_RUDP_ERROR_PAYLOAD_TOO_LARGE            = 0x80770023,
	CELL_RUDP_ERROR_END_OF_DATA                  = 0x80770024,
	CELL_RUDP_ERROR_ALREADY_ESTABLISHED          = 0x80770025,
	CELL_RUDP_ERROR_KEEP_ALIVE_FAILURE           = 0x80770026,
};

// Context options
enum
{
	CELL_RUDP_OPTION_MAX_PAYLOAD         = 1,
	CELL_RUDP_OPTION_SNDBUF              = 2,
	CELL_RUDP_OPTION_RCVBUF              = 3,
	CELL_RUDP_OPTION_NODELAY             = 4,
	CELL_RUDP_OPTION_DELIVERY_CRITICAL   = 5,
	CELL_RUDP_OPTION_ORDER_CRITICAL      = 6,
	CELL_RUDP_OPTION_NONBLOCK            = 7,
	CELL_RUDP_OPTION_STREAM              = 8,
	CELL_RUDP_OPTION_CONNECTION_TIMEOUT  = 9,
	CELL_RUDP_OPTION_CLOSE_WAIT_TIMEOUT  = 10,
	CELL_RUDP_OPTION_AGGREGATION_TIMEOUT = 11,
	CELL_RUDP_OPTION_LAST_ERROR          = 14,
	CELL_RUDP_OPTION_READ_TIMEOUT        = 15,
	CELL_RUDP_OPTION_WRITE_TIMEOUT       = 16,
	CELL_RUDP_OPTION_FLUSH_TIMEOUT       = 17,
	CELL_RUDP_OPTION_KEEP_ALIVE_INTERVAL = 18,
	CELL_RUDP_OPTION_KEEP_ALIVE_TIMEOUT  = 19,
};

// Polling event flags
enum
{
	CELL_RUDP_POLL_EV_READ  = 0x0001,
	CELL_RUDP_POLL_EV_WRITE = 0x0002,
	CELL_RUDP_POLL_EV_FLUSH = 0x0004,
	CELL_RUDP_POLL_EV_ERROR = 0x0008,
};

struct sys_net_sockaddr;

using CellRudpEventHandler = s32(s32 event_id, s32 soc, vm::cptr<u8> data, u32 datalen, vm::cptr<sys_net_sockaddr> addr, u32 addrlen, vm::ptr<void> arg);

using CellRudpAllocatorFuncAlloc = vm::ptr<void>(u32 size);
using CellRudpAllocatorFuncFree = void(vm::ptr<void> ptr);

struct CellRudpAllocator
{
	vm::bptr<CellRudpAllocatorFuncAlloc> app_malloc;
	vm::bptr<CellRudpAllocatorFuncFree> app_free;
};
