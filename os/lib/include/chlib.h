/*
    ChibiOS - Copyright (C) 2006..2018 Giovanni Di Sirio.

    This file is part of ChibiOS.

    ChibiOS is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * @file    chlib.h
 * @brief   ChibiOS/LIB main include file.
 * @details This header includes all the required library headers. This file
 *          is meant do be included by @p ch.h not directly by user.
 *
 * @addtogroup library_info
 * @details OS Library related info.
 * @{
 */

#ifndef CHLIB_H
#define CHLIB_H

/* Tmeporary hack.*/
#if !defined(_CHIBIOS_RT_CONF_VER_5_0_) && !defined(_CHIBIOS_NIL_CONF_VER_3_0_)
#include "chlibconf.h"
#else
#define _CHIBIOS_LIB_CONF_
#define _CHIBIOS_LIB_CONF_VER_1_0_
#endif

/*===========================================================================*/
/* Module constants.                                                         */
/*===========================================================================*/

/**
 * @brief   ChibiOS/LIB identification macro.
 */
#define _CHIBIOS_LIB_

/**
 * @brief   Stable release flag.
 */
#define CH_OSLIB_STABLE         0

/**
 * @name    ChibiOS/LIB version identification
 * @{
 */
/**
 * @brief   OS Library version string.
 */
#define CH_OSLIB_VERSION        "1.0.0"

/**
 * @brief   Kernel version major number.
 */
#define CH_OSLIB_MAJOR          1

/**
 * @brief   Kernel version minor number.
 */
#define CH_OSLIB_MINOR          0

/**
 * @brief   Kernel version patch number.
 */
#define CH_OSLIB_PATCH          0
/** @} */

/*===========================================================================*/
/* Module pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/* Host OS checks.*/
#if !defined(_CHIBIOS_RT_) && !defined(_CHIBIOS_NIL_)
#error "OS check failed, must be included after ch.h"
#endif

/* License checks.*/
#if !defined(CH_CUSTOMER_LIC_LIB) || !defined(CH_LICENSE_FEATURES)
#error "malformed chlicense.h"
#endif

#if (CH_LICENSE_FEATURES != CH_FEATURES_FULL) &&                            \
    (CH_LICENSE_FEATURES != CH_FEATURES_INTERMEDIATE) &&                    \
    (CH_LICENSE_FEATURES != CH_FEATURES_BASIC)
#error "invalid CH_LICENSE_FEATURES setting"
#endif

/* Restrictions in basic and intermediate modes.*/
#if (CH_CUSTOMER_LIC_LIB == FALSE) ||                                       \
    (CH_LICENSE_FEATURES == CH_FEATURES_INTERMEDIATE) ||                    \
    (CH_LICENSE_FEATURES == CH_FEATURES_BASIC)

/* Restricted subsystems.*/
#undef CH_CFG_USE_FACTORY

#define CH_CFG_USE_FACTORY                  FALSE

#endif /* (CH_CUSTOMER_LIC_LIB == FALSE) ||                                 \
          (CH_LICENSE_FEATURES == CH_FEATURES_INTERMEDIATE) ||
          (CH_LICENSE_FEATURES == CH_FEATURES_BASIC) */

/* Restrictions in basic mode.*/
#if (CH_CUSTOMER_LIC_LIB == FALSE) ||                                       \
    (CH_LICENSE_FEATURES == CH_FEATURES_BASIC)

/* Restricted subsystems.*/
#undef CH_CFG_USE_MEMCORE
#undef CH_CFG_USE_HEAP
#undef CH_CFG_USE_MEMPOOLS
#undef CH_CFG_USE_OBJ_FIFOS

#define CH_CFG_USE_MEMCORE                  FALSE
#define CH_CFG_USE_HEAP                     FALSE
#define CH_CFG_USE_MEMPOOLS                 FALSE
#define CH_CFG_USE_OBJ_FIFOS                FALSE

#endif /* (CH_CUSTOMER_LIC_LIB == FALSE) ||                                 \
          (CH_LICENSE_FEATURES == CH_FEATURES_BASIC) */

/* Configuration file checks.*/
#if !defined(_CHIBIOS_LIB_CONF_)
#error "invalid configuration file"
#endif

#if !defined(_CHIBIOS_LIB_CONF_VER_1_0_)
#error "obsolete or unknown configuration file"
#endif

#if !defined(CH_CFG_USE_SEMAPHORES)
#error "CH_CFG_USE_SEMAPHORES not defined in chconf.h"
#endif

#if !defined(CH_CFG_USE_MAILBOXES)
#error "CH_CFG_USE_MAILBOXES not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_USE_MEMCORE)
#error "CH_CFG_USE_MEMCORE not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_USE_HEAP)
#error "CH_CFG_USE_HEAP not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_USE_MEMPOOLS)
#error "CH_CFG_USE_MEMPOOLS not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_USE_OBJ_FIFOS)
#error "CH_CFG_USE_OBJ_FIFOS not defined in chlibconf.h"
#endif

/* Objects factory options checks.*/
#if !defined(CH_CFG_USE_FACTORY)
#error "CH_CFG_USE_FACTORY not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_FACTORY_MAX_NAMES_LENGTH)
#error "CH_CFG_FACTORY_MAX_NAMES_LENGTH not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_FACTORY_OBJECTS_REGISTRY)
#error "CH_CFG_FACTORY_OBJECTS_REGISTRY not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_FACTORY_GENERIC_BUFFERS)
#error "CH_CFG_FACTORY_GENERIC_BUFFERS not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_FACTORY_SEMAPHORES)
#error "CH_CFG_FACTORY_SEMAPHORES not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_FACTORY_MAILBOXES)
#error "CH_CFG_FACTORY_MAILBOXES not defined in chlibconf.h"
#endif

#if !defined(CH_CFG_FACTORY_OBJ_FIFOS)
#error "CH_CFG_FACTORY_OBJ_FIFOS not defined in chlibconf.h"
#endif

/*===========================================================================*/
/* Module data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Module macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/*===========================================================================*/
/* Late inclusions.                                                          */
/*===========================================================================*/

/* OS Library headers.*/
#include "chbsem.h"
#include "chmboxes.h"
#include "chmemcore.h"
#include "chheap.h"
#include "chmempools.h"
#include "chfifo.h"
#include "chfactory.h"

#endif /* CHLIB_H */

/** @} */
