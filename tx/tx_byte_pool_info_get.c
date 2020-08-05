/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/


/**************************************************************************/
/**************************************************************************/
/**                                                                       */
/** ThreadX Component                                                     */
/**                                                                       */
/**   Byte Memory                                                         */
/**                                                                       */
/**************************************************************************/
/**************************************************************************/

#define TX_SOURCE_CODE


/* Include necessary system files.  */

#include "tx_api.h"
#include "tx_trace.h"
#include "tx_byte_pool.h"


/**************************************************************************/
/*                                                                        */
/*  FUNCTION                                               RELEASE        */
/*                                                                        */
/*    _tx_byte_pool_info_get                              PORTABLE C      */
/*                                                           6.0          */
/*  AUTHOR                                                                */
/*                                                                        */
/*    William E. Lamie, Microsoft Corporation                             */
/*                                                                        */
/*  DESCRIPTION                                                           */
/*                                                                        */
/*    This function retrieves information from the specified byte pool.   */
/*                                                                        */
/*  INPUT                                                                 */
/*                                                                        */
/*    pool_ptr                          Pointer to byte pool control block*/
/*    name                              Destination for the pool name     */
/*    available_bytes                   Number of free bytes in byte pool */
/*    fragments                         Number of fragments in byte pool  */
/*    first_suspended                   Destination for pointer of first  */
/*                                        thread suspended on byte pool   */
/*    suspended_count                   Destination for suspended count   */
/*    next_pool                         Destination for pointer to next   */
/*                                        byte pool on the created list   */
/*                                                                        */
/*  OUTPUT                                                                */
/*                                                                        */
/*    status                            Completion status                 */
/*                                                                        */
/*  CALLS                                                                 */
/*                                                                        */
/*    None                                                                */
/*                                                                        */
/*  CALLED BY                                                             */
/*                                                                        */
/*    Application Code                                                    */
/*                                                                        */
/*  RELEASE HISTORY                                                       */
/*                                                                        */
/*    DATE              NAME                      DESCRIPTION             */
/*                                                                        */
/*  05-19-2020     William E. Lamie         Initial Version 6.0           */
/*                                                                        */
/**************************************************************************/
UINT  _tx_byte_pool_info_get(TX_BYTE_POOL *pool_ptr, CHAR **name, ULONG *available_bytes, 
                    ULONG *fragments, TX_THREAD **first_suspended, 
                    ULONG *suspended_count, TX_BYTE_POOL **next_pool)
{

TX_INTERRUPT_SAVE_AREA


    /* Disable interrupts.  */
    TX_DISABLE

    /* If trace is enabled, insert this event into the trace buffer.  */
    TX_TRACE_IN_LINE_INSERT(TX_TRACE_BYTE_POOL_INFO_GET, pool_ptr, 0, 0, 0, TX_TRACE_BYTE_POOL_EVENTS)

    /* Log this kernel call.  */
    TX_EL_BYTE_POOL_INFO_GET_INSERT

    /* Retrieve all the pertinent information and return it in the supplied
       destinations.  */

    /* Retrieve the name of the byte pool.  */
    if (name != TX_NULL)
    {
    
        *name =  pool_ptr -> tx_byte_pool_name;
    }

    /* Retrieve the number of available bytes in the byte pool.  */
    if (available_bytes != TX_NULL)
    {
    
        *available_bytes =  pool_ptr -> tx_byte_pool_available;
    }

    /* Retrieve the total number of bytes in the byte pool.  */
    if (fragments != TX_NULL)
    {
    
        *fragments =  (ULONG) pool_ptr -> tx_byte_pool_fragments;
    }

    /* Retrieve the first thread suspended on this byte pool.  */
    if (first_suspended != TX_NULL)
    {
    
        *first_suspended =  pool_ptr -> tx_byte_pool_suspension_list;
    }

    /* Retrieve the number of threads suspended on this byte pool.  */
    if (suspended_count != TX_NULL)
    {
    
        *suspended_count =  (ULONG) pool_ptr -> tx_byte_pool_suspended_count;
    }

    /* Retrieve the pointer to the next byte pool created.  */
    if (next_pool != TX_NULL)
    {
    
        *next_pool =  pool_ptr -> tx_byte_pool_created_next;
    }

    /* Restore interrupts.  */
    TX_RESTORE

    /* Return completion status.  */
    return(TX_SUCCESS);
}

