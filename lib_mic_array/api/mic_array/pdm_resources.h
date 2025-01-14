// Copyright 2021-2022 XMOS LIMITED.
// This Software is subject to the terms of the XMOS Public Licence: Version 1.
#pragma once

#include "api.h"
#include "etc/xcore_compat.h"

#include "xs3_math.h"

#include <stdint.h>

/**
 * @defgroup pdm_resources_h_ pdm_resources.h whyy
 */


C_API_START


/**
 * @brief Collection of resources IDs required for PDM capture.
 * 
 * This struct is a container for the IDs of the xCore hardware resources used 
 * by the mic array unit's PdmRx component for capturing PDM data from a port.
 * 
 * An object of this type will be used for initializing and starting the mic 
 * array unit.
 * 
 * @ingroup pdm_resources_h_
 */
MA_C_API
typedef struct {

  /** 
   * @brief ID of the 1-bit port on which the master audio clock signal is 
   * received.
   * 
   * The master audio clock will be divided to produce the PDM sample clock.
   * 
   * This port will be configured as an input.
   */
  port_t p_mclk;

  /** 
   * @brief ID of the 1-bit port through which the PDM sample clock is signaled.
   * 
   * The PDM sample clock is used by the PDM microphones to trigger sample 
   * conversion.
   * 
   * This port will be configured as an output.
   */
  port_t p_pdm_clk;

  /** 
   * @brief ID of the port on which PDM samples are received.
   * 
   * In an SDR configuration, the number of microphone channels is the width of
   * this port. In a DDR configuration, the number of microphone channels is
   * twice the width of this port.
   * 
   * This port will be configured as an input.
   */
  port_t p_pdm_mics;

  /**
   * @brief ID of the clock block used to derive the PDM clock from the master 
   * audio clock.
   * 
   * In SDR configurations this is also the PDM data capture clock.
   */
  clock_t clock_a;

  /**
   * @brief ID of the clock block used only in DDR configurations to trigger 
   * reads of the 
   * PDM data.
   * 
   * If operating in an SDR configuration, `clock_b` must be `0`. A value of 
   * `0` is what indicates an SDR configuration is being used.
   */
  clock_t clock_b;
} pdm_rx_resources_t;


/**
 * @brief Construct a `pdm_rx_resources_t` for an SDR configuration.
 *
 * `pdm_rx_resources_t.clock_b` is initialized to `0`, indicating an SDR
 * configuration.
 * 
 * @param P_MCLK      Master audio clock port resource ID.
 * @param P_PDM_CLK   PDM sample clock port resource ID.
 * @param P_PDM_MICS  PDM microphone data port resource ID.
 * @param CLOCK_A     PDM clock and capture clock block resource ID.
 * 
 * @ingroup pdm_resources_h_
 */
#define PDM_RX_RESOURCES_SDR(P_MCLK, P_PDM_CLK, P_PDM_MICS, CLOCK_A)    \
    { (port_t) (P_MCLK), (port_t) (P_PDM_CLK), (port_t) (P_PDM_MICS),   \
      (clock_t) (CLOCK_A) }


/**
 * @brief Construct a `pdm_rx_resources_t` for a DDR configuration.
 * 
 * @param P_MCLK      Master audio clock port resource ID.
 * @param P_PDM_CLK   PDM sample clock port resource ID.
 * @param P_PDM_MICS  PDM microphone data port resource ID.
 * @param CLOCK_A     PDM clock clock block resource ID.
 * @param CLOCK_B     PDM capture clock block resource ID.
 * 
 * @ingroup pdm_resources_h_
 */
#define PDM_RX_RESOURCES_DDR(P_MCLK, P_PDM_CLK, P_PDM_MICS, CLOCK_A, CLOCK_B) \
    { (port_t) (P_MCLK), (port_t) (P_PDM_CLK), (port_t) (P_PDM_MICS),         \
      (clock_t) (CLOCK_A), (clock_t) (CLOCK_B) }



C_API_END
