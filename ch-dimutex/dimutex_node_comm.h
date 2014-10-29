/*******************************************************************************
 * Copyright (c) 2012, Sandeep Prakash <123sandy@gmail.com>
 * All rights reserved.
 *
 * \file   dimutex_node_comm.h
 * \author sandeepprakash
 *
 * \date   28-Sep-2012
 *
 * \brief  
 *
 ******************************************************************************/

#ifndef __DIMUTEX_NODE_COMM_H__
#define __DIMUTEX_NODE_COMM_H__

#ifdef  __cplusplus
extern  "C"
{
#endif

/********************************* CONSTANTS **********************************/

/*********************************** MACROS ***********************************/
#define NODE_MSG_MAX_SUPP_PEERS                       (10)

#define NODE_MSG_MAX_HOSTNAME_STR_LEN                 (512)

/******************************** ENUMERATIONS ********************************/
typedef enum _NODE_MSG_ID_E
{
   eNODE_MSG_ID_INVALID                       = 0x00000000,

   /*
    * Reserved Messages.
    */
   eNODE_MSG_ID_RESERVED_START                = 0x00000001,

   eNODE_MSG_ID_RESERVED_END                  = 0x00001000,

   /*
    * Setup messages.
    */
   eNODE_MSG_ID_SETUP_RANGE_START             = 0x00001001,

   eNODE_MSG_ID_SETUP_JOIN                    = 0x00001002,
   /*!< #_NODE_MSG_JOIN_X. */

   eNODE_MSG_ID_SETUP_JOIN_DONE               = 0x00001003,
   /*!< #_NODE_MSG_JOIN_DONE_X. */

   eNODE_MSG_ID_SETUP_ESTABLISH_PEERS         = 0x00001004,
   /*!< #_NODE_MSG_ESTABLISH_PEERS_X. */

   eNODE_MSG_ID_SETUP_ESTABLISH_DONE          = 0x00001005,
   /*!< #_NODE_MSG_ESTABLISH_DONE_X. */

   eNODE_MSG_ID_SETUP_PING                    = 0x00001006,
   /*!< #_NODE_MSG_PING_X. */

   eNODE_MSG_ID_SETUP_RANGE_END               = 0x00002000,

   /*
    * Algorithm messages
    */
   eNODE_MSG_ID_ALGO_RANGE_START              = 0x00002001,

   eNODE_MSG_ID_ALGO_SETUP                    = 0x00002002,
   /* #_NODE_MSG_ALGO_SETUP_X. */

   eNODE_MSG_ID_ALGO_SETUP_COMPLETE           = 0x00002003,
   /* #_NODE_MSG_ALGO_SETUP_COMPLETE_X. */

   eNODE_MSG_ID_ALGO_TEARDOWN                 = 0x00002004,
   /* #_NODE_MSG_ALGO_TEARDOWN_X. */

   eNODE_MSG_ID_ALGO_TEARDOWN_COMPLETE        = 0x00002005,
   /* #_NODE_MSG_ALGO_TEARDOWN_COMPLETE_X. */

   eNODE_MSG_ID_ALGO_START                    = 0x00002006,
   /* #_NODE_MSG_ALGO_START_X. */

   eNODE_MSG_ID_ALGO_STOP                     = 0x00002007,
   /* #_NODE_MSG_ALGO_STOP_X. */

   eNODE_MSG_ID_ALGO_COMPLETE                 = 0x00002008,
   /* #_NODE_MSG_ALGO_COMPLETE_X. */

   eNODE_MSG_ID_ALGO_REQUEST                  = 0x00002009,
   /*!< #_NODE_MSG_ALGO_REQUEST_X. */

   eNODE_MSG_ID_ALGO_REPLY                    = 0x00002010,
   /*!< #_NODE_ALGO_MSG_REPLY_X. */

   eNODE_MSG_ID_ALGO_RANGE_END                = 0x00003000,

   /*
    * Other messages. For future use.
    */
   eNODE_MSG_ID_MAX
} NODE_MSG_ID_E;

/*********************** CLASS/STRUCTURE/UNION DATA TYPES *********************/
typedef struct _NODE_MSG_HDR_X
{
   uint32_t ui_msg_id;

   uint32_t ui_msg_pay_len;

   uint8_t puc_padding[56];
} NODE_MSG_HDR_X;

typedef struct _NODE_MSG_JOIN_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;

   DIMUTEX_NODE_CTXT_X x_node_ctxt;
} NODE_MSG_JOIN_X;

typedef struct _NODE_MSG_JOIN_DONE_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_JOIN_DONE_X;

typedef struct _NODE_MSG_PEER_DATA_X
{
   uint32_t ui_ip_addr_ho;

   uint16_t us_port_no_ho;

   uint8_t  uca_padding[2];

   uint8_t  uca_host_name_str[NODE_MSG_MAX_HOSTNAME_STR_LEN];

   uint8_t  uca_reserved[64];
} NODE_MSG_PEER_DATA_X;

typedef struct _NODE_MSG_PEERS_X
{
   uint32_t             ui_count;

   //NODE_MSG_PEER_DATA_X xa_peer[NODE_MSG_MAX_SUPP_PEERS];
} NODE_MSG_PEERS_X;

typedef struct _NODE_MSG_ESTABLISH_PEERS_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;

   NODE_MSG_PEERS_X x_peers;
} NODE_MSG_ESTABLISH_PEERS_X;

typedef struct _NODE_MSG_ESTABLISH_DONE_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ESTABLISH_DONE_X;

typedef struct _NODE_MSG_PING_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;

   uint32_t ui_ping_local_ts_ms;
} NODE_MSG_PING_X;

typedef struct _NODE_MSG_ALGO_SETUP_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ALGO_SETUP_X;

typedef struct _NODE_MSG_ALGO_SETUP_COMPLETE_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ALGO_SETUP_COMPLETE_X;

typedef struct _NODE_MSG_ALGO_TEARDOWN_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ALGO_TEARDOWN_X;

typedef struct _NODE_MSG_ALGO_TEARDOWN_COMPLETE_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ALGO_TEARDOWN_COMPLETE_X;

typedef struct _NODE_MSG_ALGO_START_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ALGO_START_X;

typedef struct _NODE_MSG_ALGO_STOP_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_MSG_ALGO_STOP_X;

typedef struct _NODE_MSG_ALGO_COMPLETE_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;

   DIMUTEX_ALGO_STATS_X x_stats;
} NODE_MSG_ALGO_COMPLETE_X;

typedef struct _NODE_MSG_ALGO_REQUEST_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;

   uint32_t ui_seq_number;
} NODE_MSG_ALGO_REQUEST_X;

typedef struct _NODE_ALGO_MSG_REPLY_X
{
   NODE_MSG_HDR_X x_hdr;

   uint32_t ui_bitmask;
} NODE_ALGO_MSG_REPLY_X;

/***************************** FUNCTION PROTOTYPES ****************************/

#ifdef   __cplusplus
}
#endif

#endif /* __DIMUTEX_NODE_COMM_H__ */
