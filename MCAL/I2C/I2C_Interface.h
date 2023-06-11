/*
 * I2C_Interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Muham
 */

#ifndef MCAL_I2C_I2C_INTERFACE_H_
#define MCAL_I2C_I2C_INTERFACE_H_

/*
 * I2C_interface.h
 *
 *  Created on: Dec 20, 2022
 *      Author: abdullah
 */


typedef enum{

	NOK,  //NOK = 0
	OK,    //OK = 1
	StartConditionErr,
	RepeatedStartConditionErr,
	SlaveAddWithWriteErr,
	SlaveAddWithReadErr,
	MAsterWriteByteErr,
	MAsterReadByteErr,
	SlaveAddCheckWriteErr,
	SlaveAddCheckReadErr,
	SlaveTrnsmitErr,
	SlaveDataRcvdErr

}I2C_ERROR_STATUS;


// pass 0 int the salve address argument if master will npt be addressed
void I2C_VidInitMaster(u8 Copu_u8SlaveAddress);

void I2C_VidInitSlave(u8 Copu_u8SlaveAddress);

I2C_ERROR_STATUS I2C_StartCondition(void);

I2C_ERROR_STATUS I2C_RepeatedStart(void);

I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Write(u8 Address);

I2C_ERROR_STATUS I2C_Master_Send_Slave_Address_With_Read(u8 Address);

I2C_ERROR_STATUS I2C_Maste_Write_DataByte_To_Slave(u8 Data);

I2C_ERROR_STATUS I2C_Master_Read_DataByte_From_Slave (u8 * ptr);

void I2C_StopCondition(void);

I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Write(void);

I2C_ERROR_STATUS I2C_Slave_Check_About_His_Addr_With_Read(void);

I2C_ERROR_STATUS I2C_Slave_Read_Byte_From_Master(u8 * ptr);

I2C_ERROR_STATUS I2C_Slave_Write_Byte_To_Master(u8 Data);



#endif /* MCAL_I2C_I2C_INTERFACE_H_ */



