/**
 * @file DEFAULT_HANDLER.h
 * @author Ahmed Osama, Mohamed Ashraf
 * @date 24 Nov 2022
 * @brief This file will contain the standard bit math
 * @copyright Copyrights (c) 2022 Osama, Wx
 *
 */
/** @defgroup Header Guards */
#ifndef __DEFAULT_HANDLER_H__
#define __DEFAULT_HANDLER_H__

/*
----------------------------------------------------------------------
- Config Parameters
----------------------------------------------------------------------
*/

/* todo: Implement the debugging */

/*
----------------------------------------------------------------------
- Function like macros
----------------------------------------------------------------------
*/

/**
 * @brief Default error handler function.
 *
 */
#define DEFAULT_ERROR_HANDLER() do{\
                                    ;\
                                  }while(1)

/**
 * @brief Default unimplemented handler
 *
 */
#define DEFAULT_UNIMPLEMENTED_HANDLER() do{\
                                            ;\
                                          }while(1)

#endif /* __DEFAULT_HANDLER_H__ */
