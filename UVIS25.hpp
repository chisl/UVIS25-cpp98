/*
 * name:        UVIS25
 * description: Digital UV index sensor: 0 - 15 UV index output range.
 * manuf:       STMicroelectronics
 * version:     0.1
 * url:         http://www.st.com/resource/en/datasheet/uvis25.pdf
 * date:        2018-01-02
 * author       https://chisl.io/
 * file:        UVIS25.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class UVIS25_Base and implement the read and write functions! */

/* UVIS25: Digital UV index sensor: 0 - 15 UV index output range. */
class UVIS25_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint8_t read8(uint16_t address, uint16_t n=8) = 0;  // 8 bit read
	virtual void write(uint16_t address, uint8_t value, uint16_t n=8) = 0;  // 8 bit write
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                           REG WHO_AM_I                                            *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG WHO_AM_I:
	 * Device who am I
	 */
	struct WHO_AM_I
	{
		static const uint16_t __address = 15;
		
		/* Bits WHO_AM_I: */
		struct WHO_AM_I_
		{
			/* Mode:r */
			static const uint8_t dflt = 0b11001010; // 8'b11001010
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register WHO_AM_I */
	void setWHO_AM_I(uint8_t value)
	{
		write(WHO_AM_I::__address, value, 8);
	}
	
	/* Get register WHO_AM_I */
	uint8_t getWHO_AM_I()
	{
		return read8(WHO_AM_I::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG1                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG1:
	 * Control register 1
	 */
	struct CTRL_REG1
	{
		static const uint16_t __address = 32;
		
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ to ensure proper operation of the device  */
		struct reserved_0
		{
			static const uint8_t dflt = 0b000000; // 6'd0
			static const uint8_t mask = 0b11111100; // [2,3,4,5,6,7]
		};
		/* Bits BDU: */
		/* Block data update.  */
		struct BDU
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t CONTINUOUS_MODE = 0b0; // continuous update; 
			static const uint8_t NOT_UPDATED_UNTIL_READ = 0b1; // output registers not updated until MSB and LSB have been read)
		};
		/* Bits ODR: */
		/*
		 * Enable continuous reading at 1 Hz.
		 * ODR bit enables the continuous reading of the UV index at 1 Hz.. When ODR is set to ‘0’ the
		 * device enables the one-shot mode. When ‘ONESHOT’ bit in 9.3: CTRL_REG2 (21h) is set
		 * to ‘1’, a new UV index value is acquired.
		 * If ODR bit and 'ONESHOT’ bit in 9.3: CTRL_REG2 (21h) are set to '0', the device is in
		 * power down mode. If ODR bit is set to '1', ‘ONESHOT’ bit in 9.3: CTRL_REG2 (21h) must
		 * be '0'.
		 */
		struct ODR
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t ONE_SHOT_MODE = 0b0; // One-shot mode enabled
			static const uint8_t ODR_1_HZ = 0b1; // ODR at 1 Hz
		};
	};
	
	/* Set register CTRL_REG1 */
	void setCTRL_REG1(uint8_t value)
	{
		write(CTRL_REG1::__address, value, 8);
	}
	
	/* Get register CTRL_REG1 */
	uint8_t getCTRL_REG1()
	{
		return read8(CTRL_REG1::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG2                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG2:
	 * Control register 2
	 */
	struct CTRL_REG2
	{
		static const uint16_t __address = 33;
		
		/* Bits BOOT: */
		/*
		 * Reboot memory content.
		 * The bit is self-cleared when the BOOT is completed.
		 * BOOT bit is used to refresh the content of the internal registers stored in the Flash memory
		 * block. At the device power-up, the content of the Flash memory block is transferred to the
		 * internal registers related to trimming functions to permit a good behavior of the device itself.
		 * If for any reason, the content of the trimming registers is modified, it is sufficient to use this
		 * bit to restore the correct values. When BOOT bit is set to ‘1’ the content of the internal Flash
		 * is copied into the corresponding internal registers and is used to calibrate the device. These
		 * values are factory trimmed, and they are different for every device. They permit good
		 * behavior of the device and generally they should not be changed. At the end of the boot
		 * process, the BOOT bit is set again to ‘0’ by hardware. BOOT bit takes effect after one ODR
		 * clock cycle.
		 */
		struct BOOT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t NORMAL_MODE = 0b0; // normal mode
			static const uint8_t REBOOT_MEM = 0b1; // reboot memory content.
		};
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ to ensure proper operation of the device  */
		struct reserved_0
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b01100000; // [5,6]
		};
		/* Bits I2C_DS: */
		/* Disable I2C interface.  */
		struct I2C_DS
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00010000; // [4]
			static const uint8_t ENABLE = 0b0; // I2C enable
			static const uint8_t DISABLE = 0b1; // I2C disable
		};
		/* Bits SIM: */
		/* SPI Serial Interface Mode Selection.  */
		struct SIM
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t SPI_4_WIRE = 0b0; // 4-wire interface
			static const uint8_t SPI_3_WIRE = 0b1; // 3-wire interface
		};
		/* Bits reserved_1: */
		/* These bits must be set to ‘0’ to ensure proper operation of the device  */
		struct reserved_1
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000110; // [1,2]
		};
		/* Bits ONE_SHOT: */
		/* One shot enable.  */
		struct ONE_SHOT
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t WAITING_FOR_START = 0b0; // waiting for start of conversion
			static const uint8_t START = 0b1; // start for a new dataset
		};
	};
	
	/* Set register CTRL_REG2 */
	void setCTRL_REG2(uint8_t value)
	{
		write(CTRL_REG2::__address, value, 8);
	}
	
	/* Get register CTRL_REG2 */
	uint8_t getCTRL_REG2()
	{
		return read8(CTRL_REG2::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG CTRL_REG3                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG CTRL_REG3:
	 * Interrupt control
	 * The device features one fully-programmable interrupt source (INT) that can be configured to
	 * trigger different events.
	 * The device may also be configured to generate, a Data Ready signal (DRDY) which
	 * indicates when a new measured UV index is available, thus simplifying data synchronization
	 * in digital systems or to optimize the system power consumption.
	 */
	struct CTRL_REG3
	{
		static const uint16_t __address = 34;
		
		/* Bits INT_H_L: */
		/* Interrupt active high, low.  */
		struct INT_H_L
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b10000000; // [7]
			static const uint8_t ACTIVE_HIGH = 0b0; // active high
			static const uint8_t ACTIVE_LOW = 0b1; // active low
		};
		/* Bits PP_OD: */
		/* Push-pull/open drain selection on interrupt pads.  */
		struct PP_OD
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b01000000; // [6]
			static const uint8_t PUSH_PULL = 0b0; // push-pull
			static const uint8_t OPEN_DRAIN = 0b1; // open drain
		};
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ to ensure proper operation of the device  */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b00111100; // [2,3,4,5]
		};
		/* Bits INT_S: */
		/* Data signal on INT_DRDY pin control bits.  */
		struct INT_S
		{
			static const uint8_t dflt = 0b00; // 2'b0
			static const uint8_t mask = 0b00000011; // [0,1]
			static const uint8_t DATA_READY = 0b00; // Data ready
			static const uint8_t UV_INDEX_HIGH = 0b01; // UV index High
			static const uint8_t UV_INDEX_LOW = 0b10; // UV index Low
			static const uint8_t UV_INDEX_HIGH_OR_LOW = 0b11; // UV index High or Low
		};
	};
	
	/* Set register CTRL_REG3 */
	void setCTRL_REG3(uint8_t value)
	{
		write(CTRL_REG3::__address, value, 8);
	}
	
	/* Get register CTRL_REG3 */
	uint8_t getCTRL_REG3()
	{
		return read8(CTRL_REG3::__address, 8);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG INT_CFG                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG INT_CFG:
	 * Interrupt configuration
	 */
	struct INT_CFG
	{
		static const uint16_t __address = 35;
		
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ to ensure proper operation of the device  */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000; // 4'b0
			static const uint8_t mask = 0b11110000; // [4,5,6,7]
		};
		/* Bits DIFF_EN: */
		/* Interrupt generation enable.  */
		struct DIFF_EN
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00001000; // [3]
			static const uint8_t DISABLE = 0b0; // interrupt circuit disable
			static const uint8_t ENABLE = 0b1; // interrupt circuit enabled
		};
		/* Bits LIR: */
		/* Latch interrupt request to the INT_SOURCE (24h) register.  */
		struct LIR
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NOT_LATCHED = 0b0; // interrupt request not latched
			static const uint8_t LATCHED = 0b1; // interrupt request latched
		};
		/* Bits UVLE: */
		/* Enable interrupt generation on differential UV low event.  */
		struct UVLE
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured differential UV values lower than preset threshold
		};
		/* Bits UVHE: */
		/* Enable interrupt generation on differential UV high event.  */
		struct UVHE
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DISABLE = 0b0; // disable interrupt request
			static const uint8_t ENABLE = 0b1; // enable interrupt request on measured differential UV values higher than preset threshold
		};
	};
	
	/* Set register INT_CFG */
	void setINT_CFG(uint8_t value)
	{
		write(INT_CFG::__address, value, 8);
	}
	
	/* Get register INT_CFG */
	uint8_t getINT_CFG()
	{
		return read8(INT_CFG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG INT_SOURCE                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG INT_SOURCE:
	 * Interrupt source configuration
	 */
	struct INT_SOURCE
	{
		static const uint16_t __address = 36;
		
		/* Bits unused_0: */
		struct unused_0
		{
			static const uint8_t dflt = 0b000; // 3'b0
			static const uint8_t mask = 0b00111000; // [3,4,5]
		};
		/* Bits IA: */
		/* Interrupt active.  */
		struct IA
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000100; // [2]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt has been generated
			static const uint8_t EVENT = 0b1; // one or more interrupt events have been generated
		};
		/* Bits UVL: */
		/* Differential UV low.  */
		struct UVL
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000010; // [1]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt has been generated
			static const uint8_t EVENT = 0b1; // UV low event has occurred
		};
		/* Bits UVH: */
		/* Differential UV high.  */
		struct UVH
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t NO_INTERRUPT = 0b0; // no interrupt has been generated
			static const uint8_t EVENT = 0b1; // UV high event has occurred
		};
	};
	
	/* Set register INT_SOURCE */
	void setINT_SOURCE(uint8_t value)
	{
		write(INT_SOURCE::__address, value, 8);
	}
	
	/* Get register INT_SOURCE */
	uint8_t getINT_SOURCE()
	{
		return read8(INT_SOURCE::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                            REG THS_UV                                             *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG THS_UV:
	 * Threshold register
	 */
	struct THS_UV
	{
		static const uint16_t __address = 37;
		
		/* Bits THS_UV: */
		/*
		 * This register contains the differential UV Interrupt threshold value for the
		 * interrupt generation.
		 */
		struct THS_UV_
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register THS_UV */
	void setTHS_UV(uint8_t value)
	{
		write(THS_UV::__address, value, 8);
	}
	
	/* Get register THS_UV */
	uint8_t getTHS_UV()
	{
		return read8(THS_UV::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG reserved_0                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG reserved_0:
	 * do not use
	 */
	struct reserved_0
	{
		static const uint16_t __address = 38;
		
		/* Bits reserved_0: */
		struct reserved_0_
		{
			/* Mode: */
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register reserved_0 */
	void setreserved_0(uint8_t value)
	{
		write(reserved_0::__address, value, 8);
	}
	
	/* Get register reserved_0 */
	uint8_t getreserved_0()
	{
		return read8(reserved_0::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG STATUS_REG                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG STATUS_REG:
	 * Status register
	 */
	struct STATUS_REG
	{
		static const uint16_t __address = 39;
		
		/* Bits reserved_0: */
		/* These bits must be set to ‘0’ to ensure proper operation of the device  */
		struct reserved_0
		{
			static const uint8_t dflt = 0b0000000; // 7'd0
			static const uint8_t mask = 0b11111110; // [1,2,3,4,5,6,7]
		};
		/* Bits UV_DA: */
		/*
		 * UV data available.
		 * UV_DA is set to 1 whenever a new UVI sample is available. UV_DA is cleared
		 * when the UV_OUT_REG (28h) is read.
		 * 
		 */
		struct UV_DA
		{
			static const uint8_t dflt = 0b0; // 1'b0
			static const uint8_t mask = 0b00000001; // [0]
			static const uint8_t DATA_AVAILABLE = 0b0; // UVI data not available
			static const uint8_t DATA_NOT_AVAILABLE = 0b1; // UVI data available
		};
	};
	
	/* Set register STATUS_REG */
	void setSTATUS_REG(uint8_t value)
	{
		write(STATUS_REG::__address, value, 8);
	}
	
	/* Get register STATUS_REG */
	uint8_t getSTATUS_REG()
	{
		return read8(STATUS_REG::__address, 8);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG UV_OUT_REG                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG UV_OUT_REG:
	 * UV index output register
	 */
	struct UV_OUT_REG
	{
		static const uint16_t __address = 40;
		
		/* Bits OUT: */
		/* UVI data output value.  */
		struct OUT
		{
			static const uint8_t dflt = 0b00000000; // 8'b0
			static const uint8_t mask = 0b11111111; // [0,1,2,3,4,5,6,7]
		};
	};
	
	/* Set register UV_OUT_REG */
	void setUV_OUT_REG(uint8_t value)
	{
		write(UV_OUT_REG::__address, value, 8);
	}
	
	/* Get register UV_OUT_REG */
	uint8_t getUV_OUT_REG()
	{
		return read8(UV_OUT_REG::__address, 8);
	}
	
};
